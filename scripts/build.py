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
from code import Project
from config import STRUCT_LIST

GTK_GIT_URL = 'https://gitlab.gnome.org/GNOME/gtk.git'
BUILD_DIR = 'build'
OUTPUT_DIR = 'h'
REPO_DIR = path.join(BUILD_DIR, 'gtk')

logger = logging.getLogger('build.py')
logging.basicConfig(level=logging.DEBUG)

def build():
    if not path.exists(BUILD_DIR):
        logger.info('Creating directory ' + BUILD_DIR)
        os.makedirs(BUILD_DIR)
    repo = Repo(GTK_GIT_URL, REPO_DIR)
    tags = repo.get_tags()
    versions = parse_tag_list(tags)
    project = Project(REPO_DIR, STRUCT_LIST)
    for i, v in enumerate(versions):
        percent = int(((i + 1) / len(versions)) * 1000) / 10
        logger.info('[' + str(percent) + '%] Checking out ' + str(v))
        repo.checkout(v.tag)
        project.update(v)
    project.simplify()
    project.write(OUTPUT_DIR)

if __name__ == '__main__':
    build()
