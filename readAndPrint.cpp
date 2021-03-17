#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "readAndPrint.h"
#include "variables.h"
#include "randomGenerator.h"

using namespace std;

void SaveData(vector<RawData> rawData)
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
    students.push_back(newStudent);
}

vector<RawData> ValidateData(vector<RawData> rawData)
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

void PrintWelcomeText()
{
    Clear();
    string name = "Pažymių skaičiuokė";
    int whiteSpace = (WidthOfNameAndSurname * 3 - name.length() + 4) / 2 - 1;
    cout << string(WidthOfNameAndSurname * 3, '\\') << endl;
    for (int i = 0; i < 3; i++)
        cout << '*' << string(WidthOfNameAndSurname * 3 - 2, ' ') << '*' << endl;
    cout << '*' << string(whiteSpace, ' ') << name << string(whiteSpace, ' ') << '*' << endl;
    for (int i = 0; i < 3; i++)
        cout << '*' << string(WidthOfNameAndSurname * 3 - 2, ' ') << '*' << endl;
    cout << string(WidthOfNameAndSurname * 3, '/') << endl;
}

bool MenuOptions()
{
    return UserInput("Pasirinkite norimą funkciją", "Pažymių skaičiuoklė - 1\nVartotojo vadovas - 2");
}

void Instrukcions()
{
    cout << string(WidthOfNameAndSurname * 3, '\\') << endl
         << endl;
    cout << "1. Paleidus programa iskarto pradedamas duomenu ivedimas: Vardas Pavarde n - pazymiu ir egzamino pazymis." << endl;
    cout << "2. Paskutinis skaitmuo nuolatos laikomas egzamino pazymiu" << endl;
    cout << "3. Norint, kad programa sugeneruotu atsitiktinius skaicius uztenka kaip pazymi parasyti 0" << endl;
    cout << "4. Sekmingai ivedus asmeni, programa automatiskai klausia antro asmens. Norint baigti duomenu ivedima uztenka parasyti - 'stop' arba 'baigti'" << endl;
    cout << endl
         << "Norint iseiti is vartotojo vadovo parasykite - exit" << endl;
    string userInput;

    do
    {
        cin >> userInput;
    } while (userInput != "exit");
}

void StartProgram()
{
    while (true)
    {
        PrintWelcomeText();
        auto selectedOption = MenuOptions();
        if (selectedOption)
        {
            break;
        }
        else
        {
            Clear();
            Instrukcions();
        }
    }
}

bool AskReadFromFile()
{
    return UserInput("Skaityti is failo?", "Taip - 1, Rankinis įvedimas - 2");
}

bool UserInput(string question, string choice)
{
    Clear();
    int userInput;
    cout << endl << question << endl;

    do
    {
        cout << choice << endl;
        cin >> userInput;
    } while (!(userInput == 1 || userInput == 2));

    return userInput == 1;
}

bool OutputToFile()
{
    return UserInput("Įrašyti duomenys į failą?", "Taip - 1, Ne - 2");
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

bool AskIfFinalGradeIsMean()
{
    return UserInput("Skaičiuoti:", "Vidurki - 1, mediana - 2");
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
                SaveData(ValidateData(rawData));
            }
            break;
        }

        rawData.push_back(tempData);

        if (cin.get() == '\n')
        {
            SaveData(ValidateData(rawData));
            rawData.clear();
            cout << "Kito asments duomenys:" << endl;
        }
    }
    return students;
}

void PrintResult(vector<Student> localStudents, bool isMean)
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