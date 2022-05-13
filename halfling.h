#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

class Race;
class Shade;
class Drow; 
class Vampire;
class Troll;
class Goblin;

class Halfling : public Enemy {
    public:
    Halfling();
    void beAttacked(Race& r, Board& b) override;
    void attack(Shade& s) override;
    void attack(Drow& d) override;
    void attack(Vampire& v) override;
    void attack(Troll& t) override;
    void attack(Goblin& g) override;
};
#endif
