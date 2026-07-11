Windows Build and Run
=====================

This tree now supports a native Windows build using CMake.

Prerequisites
-------------

- A C compiler toolchain (MSVC or Clang or MinGW)
- CMake 3.16 or newer

Build with CMake
----------------

From the project root:

  cmake -S . -B build-win
  cmake --build build-win --config Release

The resulting executables are produced in the build directory.

Run quick checks
----------------

- bc help:

  build-win\bc.exe -h

- bc expression:

  echo 1+1 | build-win\bc.exe

- dc version:

  build-win\dc.exe -V

Notes
-----

- If CMake is not installed, you can still compile with direct compiler commands,
  but CMake is the supported Windows workflow for this repository.
- The checked-in config.h contains Windows compatibility aliases for MSVC-style
  runtime function names.
