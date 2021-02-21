#include <iostream>
#include <vector>
#include <string>

#include "readAndPrint.h"
#include "variables.h"

using namespace std;

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
            cout << i << "Grade:  " << students[i].grades[y]<< endl;
        }
    }
}

void print() {
    cout << "just testing" << endl;
    PrintData();
}

ValidateData IsDataValid(vector<RawData> rawData)
{
    ValidateData returnValue;
    cout << "Validation" << endl;

    if (rawData[0].data.length() < 3) {
        rawData[0].type = "name";
        returnValue.error = "name is not long enought";
        return returnValue;
    }
    else if (rawData[1].data.length() < 3)
    {
        rawData[0].isValid = true;
        rawData[1].type = "surnmae";
        returnValue.error = "surname is not long enought";
        return returnValue;
    } else {
        rawData[1].isValid = true;
        if (rawData.size() < 4) {
            returnValue.error = "No enought grades :(";
            return returnValue;
        }
        for (int i = 2; i < rawData.size(); i++)
        {
            rawData[i].type = "number";
            if (rawData[i].data.length() != 1 || stoi(rawData[i].data) > 10 || stoi(rawData[i].data) < 0) {
                returnValue.error = "Grade is not a number";
                return returnValue;
            } else {
                rawData[i].isValid = true;
            }
        }
    }
    returnValue.isValid = true;
    return returnValue;
}

// TODO : Find way to determine operating sistem system("cls");
void Clear()
{
    system("clear");
}


void ReadUserInput() {
    // Clear();
    vector<RawData> rawData;
    cout << "Input some data" << endl;

    while (true)
    {
        RawData tempData;

        cin >> tempData.data;

        if (tempData.data == "stop")
        {
            break;
        }

        rawData.push_back(tempData);
        cin.ignore();
        if (cin.get() == '\n')
        {
            // Clear();
            auto temp = IsDataValid(rawData);
            cout << (temp.isValid == 0 ? "nope" : "jep") << " " << temp.error << endl;
            rawData.clear();
        }
    }
}
