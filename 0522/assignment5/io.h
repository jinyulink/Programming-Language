#ifndef __IO_H
#define __IO_H
#include <iostream>

using namespace std;

class Battle;

void cleanScreen();
void pressEntertoContinue();
void sleep(int millisecond);
void playGameCG(string filePath);
void playEachLineCG(string filePath, int millisecond, int totalLineNumber);
void displayText(Battle* battle, string text);
int getActionCommand(Battle* battle, int lowerBound, int upperBound);




#endif