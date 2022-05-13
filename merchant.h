#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Race;
class Shade;
class Drow; 
class Vampire;
class Troll;
class Goblin;

class Merchant : public Enemy{
public:
    Merchant();
    void beAttacked(Race &, Board& b) override;
    void attack(Shade &) override;
    void attack(Drow &) override;
    void attack(Vampire &) override;
    void attack(Troll &) override;
    void attack(Goblin &) override;
    void die(Board& board) override;
    void checkRadius(Board& board) override;
};
#endif
