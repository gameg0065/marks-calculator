#ifndef READANDPRINT_H
#define READANDPRINT_H
#include "variables.h"

void PrintData(vector<Student> localStudents);
vector<Student> ReadUserInput();
vector<RawData> GetValidDataFromUser(vector<RawData> rawData);

#endif