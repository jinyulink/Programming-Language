#ifndef __BATTLE_H
#define __BATTLE_H

#include <iostream>
#include "hero.h"
#include "monster.h"

using namespace std;

class Battle {
private:
    Hero* hero1;
    Hero* hero2;
    Hero* hero3;
    Monster* monster;
    bool isEnded();
public:
    Battle();
    ~Battle();

    void playOpenningAnimation();
    void playGameOverAnimation();
    void playWinAnimation();
    void playGameStartAnimation();
    void start();

    void addHero(Hero* hero);
    void setMonster(Monster* monster);
    Monster* getMonster();
    Hero* getHero1();
    Hero* getHero2();
    Hero* getHero3();
};

#endif