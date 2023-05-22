#include "anduin.h"
#include "battle.h"
#include "io.h"
#include <string>

Anduin::Anduin(Battle* battle): Hero("Anduin", 40, 50, 10, battle) {}

Anduin::~Anduin() {}

void Anduin::castHolyNova(Monster* monster) {
    int spellDamage = 10;
    int costMP = 10;
    if (this->MP < costMP) {
        displayText(this->battle, "Not enough mana.");
        return;
    }

    monster->underAttacked(spellDamage);
    this->MP -= costMP;
    
    int restoreHP = this->HPRegen; //回復量為 Anduin 的 HP Regen
    this->battle->getHero1()->heal(restoreHP);
    this->battle->getHero2()->heal(restoreHP);
    this->battle->getHero3()->heal(restoreHP);

    string display = this->name + " spends " + to_string(costMP) + " mana casting \"Holy Nova\" on the enemy, causing " + to_string(spellDamage) + " damage and healing all heros "+ to_string(restoreHP) +"HP.";

    displayText(this->battle, display);
}

void Anduin::castClarity() {
    int restoreMP = 20;

    this->battle->getHero1()->restoreMana(restoreMP);
    this->battle->getHero2()->restoreMana(restoreMP);
    this->battle->getHero3()->restoreMana(restoreMP);

    string display = "All heros restore 20 mana.";

    displayText(this->battle, display);
}

void Anduin::revive() {
    string display1 = "Which hero do you want to revive?\n1. kirito\n2. anduin\n3. yasuo";
    displayText(this->battle, display1);

    string hero_name;
    int hero_num = getActionCommand(this->battle, 1, 3);
    if(hero_num == 1) {
        if(this->battle->getHero1()->isDead()) {
            this->battle->getHero1()->heal(1000);
        }
        hero_name = this->battle->getHero1()->getName();
    }
    else if(hero_num == 2) {
        if(this->battle->getHero2()->isDead()) {
            this->battle->getHero2()->heal(1000);
        }
        hero_name = this->battle->getHero2()->getName();
    }
    else if(hero_num == 3) {
        if(this->battle->getHero3()->isDead()) {
            this->battle->getHero3()->heal(1000);
        }
        hero_name = this->battle->getHero3()->getName();
    }

    string display = hero_name + " was resurrected.\n";
    displayText(this->battle, display);
}

void Anduin::action() {
    displayText(this->battle, this->name + " 's turn.");
    pressEntertoContinue();
    
    string display = this->name + " wants to ....\n\n" + 
        "1. cast \"Holy Nova\"\n" + //花費 10 點 MP，對 monster 造成 10 點傷害，並回復所有英雄的 HP，回復量為 Anduin 的 HP Regen。
        "2. cast \"Clarity\"\n" + //回復所有英雄 20 點 MP。
        "3. revive\n" + //選擇一位英雄，如果該英雄已經死亡，將該英雄恢復至滿血。
        "4. heal\n" + //回復自身 HP，回復量為 Anduin 的兩倍 HP Regen。
        "5. escape\n" + //Anduin HP 歸零。
        "(please key in number then Enter)";
    displayText(this->battle, display);
    int actionNumber = getActionCommand(this->battle, 1, 5);

    switch (actionNumber)
    {
    case 1:
        this->castHolyNova(this->battle->getMonster());
        break;
    case 2:
        this->castClarity();
        break;
    case 3:
        this->revive();
        break;
    case 4:
        this->heal(2*this->HPRegen);
        break;
    case 5:
        this->escape();
        break;
    default:
        break;
    }

    pressEntertoContinue();
}