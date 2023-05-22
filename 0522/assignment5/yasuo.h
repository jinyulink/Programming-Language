#ifndef __YASUO_H
#define __YASUO_H
#include "hero.h"
#include "monster.h"

using namespace std;

class Battle;

class Yasuo: public Hero {
private:
    int shield;

public:
    Yasuo(Battle* Battle);
    ~Yasuo();
    void castSorye_ge_ton(Monster* monster);
    void underAttacked(int damage);
    void action();
};

#endif