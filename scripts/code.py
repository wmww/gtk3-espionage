'''
MIT License

Copyright 2020 William Wold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'''

import logging
from datetime import datetime
import os
from os import path
import re
import mmap

logger = logging.getLogger(__name__)

LGPL3_HEADER = '''
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
'''

CODE_EXTENSIONS = set(['h', 'hpp', 'c', 'cpp', 'cc'])

def get_all_source_files(search_dir):
    result = []
    for item in os.listdir(search_dir):
        p = path.join(search_dir, item)
        if path.isdir(p):
            result += get_all_source_files(p)
        elif p.rsplit('.', 1)[-1] in CODE_EXTENSIONS:
            result.append(p)
    return result

def struct_regex_string(struct_name):
    return r'struct\s+' + struct_name + r'\s*\{'

class StructVersion:
    def __init__(self, code_path, version, struct_name):
        with open(code_path, 'r') as f:
            source_code = f.read()
        self.version = version
        self.struct_name = struct_name
        self.copyright_lines = set(re.findall(r'[Cc]opyright .*(?=\n)', source_code))
        halves = re.split(struct_regex_string(struct_name), source_code)
        if len(halves) < 2:
            raise RuntimeError(struct_name + ' not declared in ' + code_path + ' (even though it was detected)')
        if len(halves) > 2:
            raise RuntimeError(struct_name + ' declared multiple times in ' + code_path)
        content = '{'
        count = 1
        for c in halves[1]:
            content += c
            if c == '{':
                count += 1
            elif c == '}':
                count -= 1
            if count <= 0:
                break
        self.content = content

    def emit_definition(self):
        return 'struct ' + str(self) + '\n' + self.content + '\n'

    def __str__(self):
        return self.struct_name + '_' + self.version.c_id()

    def __eq__(self, other):
        assert isinstance(other, StructVersion)
        return self.content == other.content

class Header:
    def __init__(self, path, code):
        self.path = path
        self.code = code

class Struct:
    def __init__(self, typedef):
        self.typedef = typedef
        self.struct_name = '_' + typedef
        self.versions = []
        self.copyright_lines = set()
        self.search_regex = re.compile(bytes(struct_regex_string(self.struct_name), 'utf-8'))

    def header_name(self):
        result = ''
        for l in self.typedef:
            if l.isupper() and result:
                result += '_'
            result += l.lower()
        result += '_espionage.h'
        return result

    def add_version(self, new):
        if self.versions and self.versions[-1] == new:
            logger.info(self.typedef + ' ' + str(new.version) + ' is identical to ' + str(self.versions[-1].version) + ', so not adding')
        else:
            logger.info('Adding ' + self.typedef + ' ' + str(new.version))
            self.versions.append(new)
        self.copyright_lines = self.copyright_lines.union(new.copyright_lines)

    def emit_header(self):
        result = ''
        result += '/* This file is part of gtk3-espionage\n'
        result += ' *\n'
        me = path.relpath(__file__, path.dirname(path.dirname(path.dirname(__file__))))
        my_copyright_line = 'Copyright © ' + str(datetime.now().year) + ' ' + me
        for line in list(self.copyright_lines) + [my_copyright_line]:
            result += ' * ' + line + '\n'
        result += ' * ' + '\n * '.join(LGPL3_HEADER.splitlines())
        result += '\n */\n'
        result += '\n'
        result += 'typedef struct ' + self.struct_name + ' ' + self.typedef + '\n'
        result += '\n'
        for i in self.versions:
            result += i.emit_definition()
            result += '\n'
        return result

class Code:
    def __init__(self, repo_dir, struct_names):
        self.repo_dir = repo_dir
        self.structs = [Struct(name) for name in struct_names]

    def update(self, version):
        hits = {}
        source_files = get_all_source_files(self.repo_dir)
        for i in source_files:
            with open(i) as f:
                try:
                    with mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ) as s:
                        for struct in self.structs:
                            if struct.search_regex.search(s):
                                if struct.typedef not in hits:
                                    hits[struct.typedef] = []
                                hits[struct.typedef].append(i)
                                logger.info('Found ' + struct.typedef + ' in ' + i)
                except ValueError:
                    pass
        for struct in self.structs:
            if not hits.get(struct.typedef):
                raise RuntimeError('Could not find ' + struct.typedef + ' in ' + str(version))
            if len(hits.get(struct.typedef)) > 1:
                raise RuntimeError(struct.typedef + ' implemented multiple places: ' + str(hits.get(struct.typedef)))
            struct_version = StructVersion(hits[struct.typedef][0], version, struct.struct_name)
            struct.add_version(struct_version)

    def emit(self):
        return [Header(struct.header_name(), struct.emit_header()) for struct in self.structs]
