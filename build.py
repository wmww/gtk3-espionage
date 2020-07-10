#!/usr/bin/python3

'''
MIT License

Copyright 2020 William Wold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'''

import logging
import os
from os import path
import subprocess
import sys
import re

GTK_GIT_URL = 'https://gitlab.gnome.org/GNOME/gtk.git'
BUILD_DIR = 'build'
REPO_DIR = path.join(BUILD_DIR, 'gtk')
OUTPUT_PATH = 'gtk-espionage.h'
MIN_SUPPORTED_GTK = '3.22.0' # same format as the tag names
MAX_SUPPORTED_GTK = '3.70.0' # they randomly jumped to 3.89.1 in preperation for 4. ignore that

# Used to turn a minor.patch version into a single int
# See fuse_version()
MINOR_VERSION_MULTIPLYER = 1000

logger = logging.getLogger('build.py')
logging.basicConfig(level=logging.DEBUG)

# Clones the repo (or pulls if it already exists)
# Returns
def clone_repo(repo_url, repo_dir):
    if not path.exists(repo_dir):
        logger.info('Cloning ' + repo_url + ' into ' + repo_dir)
        subprocess.run(
            ['git', 'clone', repo_url, repo_dir]
            ).check_returncode()
    else:
        logger.info('Pulling')
        subprocess.run(
            ['git', 'pull'],
            cwd=repo_dir
            ).check_returncode()

# Returns a list of git tags
def get_tags(repo_dir):
    result = subprocess.run(
        ['git', 'tag', '-l'],
        capture_output=True,
        encoding='utf-8',
        cwd=repo_dir)
    result.check_returncode()
    tags = result.stdout.splitlines()
    logger.info('Found ' + str(len(tags)) + ' git tags')
    return tags

# Turns a GTK version into a sinle int that can be compared with <>
# Major is not used because we assume it's GTK3
# For example, v3.22.9 would fuse into 22009
def fuse_version(minor, patch):
    return minor * MINOR_VERSION_MULTIPLYER + patch

min_supported_version = None
max_supported_version = None

# Returns if the version is one we support
def version_is_supported(version):
    global min_supported_version
    global max_supported_version
    if min_supported_version is None or max_supported_version is None:
        min_supported_version = parse_tag(MIN_SUPPORTED_GTK)
        max_supported_version = parse_tag(MAX_SUPPORTED_GTK)
    return version >= min_supported_version and version <= max_supported_version

def parse_tag(name):
    match = re.search(r'^3\.(\d+)\.(\d+)$', name)
    if match:
        minor = int(match.group(1))
        patch = int(match.group(2))
        return fuse_version(minor, patch)
    else:
        return None

def parse_tag_list(tags):
    result = []
    for tag in tags:
        version = parse_tag(tag)
        if (version is not None) and version_is_supported(version):
            result.append((tag, version))
    logger.info('Found ' + str(len(result)) + ' supported versions')
    return result

def write_output(output_path, code):
    f = open(output_path, "w")
    f.write(code)
    f.close()

def build():
    if not path.exists(BUILD_DIR):
        logger.info('Creating directory ' + BUILD_DIR)
        os.makedirs(BUILD_DIR)
    clone_repo(GTK_GIT_URL, REPO_DIR)
    tags = get_tags(REPO_DIR)
    versions = parse_tag_list(tags)
    code = '\n'.join([str(v[1]) + ' (' + v[0] + ')' for v in versions]) + '\n'
    write_output(OUTPUT_PATH, code)

if __name__ == '__main__':
    build()
