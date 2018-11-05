#!/bin/sh

mkdir -p build
cd build; cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_TEST=ON && make -j 9 && ctest; cd -
