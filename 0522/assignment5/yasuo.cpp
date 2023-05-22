#include "yasuo.h"
#include "battle.h"
#include "io.h"
#include <string>

Yasuo::Yasuo(Battle* battle): Hero("Yasuo", 30, 0, 6, battle) {}

Yasuo::~Yasuo() {}

void Yasuo::castSorye_ge_ton(Monster* monster) {
    int spellDamage = 25;
    
    monster->underAttacked(spellDamage);
    string display = this->name + " casting \"Sorye ge ton\" on the enemy, causing " + to_string(spellDamage) + " damage.";
    
    displayText(this->battle, display);
} 

void Yasuo::underAttacked(int damage) {
    if(damage >= this->shield) {
        damage -= this->shield;
        this->shield = 0;
    }
    else {
        this->shield -= damage;
        damage = 0;
    }
    this->HP -= damage;
    if (this->isDead()) {
        this->HP = 0;
    }
}

void Yasuo::action() {
    displayText(this->battle, this->name + " 's turn.");
    pressEntertoContinue();
    
    if(this->shield != 10) {
        this->shield = 10;
    }

    string display = this->name + " wants to ....\n\n" + 
        "1. cast \"Sorye ge ton\"\n" + 
        "2. heal\n" + 
        "3. escape\n" + 
        "(please key in number then Enter)";
    displayText(this->battle, display);
    int actionNumber = getActionCommand(this->battle, 1, 4);

    switch (actionNumber)
    {
    case 1:
        this->castSorye_ge_ton(this->battle->getMonster());
        break;
    case 2:
        this->heal(this->HPRegen);
        break;
    case 3:
        this->escape();
        break;
    default:
        break;
    }

    pressEntertoContinue();
}