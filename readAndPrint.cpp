#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "readAndPrint.h"
#include "userInteraction.h"
#include "variables.h"
#include "randomGenerator.h"

using namespace std;

vector<Student> SaveData(vector<RawData> &rawData, vector<Student> &localStudent)
{
    Student newStudent;
    for (int i = 0; i < rawData.size(); i++)
    {
        if (rawData[i].isValid)
        {
            if (rawData[i].type == "name")
            {
                newStudent.firstName = rawData[i].data;
            }
            else if (rawData[i].type == "surname")
                newStudent.lastName = rawData[i].data;
            else
            {
                newStudent.grades.push_back(stoi(rawData[i].data) == 0 ? GenerateRandomNumber() : stoi(rawData[i].data));
            }
        }
    }
    localStudent.push_back(newStudent);
    return localStudent;
}

vector<RawData>& ValidateData(vector<RawData> &rawData)
{
    if (rawData.size() < 4)
    {
        RawData empty;
        for (int y = 0; y < 4; y++)
        {
            if (rawData[y].data == "")
                rawData.push_back(empty);
        }
    }
    rawData[0].type = "name";
    rawData[1].type = "surname";

    if (rawData[0].data.length() < 3)
    {
        rawData = GetValidDataFromUser(rawData);
    }
    else if (rawData[1].data.length() < 3)
    {
        rawData[0].isValid = true;
        rawData = GetValidDataFromUser(rawData);
    }
    else
    {
        rawData[0].isValid = true;
        rawData[1].isValid = true;
        if (rawData.size() < 4)
        {
            rawData = GetValidDataFromUser(rawData);
        }
        else
        {
            for (int i = 2; i < rawData.size(); i++)
            {
                rawData[i].type = "number";
                istringstream iss(rawData[i].data);
                int number;
                iss >> number;
                if (iss.fail() || number > 10 || number < 0)
                    rawData = GetValidDataFromUser(rawData);
                else
                    rawData[i].isValid = true;
            }
        }
    }
    return rawData;
}

vector<RawData> GetValidDataFromUser(vector<RawData> &rawData)
{
    for (int i = 0; i < rawData.size(); i++)
    {
        if (!rawData[i].isValid)
        {
            if (rawData[i].type == "name")
                cout << "Iveskite teisinga varda" << endl;
            else if (rawData[i].type == "surname")
                cout << "Iveskite teisinga pavarde" << endl;
            else
                cout << "Iveskite teisinga pazymi" << endl;
            cin >> rawData[i].data;
            return ValidateData(rawData);
        }
    }
    return rawData;
}

vector<Student> ReadUserInput()
{
    Clear();
    vector<RawData> rawData;
    cout << "Iveskite varda pavarde pazymius ( per tarpa ) ir galutini pazymi. ( pvz: vardenis pavardenis 5 6 7 10 )" << endl;

    while (true)
    {
        RawData tempData;

        cin >> tempData.data;

        if (tempData.data == "stop" || tempData.data == "nope" || tempData.data == "baigti")
        {
            if (rawData.size() > 3)
            {
                students = SaveData(ValidateData(rawData), students);
            }
            break;
        }

        rawData.push_back(tempData);

        if (cin.get() == '\n')
        {
            SaveData(ValidateData(rawData), students);
            rawData.clear();
            cout << "Kito asments duomenys:" << endl;
        }
    }
    return students;
}

void PrintResult(vector<Student> &localStudents, bool isMean)
{
    Clear();
    int width = WidthOfNameAndSurname;
    cout << endl
         << left << setw(width) << "Vardas" << setw(width) << "Pavarde"
         << "Galutinis " << (isMean ? "Vid." : "Med.") << endl;
    cout << string(width * 3, '-') << endl
         << endl;
    ;
    for (int i = 0; i < localStudents.size(); i++)
        cout << left << setw(width) << localStudents[i].firstName << setw(width) << localStudents[i].lastName << fixed << setprecision(2) << localStudents[i].finalGrade << endl;
}