#ifndef ELF_H
#define ELF_H
#include "enemy.h"

class Race;
class Shade;
class Drow; 
class Vampire;
class Troll;
class Goblin;

class Elf : public Enemy {
    public:
    Elf();
    void beAttacked(Race &, Board& b) override;
    void attack(Shade &) override;
    void attack(Drow &) override;
    void attack(Vampire &) override;
    void attack(Troll &) override;
    void attack(Goblin &) override;
};
#endif
