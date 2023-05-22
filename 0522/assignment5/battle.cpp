#include "battle.h"
#include "io.h"
#include <string>

Battle::Battle() {
    this->hero1 = NULL;
    this->hero2 = NULL;
    this->hero3 = NULL;
    this->monster = NULL;
}

Battle::~Battle() {
    delete this->hero1;
    delete this->hero2;
    delete this->hero3;
    delete this->monster;
}

bool Battle::isEnded() {
    return (this->hero1->isDead() && this->hero2->isDead() && this->hero3->isDead()) || this->monster->isDead();
}

void Battle::playOpenningAnimation() {
    string path = "animation/start/";
    int frameNumber = 3;

    for (int frame=0; frame<frameNumber; frame++) {
        playGameCG(path + to_string(frame) + ".txt");
        sleep(1000);
    }
    pressEntertoContinue();
}

void Battle::playGameOverAnimation() {
    playGameCG("animation/gameover/0.txt");
    sleep(1000);
    playGameCG("animation/gameover/1.txt");
    sleep(1000);
    cleanScreen();
    sleep(2000);
    playGameCG("animation/gameover/2.txt");
}

void Battle::playWinAnimation() {
    playGameCG("animation/win/0.txt");
    sleep(200);
    playGameCG("animation/win/1.txt");
    sleep(200);
    playGameCG("animation/win/2.txt");
    sleep(200);
    playGameCG("animation/win/3.txt");
    sleep(200);
    playGameCG("animation/win/4.txt");
    sleep(200);
    cleanScreen();
    sleep(1000);
    playGameCG("animation/win/5.txt");
    sleep(50);
    playGameCG("animation/win/6.txt");
    sleep(1000);
    playGameCG("animation/win/7.txt");
}

void Battle::playGameStartAnimation() {
    playEachLineCG("animation/game/0.txt", 20, 35);
    pressEntertoContinue();
}

void Battle::start() {
    this->playGameStartAnimation();
    while(!this->isEnded()) {
        if (!this->hero1->isDead()) {
            this->hero1->action();
        }
        if (this->isEnded()) break;

        if (!this->hero2->isDead()) {
            this->hero2->action();
        }
        if (this->isEnded()) break;

        if (!this->hero3->isDead()) {
            this->hero3->action();
        }
        if (this->isEnded()) break;

        this->monster->action();
    }

    if (this->monster->isDead()) {
        this->playWinAnimation();
    } else {
        this->playGameOverAnimation();
    }
}


void Battle::addHero(Hero* hero) {
    if (!this->hero1) {
        this->hero1 = hero;
    } else if (!this->hero2) {
        this->hero2 = hero;
    } else if (!this->hero3) {
        this->hero3 = hero;
    }
}

void Battle::setMonster(Monster* monster) { this->monster = monster; }
Monster* Battle::getMonster() { return this->monster; }
Hero* Battle::getHero1() { return this->hero1; }
Hero* Battle::getHero2() { return this->hero2; }
Hero* Battle::getHero3() { return this->hero3; }
