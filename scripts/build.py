#!/usr/bin/python3

'''
MIT License

Copyright 2020 William Wold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'''

import logging
from os import path
import sys

from version import parse_tag_list
from repo import Repo
import code

GTK_GIT_URL = 'https://gitlab.gnome.org/GNOME/gtk.git'
BUILD_DIR = 'build'
REPO_DIR = path.join(BUILD_DIR, 'gtk')
OUTPUT_PATH = 'gtk-espionage.h'

STRUCTS = [
    'GdkWindowImplWayland',
    'GdkWaylandSeat',
]

logger = logging.getLogger('build.py')
logging.basicConfig(level=logging.DEBUG)

def write_output(output_path, code):
    f = open(output_path, "w")
    f.write(code)
    f.close()

def build():
    if not path.exists(BUILD_DIR):
        logger.info('Creating directory ' + BUILD_DIR)
        os.makedirs(BUILD_DIR)
    repo = Repo(GTK_GIT_URL, REPO_DIR)
    tags = repo.get_tags()
    versions = parse_tag_list(tags)
    for v in versions:
        repo.checkout(v.tag)
    code = '\n'.join([str(v) for v in versions]) + '\n'
    write_output(OUTPUT_PATH, code)

if __name__ == '__main__':
    build()
