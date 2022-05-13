#include "dragon.h"
#include "race.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "gold.h"
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

Dragon::Dragon(int hoardX, int hoardY)
    : Enemy{ 150, 20, 20, 'D' }, hoardX{ hoardX }, hoardY{ hoardY }
{}

void Dragon::beAttacked(Race& r, Board& b) {
	r.attack(*this, b);
}

void Dragon::attack(Shade& s) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + s.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        s.setHp(s.getHp() - damage);
    }
}

void Dragon::attack(Drow& d) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        d.setHp(d.getHp() - damage);
    }
}

void Dragon::attack(Vampire& v) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + v.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        v.setHp(v.getHp() - damage);
    }
}

void Dragon::attack(Troll& t) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + t.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        t.setHp(t.getHp() - damage);
    }
}

void Dragon::attack(Goblin& g) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + g.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        g.setHp(g.getHp() - damage);
    }
}

void Dragon::die(Board& board) {
    pair <int, int> p = board.getCoords(this);
    shared_ptr<Gold> hoard = static_pointer_cast<Gold>(board.getObject(hoardX, hoardY));
    board.setObject(p.first, p.second, nullptr);
    board.setChar(p.first, p.second, '.');
    hoard->dragonHoard = false;
}

void Dragon::move(Board& b, std::shared_ptr<Enemy> e) const {

}
