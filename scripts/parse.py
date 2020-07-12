'''
MIT License

Copyright 2020 William Wold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'''

import logging
import re

INDENT = '  ' # only used for generating code, which isn't normally done

logger = logging.getLogger(__name__)

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
