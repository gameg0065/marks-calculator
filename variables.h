#ifndef VARIABLES_H
#define VARIABLES_H
#include <vector>
#include <string>

using namespace std;

const int MinNumberOfLetters = 3;
const int WidthOfNameAndSurname = 18;
const int MaxNumberOfStudents = 100;

// struct Student
// {
//     string firstName;
//     string lastName;
//     vector<int> grades;
//     double arithMeanGrade;
//     double finalGrade;
//     double medianGrade;
// };

struct Student
{
    string firstName;
    string lastName;
    int grades[MaxNumberOfStudents] = {[0 ... 99] = -1};
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

// static vector<Student> students;
extern Student students[MaxNumberOfStudents];

#endif