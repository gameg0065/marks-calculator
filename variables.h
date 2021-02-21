#ifndef VARIABLES_H
#define VARIABLES_H
#include <vector>
#include <string>

using namespace std;

const int MinNumberOfLetters = 3;

struct Student
{
    string firstName;
    string lastName;
    vector<int> grades;
    double arithMeanGrade;
    double finalGrade;
    double medianGrade;
};

struct RawData
{
    string data;
    string type;
    bool isValid = false;
};

static vector<Student> students;

#endif