#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Race;
class Shade;
class Drow; 
class Vampire;
class Troll;
class Goblin;

class Dragon : public Enemy {
private:
    int hoardX;
    int hoardY;
    public:
    Dragon(int hoardX, int hoardY);
    void beAttacked(Race &, Board& b) override;
    void attack(Shade &) override;
    void attack(Drow &) override;
    void attack(Vampire &) override;
    void attack(Troll &) override;
    void attack(Goblin &) override;
    void die(Board& board) override;
    void move(Board& b, std::shared_ptr<Enemy> e) const override;
};
#endif
