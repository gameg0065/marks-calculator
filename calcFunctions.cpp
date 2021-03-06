#include <iostream>
#include "calcFunctions.h"

using namespace std;

vector<Student> FindArithmeticMean(vector<Student> &localStudens)
{
    for (int i = 0; i < localStudens.size(); i++)
    {
        double result = 0;
        for (int y = 0; y < localStudens[i].grades.size() - 1; y++)
        {
            result += localStudens[i].grades[y];
        }
        localStudens[i].arithMeanGrade = result / (localStudens[i].grades.size() - 1);
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
    localStudens = SortGrades(localStudens);

    for (int i = 0; i < localStudens.size(); i++)
    {
        if ((localStudens[i].grades.size() - 1) % 2 == 0)
            localStudens[i].medianGrade = (localStudens[i].grades[(localStudens[i].grades.size() - 1) / 2] + localStudens[i].grades[(localStudens[i].grades.size() - 1) / 2 - 1]) / 2.0;
        else
            localStudens[i].medianGrade = localStudens[i].grades[(localStudens[i].grades.size() - 1) / 2];
    }
    return localStudens;
}

vector<Student> FindFinalGrade(vector<Student> &localStudens, bool isMean)
{
    for (int i = 0; i < localStudens.size(); i++)
    {
        sort(localStudens.begin(), localStudens.end(), compareStudents);
        localStudens[i].finalGrade = (isMean ? localStudens[i].arithMeanGrade : localStudens[i].medianGrade) * 0.4 + 0.6 * localStudens[i].grades[localStudens[i].grades.size() - 1];
    }

    return localStudens;
}