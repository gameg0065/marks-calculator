#ifndef READANDPRINT_H
#define READANDPRINT_H
#include "variables.h"

vector<Student> SaveData(vector<RawData> &rawData, vector<Student> &localStudent);
void PrintResult(vector<Student> &localStudents, bool isMean);
vector<Student> ReadUserInput();
vector<RawData> GetValidDataFromUser(vector<RawData> &rawData);

#endif