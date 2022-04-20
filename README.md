<!--
SPDX-FileCopyrightText: 2022 Julian Amann <dev@vertexwahn.de>
SPDX-License-Identifier: Apache-2.0
-->

[![Support Ukraine](https://img.shields.io/badge/Support-Ukraine-FFD500?style=flat&labelColor=005BBB)](https://opensource.fb.com/support-ukraine)
[![Build Status](https://vertexwahn.visualstudio.com/FlatlandRT/_apis/build/status/Vertexwahn.FlatlandRT?branchName=master)](https://vertexwahn.visualstudio.com/FlatlandRT/_build/latest?definitionId=6&branchName=master)

# FlatlandRT

## Description

FlatlandRT is a 2D ray tracer visualization tool.
The following pictures were created using Flatland:

From left to right: Refraction, ambient occulsion and reflection:

![Refraction, ambient occulusion and reflection](docs/images/header.svg)

Quadtree intersection of 2d triangle meshes:

![Quadtree](docs/images/quadtree_StopSplitIfAtLeastTwoChildsHaveAsManySubShapesAsParent.svg)

More examples scenes can be found [here](devertexwahn/flatland/docs/example_scenes.md).
See the [user manual](devertexwahn/flatland/docs/user_manual.md) if you want to find out how to use it. 

## Quick start

This project uses [Bazel](https://bazel.build/) as a build system. The current used version is defined in [.bazelversion](devertexwahn/.bazelversion).

You can use Flatland by invoking the following Bazel command.

*Render a scene with Windows 10/11 x64 with Visual Studio 2019/2022:*

```bash
git clone https://github.com/Vertexwahn/FlatlandRT
cd FlatlandRT
cd devertexwahn # switch to the location where the WORKSPACE file is located
bazel --output_base=C:/bazel_output_base  run --config=vs2022 //flatland/cli:flatland.cli C:\scenes\bunny.flatland.xml
```

For more hints on how to use Bazel on Windows have a look at the [Bazel on Windows](https://docs.google.com/document/d/17YIqUdffxpwcKP-0whHM6TFELN8VohTpjiiEIbbRfts/edit?usp=sharing) document.

*Render a scene with Linux (e.g. Ubunutu 20.04):*

```bash
git clone https://github.com/Vertexwahn/FlatlandRT
cd FlatlandRT
cd devertexwahn # switch to the location where the WORKSPACE file is located
bazel run --config=gcc9 //flatland/cli:flatland.cli -- $(pwd)/flatland/scenes/bunny/bunny.flatland.xml
```

*Render a scene with macOS:*

```bash
git clone https://github.com/Vertexwahn/FlatlandRT
cd FlatlandRT
cd devertexwahn # switch to the location where the WORKSPACE file is located
bazel run --config=macos //flatland/cli:flatland.cli -- $(pwd)/flatland/scenes/bunny/bunny.flatland.xml
```

## Building

### Building with Linux

#### Command line (bash/zsh)

```bash
# Run all tests using GCC 9.3
bazel test --config=gcc9 //...
# Build all targets uing GCC 9.3
bazel build --config=gcc9 //... 
# Run all tests using Clang 13
bazel test --config=clang14 //...
# Build all targets uing Clang 13
bazel build --config=clang13 //... 
```

#### CLion

There is a Bazel Plugin for CLion. It can be downloaded from [here](https://plugins.jetbrains.com/author/4bb31785-ad06-4671-8e26-266aadc184bd).

You can use the following `.bazelproject` file:

```yaml
directories:
  .

test_sources:
  flatland/tests

derive_targets_from_directories: true

additional_languages:
  python

build_flags:
  --config=gcc9
```

#### Code coverage

Make sure that lcov is installed.

    sudo apt install lcov

Go to the directory that contains the `WORKSPACE` file and execute:

```bash
./coverage.sh buchgr_remote_cache
xdg-open coverage_report/index.html
```

#### Address Sanitizer

There is a build config called `asan` that can be used for detection memory errors.

    bazel run --config=asan --compilation_mode=opt //flatland/cli:flatland.cli --  $(pwd)/flatland/scenes/sphere.flatland.xml

#### Clang Tidy

    bazel build --config=clang-tidy //flatland/core/...

### Building with Windows

#### Command line (Powershell)

    # Build with Visual Studio C++ Compiler
    bazel build --config=vs2022 //...

#### Using Visual Studio

Use [Lavender](https://github.com/tmandry/lavender) to generate a solution and project files for Visual Studio.

```bash
python3 G:\dev\lavender\generate.py --config=vs2022  //...
```

Lavender is far from being perfect. 
It might be necessary to do some modifications to the generated solution and project files.

## Development process

I made a short video where I describe how I use test driven development to implement this project: 
[![Let's Code: Using Test-driven Development to implement a ray tracer](https://img.youtube.com/vi/vFBXNr952nU/0.jpg)](https://www.youtube.com/watch?v=vFBXNr952nU)

## Ray tracing 101

I have written several blog posts about ray tracing:

- [Ray tracing 101: Refraction of light](https://vertexwahn.de/2020/12/19/refraction/)
- [Ray tracing 101: Matrices and coordinate systems](https://vertexwahn.de/2020/12/20/coordinatesystemsandmatrices/)
- [Ray tracing 101: How does a look at transform work?](https://vertexwahn.de/2020/12/21/lookat/)
- [Ray tracing 101: Perspective projection](https://vertexwahn.de/2020/12/27/perspectiveprojection/)
- [Ray tracing 101: Shooting Rays](https://vertexwahn.de/2021/01/03/shootingrays/)
- [Ray Tracing 101: Image sampling and reconstruction](https://vertexwahn.de/2021/02/28/imagereconstruction/)
- [Ray Tracing 101: Ray Triangle Intersection](https://vertexwahn.de/2021/05/29/raytriangleintersection/)
- [Ray Tracing 101: Octrees for faster intersection](https://vertexwahn.de/2022/03/12/octree/)

## License

The source code of FlatlandRT itself is under the Apache License 2.0 (see [LICENSE](LICENSE)).
The license of its third-party dependencies or some third-party code fragments can and is under different license terms. See copyright notes in the next section.

## Copyright notes

FlatlandRT makes use of several software libraries.
Some tools and libraries were copied to this repository (see `third_party` folder).
The corresponding licenses can be found in the `third_party` folder of this repository.
Besides this,
some source code was directly copied from other open-source software libraries or programs.
This is always clearly stated as a comment in the source code of FlatlandRT.
If you find any copyright or license violations or issues please let me know.

### Copied source code/ideas

* Mitsuba Renderer 2 (https://github.com/mitsuba-renderer/mitsuba2) (scene file format) ([License](devertexwahn/flatland/LICENSES/mitsuba2/LICENSE))
* envoy (https://github.com/glasnostic/envoy) (third party Bazel dependency for tclap, i.e. tclap.BUILD)  ([License](devertexwahn/flatland/LICENSES/envoy/LICENSE))
* pbrt, Version 3 (https://github.com/mmp/pbrt-v3) (Refract, face_forward functions) ([License](devertexwahn/flatland/LICENSES/pbrt-v3/LICENSE.txt))
* pbrt, Version 4 (https://github.com/mmp/pbrt-v4) (concentric sampling of unit disk) ([License](devertexwahn/flatland/LICENSES/pbrt-v4/LICENSE.txt))
* bazel_clang_tidy (https://github.com/erenon/bazel_clang_tidy) (almost everything) ([License](devertexwahn/flatland/LICENSES/bazel_clang_tidy/LICENSE))

### Build related

* LLVM toolchain for Bazel (https://github.com/grailbio/bazel-toolchain) (building Flatland with LLVM) ([License](licenses/llvm_bazel_toolchain/LICENSE))

### Third party dependencies

* Boost (https://www.boost.org/) (third party dependency) ([License](devertexwahn/flatland/LICENSES/boost/LICENSE))
* Catch2 (https://github.com/catchorg/Catch2) (see `third_party` folder)
* Eigen 3.4.0 (see `third_party` folder)
* Google Test (https://github.com/google/googletest) (see `third_party` folder)
* Imath 3.1.4 (see `third_party` folder)
* LLVM toolchain for Bazel (see `third_party` folder)
* OpenEXR (see `third_party` folder)
* TCLAP - Templatized Command Line Argument Parser (https://github.com/mirror/tclap)  (see `third_party` folder)
* gflags (https://github.com/gflags/gflags/) (see `third_party` folder)
* glog (https://github.com/google/glog) (see `third_party` folder)
* hypothesis (https://github.com/wjakob/hypothesis) (see `third_party` folder)
* libpng-1.6.37 (https://github.com/wjakob/hypothesis) (see `third_party` folder)
* pcg-cpp (https://github.com/imneme/pcg-cpp/)  (see `third_party` folder)
* pugixml (https://pugixml.org/, https://github.com/zeux/pugixml) (third party dependency) (see `third_party` folder)
* rules_boost (see `third_party` folder)
* rules_pkg (see `third_party` folder)
* yaml-cpp (https://github.com/jbeder/yaml-cpp) (third party dependency) ([License](devertexwahn/flatland/LICENSES/yaml-cpp/LICENSE))
* zlib 1.2.11 (https://zlib.net/) ([License](devertexwahn/flatland/LICENSES/third_party/zlib-1.2.11/README))
* {fmt} (https://github.com/fmtlib/fmt) (see `third_party` folder)

### Artwork

The Stanford Bunny was derived from the Stanford Bunny provided from the Stanford 3D Scanning Repository (see [here](http://graphics.stanford.edu/data/3Dscanrep/#bunny)).

The data for the Donut, Armadillo and Stanford Bunny for the 2D triangle data was derived from https://github.com/mmacklin/sandbox. 

### Credits

A big thank goes to all the providers, developers and maintainers of the aforementioned artifacts.
