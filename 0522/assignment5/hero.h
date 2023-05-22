#ifndef __HERO_H
#define __HERO_H

#include <iostream>
#include "monster.h"

using namespace std;

class Battle;

class Hero {
protected:
    string name;
    int HP;
    int MP;
    int maxHP;
    int maxMP;
    int HPRegen;
    Battle* battle;

public:
    Hero(string name, int maxHP, int maxMP, int HPRegen, Battle* battle);
    virtual ~Hero();

    bool isDead();
    string getName();
    int getHP();
    int getMP();
    int getMaxHP();
    int getMaxMP();
    int getHPRegen();


    virtual void underAttacked(int damage);
    virtual void escape();
    virtual void heal(int healingAmount);
    virtual void restoreMana(int manaAmount);
    virtual void action() = 0;
};

#endif