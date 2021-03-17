#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "readAndPrint.h"
#include "readAndPrintFile.h"
#include "variables.h"
#include "randomGenerator.h"

using namespace std;

vector<Student> ReadFromFile(string path)
{
    ifstream file;
    file.open(path);
    try
    {
        if (file.is_open())
        {
            string temp;
            getline(file, temp);
            vector<RawData> rawData;

            while (true)
            {
                RawData tempData;

                file >> tempData.data;

                if (tempData.data.empty() && file.get() != '\n')
                {
                    SaveData(ValidateDataForFile(rawData));
                    break;
                }

                rawData.push_back(tempData);

                if (file.get() == '\n')
                {
                    SaveData(ValidateDataForFile(rawData));
                    rawData.clear();
                }
            }
        }
        else
            throw runtime_error("Error opening file");

        file.close();
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    return students;
}

vector<RawData> ValidateDataForFile(vector<RawData> rawData)
{
    if (rawData.size() < 4)
    {
        return rawData;
    }
    rawData[0].type = "name";
    rawData[1].type = "surname";
    rawData[0].isValid = true;
    rawData[1].isValid = true;

    for (int i = 2; i < rawData.size(); i++)
    {
        rawData[i].type = "number";
        istringstream iss(rawData[i].data);
        int number;
        iss >> number;
        if (!(iss.fail() || number > 10 || number < 0))
            rawData[i].isValid = true;
    }
    return rawData;
}

void PrintResultToFile(vector<Student> localStudents, bool isMean)
{
    ofstream file;
    file.open(FileOuputPath);
    try
    {
        if (file.is_open())
        {
            int width = WidthOfNameAndSurname;
            file << endl
                 << left << setw(width) << "Vardas" << setw(width) << "Pavarde"
                 << "Galutinis " << (isMean ? "Vid." : "Med.") << endl;
            file << string(width * 3, '-') << endl
                 << endl;
            ;
            for (int i = 0; i < localStudents.size(); i++)
                file << left << setw(width) << localStudents[i].firstName << setw(width) << localStudents[i].lastName << fixed << setprecision(2) << localStudents[i].finalGrade << endl;
        }
        else
        {
            throw runtime_error("Error opening file");
        }
        file.close();
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}