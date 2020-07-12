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
INDENT = '  ' # only used for generating code, which isn't normally done

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

def remove_comments(code):
    return re.sub(r'(/\*.*?\*/|//.*?\n)', '', code, flags=re.DOTALL)

# These can be combined in any order, we do not check that it is valid
std_types = set([
    'void',
    'int',
    'char',
    'signed',
    'unsigned',
    'short',
    'long',
    'float',
    'double',
])

def is_std_type(name):
    for i in name.split():
        if not i in std_types:
            return False
    return True

class CType:
    def __str__(self):
        return self.str_left() + self.str_right()

    def str_right(self):
        return ''

class StdType(CType):
    def __init__(self, name):
        assert isinstance(name, str)
        assert is_std_type(name), name
        self.name = name

    def str_left(self):
        return self.name

class CustomType(CType):
    def __init__(self, name):
        assert isinstance(name, str)
        explicit_struct = False
        if name.startswith('struct'):
            name = name[6:].strip()
            explicit_struct = True
        self.name = name
        self.explicit_struct = explicit_struct

    def str_left(self):
        result = ''
        if self.explicit_struct:
            result += 'struct '
        result += self.name
        return result

class PtrType(CType):
    def __init__(self, inner):
        assert isinstance(inner, CType)
        self.inner = inner

    def str_left(self):
        result = self.inner.str_left()
        if not isinstance(self.inner, PtrType):
            result += ' '
        result += '*'
        return result

    def str_right(self):
        return self.inner.str_right()

class ConstType(CType):
    def __init__(self, inner):
        assert isinstance(inner, CType)
        self.inner = inner

    def str_left(self):
        return 'const ' + self.inner.str_left()

    def str_right(self):
        return self.inner.str_right()

# Note the first (and usually only) layer of "pointer" is consumed by this type
# Do not wrap in a PtrType in most cases
class FpType(CType):
    def __init__(self, return_type, arg_list):
        assert isinstance(return_type, CType)
        assert isinstance(arg_list, list)
        for i in arg_list:
            assert isinstance(i, PropertyNode)
        self.return_type = return_type
        self.arg_list = arg_list

    def str_left(self):
        return str(self.return_type) + ' (*'

    def str_right(self):
        return ') (' + str(', '.join([str(t) for t in self.arg_list])) + ')'

class ArrayType(CType):
    def __init__(self, inner, size):
        assert isinstance(inner, CType)
        assert isinstance(size, str)
        self.inner = inner
        self.size = size

    def str_left(self):
        return self.inner.str_left()

    def str_right(self):
        return '[' + self.size + ']' + self.inner.str_right()

class AstNode:
    pass

class PropertyNode(AstNode):
    def __init__(self, c_type, name, bit_field = None):
        assert isinstance(c_type, CType)
        assert name is None or isinstance(name, str)
        assert bit_field is None or isinstance(bit_field, int)
        self.c_type = c_type
        self.name = name
        self.bit_field = bit_field

    def __str__(self):
        result = self.c_type.str_left()
        if self.name:
            if not isinstance(self.c_type, PtrType):
                result += ' '
            result += self.name
        result += self.c_type.str_right()
        if self.bit_field:
            result += ' : ' + str(self.bit_field)
        return result

class ListNode(AstNode):
    def __init__(self, nodes):
        assert isinstance(nodes, list)
        for node in nodes:
            assert isinstance(node, AstNode)
        self.nodes = nodes

    def __str__(self):
        return '\n'.join(str(node) + ';' for node in self.nodes)

class SubStructNode(AstNode):
    def __init__(self, name, content):
        assert isinstance(name, str)
        assert isinstance(content, AstNode)
        self.name = name
        self.content = content

    def __str__(self):
        return (
            'struct {' +
            ('\n' + INDENT).join([''] + str(self.content).splitlines()) +
            '\n} ' + self.name)

