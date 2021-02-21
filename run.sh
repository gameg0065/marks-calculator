#!/bin/bash

readonly fileName=main
make
./$fileName

# g++ -std=c++0x main.cpp tests/tests.cpp -lgtest -lgtest_main -pthread -o tests/tests
# ./tests/tests