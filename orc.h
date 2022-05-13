#ifndef ORC_H
#define ORC_H
#include "enemy.h"

class Race;
class Shade;
class Drow; 
class Vampire;
class Troll;
class Goblin;

class Orc : public Enemy {
    public:
    Orc();
    void beAttacked(Race& r, Board& b) override;
    void attack(Shade& s) override;
    void attack(Drow& d) override;
    void attack(Vampire& v) override;
    void attack(Troll& t) override;
    void attack(Goblin& g) override;
};
#endif
