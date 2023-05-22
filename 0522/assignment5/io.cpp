#define WINDOWS

#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif
#include "io.h"
#include "battle.h"
#include <fstream>
#include <string>


void printSpace(int spaceNumber);
void showBanner(Battle* battle);
void showName(Battle* battle, int tab1, int tab2, int tab3, int tab4, int tab5);
void showHP(Battle* battle, int tab1, int tab2, int tab3, int tab4, int tab5);
void showMP(Battle* battle, int tab1, int tab2, int tab3, int tab4, int tab5);

void cleanScreen() {
#ifdef LINUX
    system("clear");
#endif
#ifdef WINDOWS
    system("cls");
#endif
}

void pressEntertoContinue() {
#ifdef LINUX
    cout << "Press any key to continue..." << endl;
    cin.get();
#endif
#ifdef WINDOWS
    system("pause");
#endif
}

void sleep(int millisecond) {
#ifdef LINUX
    usleep(millisecond*1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
#ifdef WINDOWS
    Sleep(millisecond);
#endif
}

void playGameCG(string filePath) {
    fstream file;
    string line;

    cleanScreen();
    file.open(filePath);
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void printSpace(int spaceNumber) {
    for (int i=0; i<spaceNumber; i++) {
        cout << ' ';
    }
}

void showName(Battle* battle, int tab1, int tab2, int tab3, int tab4, int tab5) {
    printSpace(tab1);
    cout << battle->getHero1()->getName();
    printSpace(tab2 - battle->getHero1()->getName().size());
    cout << battle->getHero2()->getName();
    printSpace(tab3 - battle->getHero2()->getName().size());
    cout << battle->getHero3()->getName();
    printSpace(tab4 - battle->getHero3()->getName().size());
    cout << battle->getMonster()->getName();
    printSpace(tab5 - battle->getMonster()->getName().size());
    cout << endl;
}

void showHP(Battle* battle, int tab1, int tab2, int tab3, int tab4, int tab5) {
    printSpace(tab1 - 4);
    string HPString = "HP: " + to_string(battle->getHero1()->getHP()) + "/" + to_string(battle->getHero1()->getMaxHP());
    cout << HPString;
    printSpace(tab2 - HPString.size());
    HPString = "HP: " + to_string(battle->getHero2()->getHP()) + "/" + to_string(battle->getHero2()->getMaxHP());
    cout << HPString;
    printSpace(tab3 - HPString.size());
    HPString = "HP: " + to_string(battle->getHero3()->getHP()) + "/" + to_string(battle->getHero3()->getMaxHP());
    cout << HPString;
    printSpace(tab4 - HPString.size());
    HPString = "HP: " + to_string(battle->getMonster()->getHP()) + "/" + to_string(battle->getMonster()->getMaxHP());
    cout << HPString;
    printSpace(tab5 - HPString.size() + 4);
    cout << endl;
}

void showMP(Battle* battle, int tab1, int tab2, int tab3, int tab4, int tab5) {
    printSpace(tab1 - 4);
    string MPString = "MP: " + to_string(battle->getHero1()->getMP()) + "/" + to_string(battle->getHero1()->getMaxMP());
    cout << MPString;
    printSpace(tab2 - MPString.size());
    MPString = "MP: " + to_string(battle->getHero2()->getMP()) + "/" + to_string(battle->getHero2()->getMaxMP());
    cout << MPString;
    printSpace(tab3 - MPString.size());
    MPString = "MP: " + to_string(battle->getHero3()->getMP()) + "/" + to_string(battle->getHero3()->getMaxMP());
    cout << MPString;
    printSpace(tab4 - MPString.size() + tab5 + 4);
    cout << endl;
}

void showBanner(Battle* battle) {
    int tab1 = 20;
    int tab2 = 22;
    int tab3 = 29;
    int tab4 = 70;
    int tab5 = 43;

    showName(battle, tab1, tab2, tab3, tab4, tab5);
    showHP(battle, tab1, tab2, tab3, tab4, tab5);
    showMP(battle, tab1, tab2, tab3, tab4, tab5);
    cout << "    ************************************************************************************************************************************************************************************" << endl;
}


void displayText(Battle* battle, string text) {
    string path = "animation/game/0.txt";
    int length = text.size();

    playGameCG(path);
    showBanner(battle);
    for (int i=0; i<length; i++) {
        cout << text[i];
        sleep(20);
    }
    cout << endl;
}

void playEachLineCG(string filePath, int millisecond, int totalLineNumber) {
    fstream file;

    for (int lineNumber=0; lineNumber<totalLineNumber; lineNumber++) {
        cleanScreen();
        string line;
        file.open(filePath);
        for (int i=lineNumber; i>=0; i--) {
            getline(file, line);
            cout << line << endl;
        }
        file.close();
        sleep(20);
    }
}

int getActionCommand(Battle* battle, int lowerBound, int upperBound) {
    int number = 0;
    // try {
        string input = "";
        cin >> input;
        number = stoi(input);
        if (number < lowerBound || number > upperBound) {
            throw out_of_range("stoi: out of range");
        }
    // } catch (invalid_argument& e) {

    // } catch (out_of_range& e) {
        
    // }

    return number;
}