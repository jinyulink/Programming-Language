#include "monster.h"
#include "battle.h"
#include "io.h"
#include <string>


Monster::Monster(string name, int maxHP, Battle* battle) {
    this->name = name;
    this->maxHP = maxHP;
    this->HP = maxHP;
    this->battle = battle;
    this->round = 0;
}

Monster::~Monster() {}

bool Monster::isDead() { return this->HP <= 0; }

string Monster::getName() { return this->name; }
int Monster::getHP() { return this->HP; }
int Monster::getMaxHP() { return this->maxHP; }

void Monster::underAttacked(int damage) {
    this->HP -= damage;
    if (this->isDead()) {
        this->HP = 0;
    }
}

void Monster::action(){
    this->round++;
    displayText(this->battle, this->name + " 's turn.");
    system("pause");

    if (this->round % 2) {
        int damage = 30;
        Hero* victom = NULL;
        this->playAttackAnimation();
        if (!this->battle->getHero3()->isDead()) {
            victom = this->battle->getHero3();
        } else if (!this->battle->getHero2()->isDead()) {
            victom = this->battle->getHero2();
        } else if (!this->battle->getHero1()->isDead()) {
            victom = this->battle->getHero1();
        }
        victom->underAttacked(damage);

        string display = this->name + " attacks " + victom->getName() + ", " + victom->getName() + " takes " + to_string(damage) + " damage.";
        displayText(this->battle, display);
    } else {
        int damage = 20;
        this->playAOEAnimation();
        this->battle->getHero3()->underAttacked(damage);
        this->battle->getHero2()->underAttacked(damage);
        this->battle->getHero1()->underAttacked(damage);

        string display = this->name + " cast AOE spell , all heros takes " + to_string(damage) + " damage.";
        displayText(this->battle, display);
    }
    system("pause");
}

void Monster::playAttackAnimation() {
    for (int i=0; i<5; i++) {
        playGameCG("animation/monster/attack/0.txt");
        sleep(50);
        playGameCG("animation/monster/attack/1.txt");
        sleep(50);
        playGameCG("animation/monster/attack/2.txt");
        sleep(50);
        playGameCG("animation/monster/attack/3.txt");
        sleep(50);
    }
    playGameCG("animation/monster/attack/0.txt");
    sleep(50);
    playGameCG("animation/monster/attack/4.txt");
    sleep(50);
    playGameCG("animation/monster/attack/5.txt");
    sleep(50);
    playGameCG("animation/monster/attack/6.txt");
    sleep(50);
    playGameCG("animation/monster/attack/7.txt");
    sleep(50);
    playGameCG("animation/monster/attack/8.txt");
    sleep(1000);
    playGameCG("animation/monster/attack/9.txt");
    sleep(50);
    playGameCG("animation/monster/attack/10.txt");
    sleep(50);
    playGameCG("animation/monster/attack/0.txt");
    sleep(1000);
}

void Monster::playAOEAnimation() {
    for (int i=0; i<10; i++) {
        playGameCG("animation/monster/aoe/0.txt");
        sleep(50);
        playGameCG("animation/monster/aoe/1.txt");
        sleep(50);
        playGameCG("animation/monster/aoe/2.txt");
        sleep(50);
    }
    playGameCG("animation/monster/aoe/3.txt");
    sleep(50);
    playGameCG("animation/monster/aoe/4.txt");
    sleep(2000);
    playGameCG("animation/monster/aoe/5.txt");
    sleep(1000);
}