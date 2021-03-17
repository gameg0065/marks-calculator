#ifndef USERINTERACTION_H
#define USERINTERACTION_H
#include "variables.h"

void Clear();
bool MenuOptions();
void StartProgram();
bool UserInput(string question, string choice);
bool AskReadFromFile();
void PrintWelcomeText();
bool AskIfFinalGradeIsMean();
bool AskOutputToFile();

#endif