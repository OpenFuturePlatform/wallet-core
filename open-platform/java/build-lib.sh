#!/bin/bash

rm -rf CMakeFiles cmake_install.cmake CMakeCache.txt Makefile libtrust-core-jvm.dylib
cmake . -DWALLET_CORE=../../
make