#!/bin/bash

if [ $1 == "tests" ]; then
   g++ -std=c++0x calcFunctions.cpp tests/tests.cpp -lgtest -lgtest_main -pthread -o tests/tests
    ./tests/tests
else
    make
    ./main
    make clean
fi
