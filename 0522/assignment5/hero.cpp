#include "hero.h"
#include "battle.h"
#include "io.h"
#include <string>

Hero::Hero(string name, int maxHP, int maxMP, int HPRegen, Battle* battle) {
    this->name = name;
    this->maxHP = maxHP;
    this->maxMP = maxMP;
    this->HP = maxHP;
    this->MP = maxMP;
    this->HPRegen = HPRegen;
    this->battle = battle;
}

Hero::~Hero() {}

bool Hero::isDead() { return this->HP <= 0; }
void Hero::underAttacked(int damage) { 
    this->HP -= damage;
    if (this->isDead()) {
        this->HP = 0;
    }
}

string Hero::getName() { return this->name; }
int Hero::getHP() { return this->HP; }
int Hero::getMP() { return this->MP; }
int Hero::getMaxHP() { return this->maxHP; }
int Hero::getMaxMP() { return this->maxMP; }
int Hero::getHPRegen() { return this->HPRegen; }

void Hero::escape() { 
    this->HP = 0; 
    string display = this->name + " ran away!!";
    displayText(this->battle, display);
}

void Hero::heal(int healingAmount) {
    this->HP += healingAmount;
    if (this->HP > this->maxHP) {
        this->HP = this->maxHP;
    }

    string display = this->name + " restore " + to_string(healingAmount) + " HP.";
    displayText(this->battle, display);
}

void Hero::restoreMana(int manaAmount) {
    this->MP += manaAmount;
    if (this->MP > this->maxMP) {
        this->MP = this->maxMP;
    }

    string display = this->name + " restore " + to_string(manaAmount) + " MP.";
    displayText(this->battle, display);
}