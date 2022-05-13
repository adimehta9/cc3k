#include <cstdlib>
#include <ctime>
#include <math.h>
#include "dwarf.h"
#include "race.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Dwarf::Dwarf()
    : Enemy{ 100, 20, 30, 'W'}
{}

void Dwarf::beAttacked(Race& r, Board& b) {
    r.attack(*this, b);
}

void Dwarf::attack(Shade& s) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + s.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        s.setHp(s.getHp() - damage);
    }
}

void Dwarf::attack(Drow& d) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        d.setHp(d.getHp() - damage);
    }
}

void Dwarf::attack(Vampire& v) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + v.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        v.setHp(v.getHp() - damage);
    }
}

void Dwarf::attack(Troll& t) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + t.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        t.setHp(t.getHp() - damage);
    }
}

void Dwarf::attack(Goblin& g) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + g.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        g.setHp(g.getHp() - damage);
    }
}
