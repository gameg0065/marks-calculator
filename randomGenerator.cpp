#include <iostream>
#include <random>
#include "randomGenerator.h"

using namespace std;

int GenerateRandomNumber()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}