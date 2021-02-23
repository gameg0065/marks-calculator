#include <iostream>
#include "calcFunctions.h"

using namespace std;

int CountGrades(int m)
{
    int number = 0;
    for (int i = 0; i < 100; i++)
    {
        if (students[m].grades[i] != -1)
            number++;
    }
    return number;
}

void FindArithmeticMean()
{
    for (int i = 0; i < 100; i++)
    {
        if (!students[i].firstName.empty())
        {
            double result = 0;
            for (int y = 0; y < CountGrades(i) - 1; y++)
            {
                result += students[i].grades[y];
                cout << result << endl;
            }
            students[i].arithMeanGrade = result / (CountGrades(i) - 1);
        }
    }
}


void SortGrades()
{
    for (int i = 0; i < 100; i++)
    {
        if (!students[i].firstName.empty())
        {
            for (int step = 0; step < CountGrades(i) - 2; ++step)
            {
                for (int y = 0; y < CountGrades(i) - 1 - step - 1; ++y)
                {
                    if (students[i].grades[y] > students[i].grades[y + 1])
                        swap(students[i].grades[y], students[i].grades[y + 1]);
                }
            }
        }
    }
}

void FindMedian() {
    SortGrades();
    for (int i = 0; i < 100; i++)
    {
        if(!students[i].firstName.empty()) {
            if ((CountGrades(i) - 1) % 2 == 0) 
                students[i].medianGrade = (students[i].grades[(CountGrades(i) - 1) / 2] + students[i].grades[(CountGrades(i) - 1) / 2 - 1]) / 2.0;
            else
                students[i].medianGrade = students[i].grades[(CountGrades(i) - 1) / 2];
        }
    }
}

void FindFinalGrade(bool isMean)
{
    for (int i = 0; i < 100; i++)
    {
        students[i].finalGrade = (isMean ? students[i].arithMeanGrade: students[i].medianGrade ) * 0.4 + 0.6 * students[i].grades[CountGrades(i) - 1];
    }
}