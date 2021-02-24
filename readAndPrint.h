#ifndef READANDPRINT_H
#define READANDPRINT_H
#include "variables.h"

void Clear();
bool MenuOptions();
void StartProgram();
void PrintWelcomeText();
void PrintResult(vector<Student> localStudents, bool isMean);
vector<Student> ReadUserInput();
vector<RawData> GetValidDataFromUser(vector<RawData> rawData);
bool AskIfFinalGradeIsMean();

#endif