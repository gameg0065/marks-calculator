#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "readAndPrint.h"
#include "randomGenerator.h"

using namespace std;

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
    cout << endl
         << question << endl;

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

bool AskIfFinalGradeIsMean()
{
    return UserInput("Skaičiuoti:", "Vidurki - 1, mediana - 2");
}
