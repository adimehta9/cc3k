#include "troll.h"
#include "dwarf.h"
#include "race.h"
#include "dragon.h"
#include "merchant.h"
#include "elf.h"
#include "human.h"
#include "halfling.h"
#include "orc.h"
#include "dwarf.h"
#include <cstdlib>
#include <ctime>
#include <math.h>

Troll::Troll() 
    : Race{"troll", 120, 25, 15}
{}

void Troll::beAttacked(Enemy &e) {
    e.attack(*this);
}

void Troll::attack(Merchant &m, Board& b) {
    int damage = ceil((100.0/(100.0 + m.getDef())) * atk);
    m.setHp(m.getHp() - damage);

    if(m.getHp() <= 0){
        m.die(b);
    }

    hp += 5;
    if(hp > 120){
        hp = 120;
    }
}

void Troll::attack(Dragon &d, Board& b) {
    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    d.setHp(d.getHp() - damage);

    if(d.getHp() <= 0){
        d.die(b);
    }

    hp += 5;
    if(hp > 120){
        hp = 120;
    }
}

void Troll::attack(Elf &e, Board& b) {
    int damage = ceil((100.0/(100.0 +e.getDef())) * atk);
    e.setHp(e.getHp() - damage);

    if(e.getHp() <= 0){
        e.die(b);
    }

    hp += 5;
    if(hp > 120){
        hp = 120;
    }
}

void Troll::attack(Human &h, Board& b) {
    int damage = ceil((100.0/(100.0 + h.getDef())) * atk);
    h.setHp(h.getHp() - damage);

    if(h.getHp() <= 0){
        h.die(b);
    }

    hp += 5;
    if(hp > 120){
        hp = 120;
    }
}

void Troll::attack(Halfling &h, Board& b) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + h.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        h.setHp(h.getHp() - damage);
    }

    if(h.getHp() <= 0){
        h.die(b);
    }

    hp +=5;
    if(hp > 120){
        hp = 120;
    }
}

void Troll::attack(Orc &o, Board& b) {
    int damage = ceil((100.0/(100.0 + o.getDef())) * atk);
    o.setHp(o.getHp() - damage);

    if(o.getHp() <= 0){
        o.die(b);
    }

    hp += 5;
    if(hp > 120){
        hp = 120;
    }
}

void Troll::attack(Dwarf &d, Board& b) {
    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    d.setHp(d.getHp() - damage);

    if(d.getHp() <= 0){
        d.die(b);
    }

    hp += 5;
    if(hp > 120){
        hp = 120;
    }
}
