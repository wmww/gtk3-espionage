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

import parse

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

def remove_headers_from_dir(header_dir):
    logger.info('Clearing header files out of ' + header_dir)
    for item in os.listdir(header_dir):
        p = path.join(header_dir, item)
        if p.rsplit('.', 1)[-1] == 'h':
            os.remove(p)

def struct_regex_string(struct_name):
    return r'struct\s+' + struct_name + r'\s*\{'

def extract_body(file_content, struct_name):
    halves = re.split(struct_regex_string(struct_name), file_content)
    if len(halves) < 2:
        raise RuntimeError(struct_name + ' not declared in ' + code_path + ' (even though it was detected)')
    if len(halves) > 2:
        raise RuntimeError(struct_name + ' declared multiple times in ' + code_path)
    body = ''
    brace_level = 1
    for c in halves[1]:
        if c == '{':
            brace_level += 1
        elif c == '}':
            brace_level -= 1
        if brace_level <= 0:
            break
        body += c
    return body

class StructVersion:
    def __init__(self, code_path, version, struct_name):
        with open(code_path, 'r') as f:
            source_code = f.read()
        self.code_path = code_path
        self.version = version
        self.struct_name = struct_name
        self.copyright_lines = set(re.findall(r'[Cc]opyright .*(?=\n)', source_code))
        self.body = extract_body(source_code, struct_name)
        self.ast = parse.parse_ast(self.body)

    def get_code_path(self):
        return self.code_path

    def emit_definition(self):
        return 'struct ' + str(self) + '\n{' + self.body + '}\n'

    def generate_definition(self):
        return (
            'struct ' + str(self) +
            '\n{\n' +
            parse.INDENT + ('\n' + parse.INDENT).join(str(self.ast).splitlines()) +
            '\n}\n')

    def __str__(self):
        return self.struct_name + '_' + self.version.c_id()

    def __eq__(self, other):
        assert isinstance(other, StructVersion)
        return self.ast == other.ast

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

    def get_code_path(self):
        if self.versions:
            return self.versions[-1].get_code_path()
        else:
            return None

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
            # logger.info(self.typedef + ' ' + str(new.version) + ' is identical to ' + str(self.versions[-1].version) + ', so not adding')
            pass
        else:
            logger.info(self.typedef + ' changed at ' + str(new.version))
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
        result += '\n * '.join(LGPL3_HEADER.splitlines())
        result += '\n */\n'
        result += '\n'
        result += 'typedef struct ' + self.struct_name + ' ' + self.typedef + '\n'
        result += '\n'
        for i in self.versions:
            result += i.generate_definition()
            result += '\n'
        return result

def file_contains_byte_regex(source_file, regex):
    try:
        with open(source_file) as f:
            with mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ) as s:
                return bool(regex.search(s))
    except (ValueError, FileNotFoundError):
        return False

class Code:
    def __init__(self, repo_dir, struct_names):
        self.repo_dir = repo_dir
        self.structs = [Struct(name) for name in struct_names]

    def update(self, version):
        source_files = None
        for struct in self.structs:
            code_path = struct.get_code_path()
            search_regex = struct.search_regex
            if not code_path or not file_contains_byte_regex(code_path, search_regex):
                if source_files is None:
                    source_files = get_all_source_files(self.repo_dir)
                files = set([])
                for source_file in source_files:
                    if file_contains_byte_regex(source_file, search_regex):
                        files.add(source_file)
                if not files:
                    raise RuntimeError('Could not find ' + struct.typedef + ' in ' + str(version))
                if len(files) > 1:
                    raise RuntimeError(struct.typedef + ' implemented multiple places: ' + str(files))
                code_path = list(files)[0]
            struct_version = StructVersion(code_path, version, struct.struct_name)
            struct.add_version(struct_version)

    def write(self, output_dir):
        remove_headers_from_dir(output_dir)
        for struct in self.structs:
            output_path = path.join(output_dir, struct.header_name())
            logger.info('Writing ' + str(len(struct.versions)) + ' versions of ' + struct.typedef + ' to ' + output_path)
            with open(output_path, "w") as f:
                f.write(struct.emit_header())
