# Catch2
## Intro

This is our local copy of the header-only form of [Catch2](https://github.com/catchorg/Catch2).
Please check the repo tags to see available versions.

This library supports idempotent inclusion, so use it liberally!

## Using this repository

Add `../../sdc/catch2.git` as a submodule to your own repository.
By default, `git submodule update --remote` will pull the master branch
(latest tagged version of Catch2 that we have)

In your CMakeLists.txt, add the line 
`add_subdirectory("catch2")`
ensuring that you provide the path to the catch2 submodule folder, if it differs from `./catch2`.

The library will be added to your CMake build, and the active version number
will be printed into your build log.

## Idempotence

[Idempotence](https://en.wikipedia.org/wiki/Idempotence) in this instance means that you can include
this library multiple times in your build, and it will only be activated by CMake once.

This is equivalent to a C++ header guard.

This allows us to avoid having to define Catch2 in a "known location" and instead include it with
everything that needs it locally, helping move towards independent builds.