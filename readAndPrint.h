#ifndef READANDPRINT_H
#define READANDPRINT_H
#include "variables.h"

void SaveData(vector<RawData> rawData);
void PrintResult(vector<Student> localStudents, bool isMean);
vector<Student> ReadUserInput();
vector<RawData> GetValidDataFromUser(vector<RawData> rawData);

#endif