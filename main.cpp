#include <iostream>
#include "readAndPrint.h"
#include "calcFunctions.h"

using namespace std;

int main(int argc, char **argv)
{
    StartProgram();
    students = ReadFromFile() ? ReadFromFile("data/kursiokai.txt") : ReadUserInput();
    auto isMean = AskIfFinalGradeIsMean();
    students = isMean ? FindArithmeticMean(students) : FindMedian(students);
    students = FindFinalGrade(students, isMean);
    OutputToFile() ? PrintResultToFile(students, isMean) : PrintResult(students, isMean);
    return 0;
}