#include <iostream>
#include "readAndPrint.h"
#include "calcFunctions.h"

using namespace std;

int main(int argc, char **argv)
{
    StartProgram();
    ReadUserInput();
    auto isMean = AskIfFinalGradeIsMean();
    isMean ? FindArithmeticMean() : FindMedian();
    FindFinalGrade(isMean);
    PrintResult(isMean);
}