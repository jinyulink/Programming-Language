#include "kirito.h"
#include "battle.h"
#include "io.h"
#include <string>

Kirito::Kirito(Battle* battle): Hero("Kirito", 25, 14, 8, battle) {}

Kirito::~Kirito() {}    

void Kirito::castStarburstStream(Monster* monster) {
    int spellDamage = 30;
    int costMP = 5;
    if (this->MP < costMP) {
        displayText(this->battle, "Not enough mana.");
        return;
    }
    
    this->playStarburstStreamAnimation();
    monster->underAttacked(spellDamage);
    this->MP -= costMP;
    string display = this->name + " spends " + to_string(costMP) + " mana casting \"Starburst Stream\" on the enemy, causing " + to_string(spellDamage) + " damage.";
    
    displayText(this->battle, display);
}

void Kirito::playStarburstStreamAnimation() {
    cleanScreen();
    sleep(1000);
    playGameCG("animation/kirito/0.txt");
    sleep(500);
    playGameCG("animation/kirito/1.txt");
    sleep(1000);
    playGameCG("animation/kirito/2.txt");
    sleep(1000);
    playGameCG("animation/kirito/3.txt");
    sleep(500);
    playGameCG("animation/kirito/4.txt");
    sleep(500);
    playGameCG("animation/kirito/1.txt");
    sleep(500);
    playGameCG("animation/kirito/5.txt");
    sleep(1000);
    playGameCG("animation/kirito/4.txt");
    sleep(400);
    playGameCG("animation/kirito/6.txt");
    sleep(400);
    playGameCG("animation/kirito/7.txt");
    sleep(400);
    playGameCG("animation/kirito/1.txt");
    sleep(500);
    playGameCG("animation/kirito/8.txt");
    sleep(1000);
    playGameCG("animation/kirito/7.txt");
    sleep(300);
    playGameCG("animation/kirito/9.txt");
    sleep(300);
    playGameCG("animation/kirito/10.txt");
    sleep(300);
    playGameCG("animation/kirito/11.txt");
    sleep(1000);
}

void Kirito::action() {
    displayText(this->battle, this->name + " 's turn.");
    pressEntertoContinue();

    string display = this->name + " wants to ....\n\n" + 
        "1. cast \"Starburst Stream\"\n" + 
        "2. heal\n" + 
        "3. escape\n" + 
        "(please key in number then Enter)";
    displayText(this->battle, display);
    int actionNumber = getActionCommand(this->battle, 1, 4);

    switch (actionNumber)
    {
    case 1:
        this->castStarburstStream(this->battle->getMonster());
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