#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Race;
class Shade;
class Drow; 
class Vampire;
class Troll;
class Goblin;

class Human : public Enemy{
    public:
    Human();
    void beAttacked(Race& r, Board& b) override;
    void attack(Shade& s) override;
    void attack(Drow& d) override;
    void attack(Vampire& v) override;
    void attack(Troll& t) override;
    void attack(Goblin& g) override;
    void die(Board& board) override;
};
#endif
