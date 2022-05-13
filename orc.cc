#include "orc.h"
#include "race.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <cstdlib>
#include <ctime>
#include <math.h>

Orc::Orc() 
    : Enemy{180, 30, 25, 'O'}
{}
void Orc::beAttacked(Race& r, Board& b){
    r.attack(*this, b);
}
void Orc::attack(Shade& s) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + s.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        s.setHp(s.getHp() - damage);
    }
}
void Orc::attack(Drow& d) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        d.setHp(d.getHp() - damage);
    }
}
void Orc::attack(Vampire& v) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + v.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        v.setHp(v.getHp() - damage);
    }
}
void Orc::attack(Troll& t) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + t.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        t.setHp(t.getHp() - damage);
    }
}
void Orc::attack(Goblin& g) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + g.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        g.setHp(g.getHp() - (damage * 1.5));
    }
}
