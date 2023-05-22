#ifndef __KIRITO_H
#define __KIRITO_H
#include "hero.h"
#include "monster.h"

class Battle;

class Kirito: public Hero {
private:

public:
    Kirito(Battle* Battle);
    ~Kirito();
    void castStarburstStream(Monster* monster);
    void playStarburstStreamAnimation();
    void action();
};

#endif