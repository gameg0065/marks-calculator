#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "readAndPrint.h"
#include "variables.h"

using namespace std;

void SaveData(vector<RawData> rawData) {
    Student newStudent;
    for (int i = 0; i < rawData.size(); i++)
    {
        if (rawData[i].type == "name") {
            newStudent.firstName = rawData[i].data;
        }
        else if (rawData[i].type == "surname")
            newStudent.lastName = rawData[i].data;
        else {
            newStudent.grades.push_back(stoi(rawData[i].data));
        }
    }
    students.push_back(newStudent);
}

vector<RawData> ValidateData(vector<RawData> rawData)
{
    if (rawData.size() < 4) {
        RawData empty;
        for (int y = 0; y < 4; y++) {
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
        } else {
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

// TODO : Find way to determine operating sistem system("cls");
void Clear()
{
    system("clear");
}

vector<RawData> GetValidDataFromUser(vector<RawData> rawData)
{
    for (int i = 0; i < rawData.size(); i++)
    {
        if (!rawData[i].isValid)
        {
            if (rawData[i].type == "name")
                cout << "Enter correct name" << endl;
            else if (rawData[i].type == "surname")
                cout << "Enter correct surname" << endl;
            else 
                cout << "Enter correct mark" << endl;
            cin >> rawData[i].data;
            return ValidateData(rawData);
        }
    }
    return rawData;
}

void ReadUserInput() {
    Clear();
    vector<RawData> rawData;
    cout << "Input some data" << endl;

    while (true)
    {
        RawData tempData;

        cin >> tempData.data;

        if (tempData.data == "stop")
        {
            if (rawData.size() > 3) {
                SaveData(ValidateData(rawData));
            }
            break;
        }

        rawData.push_back(tempData);

        if (cin.get() == '\n' )
        {
            SaveData(ValidateData(rawData));
            rawData.clear();
            Clear();
            cout << "Another person:" << endl;
        }
    }
}



// TEMP:

void PrintData()
{
    cout << endl
         << "RESULTS:" << endl
         << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << "Vardas:  " << students[i].firstName << endl;
        cout << "Pavarde:  " << students[i].lastName << endl;
        for (int y = 0; y < students[i].grades.size(); y++)
        {
            cout << "Grade:  " << students[i].grades[y] << endl;
        }
    }
}

void print()
{
    cout << "just testing" << endl;
    PrintData();
}