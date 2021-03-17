#include <iostream>
#include "calcFunctions.h"

using namespace std;

vector<Student> FindArithmeticMean(vector<Student> &localStudens)
{
    if (localStudens.size() == 0)
    {
        throw domain_error("Empty vector");
    }
    
    for (int i = 0; i < localStudens.size(); i++)
    {
        double result = 0;
        int size = localStudens[i].grades.size() - 1;
        for (int y = 0; y < size; y++)
            result += localStudens[i].grades[y];
        localStudens[i].homeWorkGrade = result / size;
    }
    return localStudens;
}

vector<Student> SortGrades(vector<Student> &localStudens)
{
    for (int i = 0; i < localStudens.size(); i++)
    {
        sort(localStudens[i].grades.begin(), localStudens[i].grades.end() - 1);
    }

    return localStudens;
}

bool compareStudents(Student a, Student b)
{
    return a.firstName.compare(b.firstName) < 0;
}

vector<Student> FindMedian(vector<Student> &localStudens)
{
    if (localStudens.size() == 0) {
        throw domain_error("Empty vector");
    }

    localStudens = SortGrades(localStudens);

    for (int i = 0; i < localStudens.size(); i++)
    {
        int size = localStudens[i].grades.size() - 1;
        int middleGrade = localStudens[i].grades[size / 2];

        localStudens[i].homeWorkGrade = (size % 2 == 0 ? middleGrade / 2.0 + localStudens[i].grades[size / 2 - 1] / 2.0 : middleGrade);
    }
    return localStudens;
}

vector<Student> FindFinalGrade(vector<Student> &localStudens, bool isMean)
{
    if (localStudens.size() == 0)
    {
        throw domain_error("Empty vector");
    }

    for (int i = 0; i < localStudens.size(); i++)
    {
        sort(localStudens.begin(), localStudens.end(), compareStudents);
        localStudens[i].finalGrade =  localStudens[i].homeWorkGrade * 0.4 + 0.6 * localStudens[i].grades[localStudens[i].grades.size() - 1];
    }

    return localStudens;
}

vector<Student> FindGrades(vector<Student> &localStudens, bool isMean)
{
    localStudens = isMean ? FindArithmeticMean(students) : FindMedian(students);
    localStudens = FindFinalGrade(students, isMean);
    return localStudens;
}