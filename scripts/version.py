'''
MIT License

Copyright 2020 William Wold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'''

import logging
import functools
import re

MIN_SUPPORTED_GTK = '3.22.0' # same format as the tag names
MAX_SUPPORTED_GTK = '3.24.18' # 3.24.19 changes GdkWindow to GdkSurface -- what?
#MAX_SUPPORTED_GTK = '3.70.0' # they randomly jumped to 3.89.1 in preperation for 4. ignore that

logger = logging.getLogger(__name__)

@functools.total_ordering # implement all comparisons with just eq and lt
class Version:
    def __init__(self, tag):
        self.tag = tag
        match = re.search(r'^3\.(\d+)\.(\d+)$', tag)
        if match:
            self.minor = int(match.group(1))
            self.patch = int(match.group(2))
        else:
            raise RuntimeError(tag + ' is not a valid version')

    def __eq__(self, other):
        return self.minor == other.minor and self.patch == other.patch

    def __lt__(self, other):
        if self.minor == other.minor:
            return self.patch < other.patch
        else:
            return self.minor < other.minor

    def is_supported(self):
        '''Returns if the version is one we support'''
        return self >= min_supported_version and self <= max_supported_version

    def __str__(self):
        return 'v' + self.tag

    def c_id(self):
        '''a string suitable for a C identifier'''
        return 'v3_' + str(self.minor) + '_' + str(self.patch)

min_supported_version = Version(MIN_SUPPORTED_GTK)
max_supported_version = Version(MAX_SUPPORTED_GTK)

def parse_tag_list(tags):
    result = []
    for tag in tags:
        try:
            version = Version(tag)
            if version.is_supported():
                result.append(version)
        except RuntimeError as e:
            pass
    logger.info('Found ' + str(len(result)) + ' supported versions')
    result.sort()
    return result
