#include "halfling.h"
#include "race.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <cstdlib>
#include <ctime>
#include <math.h>

Halfling::Halfling()
    : Enemy{ 100, 15, 20, 'L' }
    {}

void Halfling::beAttacked(Race& r, Board& b){
    r.attack(*this, b);
}

void Halfling::attack(Shade& s) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + s.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        s.setHp(s.getHp() - damage);
    }
}
void Halfling::attack(Drow& d) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        d.setHp(d.getHp() - damage);
    }
    
}
void Halfling::attack(Vampire& v) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + v.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        v.setHp(v.getHp() - damage);
    }
    
}
void Halfling::attack(Troll& t) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + t.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        t.setHp(t.getHp() - damage);
    }
    
}
void Halfling::attack(Goblin& g) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + g.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        g.setHp(g.getHp() - damage);
    }
    
}
