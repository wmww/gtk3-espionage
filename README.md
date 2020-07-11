# GTK3 Espionage

__WARNING: Using this library is a bad idea__

__Current status:__ `not yet functional`

gtk3-espionage is a header-only library for extracting and modifying internal GTK state. The headers are automatically constructed from multiple versions of GTK3. This lets programs be compatible with all supported GTk versions, despite using internals that are not part of the stable API. Note that using gtk3-espionage is generally harder than forking GTK and adding the features you want, however it may be useful if you don't wish to maintain and distribute an entire GTK.

## Using in your project

TODO

## Building

NOTE: you don't need to build in order to use this project. Building the header files is only required when there is a new GTK or a structure is added

To build you need the following:
- Linux
  - MacOS *might* just work, but is untested
  - Windows support probably requires a small effort
- Python3
- Git

To build, run `./scripts/build.py`

This script will
- Load the list of structures from [scripts/struct_list.py](scripts/struct_list.py)
- Clone the official GTK git repository
- Detect all supported versions of GTK3
- Check out and extract data from each version
- Write header files for each structure

## Licensing

The library is licensed under the GNU Lesser General Public License (LGPL) version 3. See [COPYING.txt](COPYING.txt) for details. The build scripts are licensed under MIT. At the top of each file should be a header that specifies which license applies to it. Please refer to that if in doubt.

The library is technically a derivatives of GTK. GTK is licensed under LGPL v2 "or any later version", which allows this library to use LGPL v3. LGPL v3-licensed header files can be used by non-LGPL projects as per section 3.

__NOTE:__ by contributing to this project, you agree for your modifications to be licensed under the same license as the files they are made to (which may be a permissive license)
