#include <iostream>
#include "readAndPrint.h"
#include "readAndPrintFile.h"
#include "calcFunctions.h"
#include "userInteraction.h"

using namespace std;

int main(int argc, char **argv)
{
    StartProgram();
    students = AskReadFromFile() ? ReadFromFile("data/kursiokai.txt") : ReadUserInput();
    auto isMean = AskIfFinalGradeIsMean();
    students = FindFinalGrade(students, isMean);
    AskOutputToFile() ? PrintResultToFile(students, isMean) : PrintResult(students, isMean);
    return 0;
}