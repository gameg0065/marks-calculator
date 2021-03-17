#ifndef READANDPRINT_H
#define READANDPRINT_H
#include "variables.h"

void Clear();
bool MenuOptions();
vector<Student> ReadFromFile(string path);
void SaveData(vector<RawData> rawData);
void StartProgram();
bool AskReadFromFile();
bool OutputToFile();
void PrintWelcomeText();
void PrintResult(vector<Student> localStudents, bool isMean);
void PrintResultToFile(vector<Student> localStudents, bool isMean);
vector<RawData> ValidateDataForFile(vector<RawData> rawData);
vector<Student> ReadUserInput();
vector<RawData> GetValidDataFromUser(vector<RawData> rawData);
bool AskIfFinalGradeIsMean();

#endif