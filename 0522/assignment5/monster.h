#ifndef __MONSTER_H
#define __MONSTER_H

#include <iostream>

using namespace std;

class Battle;

class Monster {
protected:
    string name;
    int HP;
    int maxHP;
    Battle* battle;
    int round;
public:
    Monster(string name, int maxHP, Battle* battle);
    ~Monster();

    bool isDead();
    string getName();
    int getHP();
    int getMaxHP();
    void underAttacked(int damage);
    void action();
    void playAttackAnimation();
    void playAOEAnimation();
};

#endif