def parse_type(code):
    code = code.strip()
    if code.endswith('*'):
        return PtrType(parse_type(code[:-1]))
    elif code.startswith('const '):
        return ConstType(parse_type(code[5:]))
    if code.endswith(' const'):
        return ConstType(parse_type(code[:5]))
    elif is_std_type(code):
        return StdType(code)
    elif re.search(r'^(struct\s+)?\w+$', code):
        return CustomType(code)
    else:
        assert False, 'Unknown type `' + code + '`'

def parse_property(code):
    code = code.strip()
    bit_field = None
    bit_field_split = code.rsplit(':', 1)
    if len(bit_field_split) > 1:
        code = bit_field_split[0].strip()
        bit_field = int(bit_field_split[1].strip())
    normal = re.search(r'^((\w+\s*\W)+(\*\s*)*)(\w*)$', code)
    if normal:
        c_type = parse_type(normal.group(1))
        name = normal.group(4)
        if name == '':
            name = None
        return PropertyNode(c_type, name, bit_field)
    fp = re.search(r'^(.*)\(\s*(\*\s*)+(\w*)\s*\)\s*\((.*)\)$', code)
    if fp:
        assert bit_field is None
        ret = parse_type(fp.group(1))
        pointer_count = fp.group(2).count('*') - 1
        name = fp.group(3)
        if name == '':
            name = None
        args = []
        for i in fp.group(4).split(','):
            args.append(parse_property(i))
        c_type = FpType(ret, args)
        return PropertyNode(c_type, name)
    assert False, 'Could not parse property `' + code + '`'

def parse_token_list(tokens, i):
    nodes = []
    while i < len(tokens):
        token = tokens[i].strip()
        if token == '' or token == ';':
            pass
        elif token == 'struct' and tokens[i + 1].strip() == '{':
            i, node = parse_token_list(tokens, i + 2)
            i += 1
            assert i < len(tokens)
            name = tokens[i].strip()
            assert re.search(r'^\w+$', name)
            struct = SubStructNode(name, node)
            nodes.append(struct)
        elif token == '}':
            break
        else:
            nodes.append(parse_property(token))
        i += 1
    return i, ListNode(nodes)

def parse_ast(code):
    code = remove_comments(code)
    code = code.replace('\n', ' ')
    code = code.replace('\t', ' ')
    tokens = re.split(r'([;\{\}])', code)
    i, node = parse_token_list(tokens, 0)
    assert i == len(tokens), code
    return node

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
        self.version = version
        self.struct_name = struct_name
        self.copyright_lines = set(re.findall(r'[Cc]opyright .*(?=\n)', source_code))
        self.body = extract_body(source_code, struct_name)
        self.ast = parse_ast(self.body)

    def emit_definition(self):
        return 'struct ' + str(self) + '\n{' + self.body + '}\n'

    def generate_definition(self):
        return (
            'struct ' + str(self) +
            '\n{\n' +
            INDENT + ('\n' + INDENT).join(str(self.ast).splitlines()) +
            '\n}\n')

    def __str__(self):
        return self.struct_name + '_' + self.version.c_id()

    def __eq__(self, other):
        assert isinstance(other, StructVersion)
        return self.body == other.body

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
        result += '\n * '.join(LGPL3_HEADER.splitlines())
        result += '\n */\n'
        result += '\n'
        result += 'typedef struct ' + self.struct_name + ' ' + self.typedef + '\n'
        result += '\n'
        for i in self.versions:
            result += i.generate_definition()
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
                                logger.info('Found ' + struct.typedef + ' in ' + i)
                                files = hits.get(struct.typedef, set([]))
                                files.add(i)
                                hits[struct.typedef] = files
                except ValueError:
                    pass
        for struct in self.structs:
            files = hits.get(struct.typedef)
            if not files:
                raise RuntimeError('Could not find ' + struct.typedef + ' in ' + str(version))
            if len(files) > 1:
                raise RuntimeError(struct.typedef + ' implemented multiple places: ' + str(files))
            struct_version = StructVersion(list(files)[0], version, struct.struct_name)
            struct.add_version(struct_version)

    def write(self, output_dir):
        for struct in self.structs:
            output_path = path.join(output_dir, struct.header_name())
            with open(output_path, "w") as f:
                f.write(struct.emit_header())
