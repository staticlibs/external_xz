Xz library build for Staticlibs
===============================

[![travis](https://travis-ci.org/staticlibs/external_xz.svg?branch=master)](https://travis-ci.org/staticlibs/external_xz)
[![appveyor](https://ci.appveyor.com/api/projects/status/github/staticlibs/external_xz?svg=true)](https://ci.appveyor.com/project/staticlibs/external-xz)

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a CMake build file for building the [XZ library](http://tukaani.org/xz/).

[XZ sources imported from CentOS lookaside](https://github.com/ojdkbuild/lookaside_xz.git)
are used as a submodule of this project.

How to build
------------

[CMake](http://cmake.org/) is required for building.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone --recursive https://github.com/staticlibs/external_xz.git
    cd external_xz
    mkdir build
    cd build
    cmake ..
    msbuild external_xz.sln

See [StaticlibsToolchains](https://github.com/staticlibs/wiki/wiki/StaticlibsToolchains) for 
more information about the CMake toolchains setup and cross-compilation.

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2017-12-24**

 * version 5.2.1-2
 * vs2017 support

**2016-10-30**

 * version 5.1.2-1
 * use XZ sources from CentOS

**2016-01-28**

 * CMake build for Linux
