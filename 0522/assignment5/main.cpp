#define WINDOWS

#include "battle.h"
#include "yasuo.h"
#include "kirito.h"
#include "anduin.h"

using namespace std;

int main() {
    Battle *battle = new Battle();
    battle->addHero(new Kirito(battle));
    battle->addHero(new Anduin(battle));
    battle->addHero(new Yasuo(battle));
    battle->setMonster(new Monster("Boss", 200, battle));

    battle->playOpenningAnimation();
    battle->start();
    delete battle;

    return 0;
}
