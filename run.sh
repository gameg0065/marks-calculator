#!/bin/bash

readonly fileName=main
rm -rf make
make
./$fileName

# g++ -std=c++0x main.cpp tests/tests.cpp -lgtest -lgtest_main -pthread -o tests/tests
# ./tests/tests