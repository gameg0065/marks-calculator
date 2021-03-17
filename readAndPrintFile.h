#ifndef READANDPRINTFile_H
#define READANDPRINTFile_H
#include "variables.h"

vector<Student> ReadFromFile(string path);
void PrintResultToFile(vector<Student> &localStudents, bool isMean);
vector<RawData>& ValidateDataForFile(vector<RawData> &rawData);

#endif