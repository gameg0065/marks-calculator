#ifndef CALCFUNCTIONS_H
#define CALCFUNCTIONS_H
#include "readAndPrint.h"

vector<Student> FindArithmeticMean(vector<Student> &localStudens);
vector<Student> FindFinalGrade(vector<Student> &localStudens, bool isMean);
vector<Student> FindMedian(vector<Student> &localStudens);
vector<Student> FindGrades(vector<Student> &localStudens, bool isMean);

#endif