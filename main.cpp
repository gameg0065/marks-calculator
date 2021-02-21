#include <iostream>
#include "readAndPrint.h"
#include "calcFunctions.h"

using namespace std;

int main(int argc, char **argv)
{
    students = ReadUserInput();
    students = FindArithmeticMean(students);
    students = FindMedian(students);
    students = FindFinalGrade(students);
    PrintData(students);
}