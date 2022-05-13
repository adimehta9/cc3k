#include "vampire.h"
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

Vampire::Vampire()
    : Race{"vampire", 50, 25, 25}
{}

void Vampire::beAttacked(Enemy &e) {
    e.attack(*this);
}

void Vampire::attack(Merchant &m, Board& b)  {
    int damage = ceil((100.0/(100.0 + m.getDef())) * atk);
    m.setHp(m.getHp() - damage);
    hp += 5;

    if(m.getHp() <= 0){
        m.die(b);
    }
}

void Vampire::attack(Dragon &d, Board& b) {
    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    d.setHp(d.getHp() - damage);
    hp += 5;

    if(d.getHp() <= 0){
        d.die(b);
    }
}

void Vampire::attack(Elf &e, Board& b) {
    int damage = ceil((100.0/(100.0 + e.getDef()))) * atk;
    e.setHp(e.getHp() - damage);
    hp += 5;

    if(e.getHp() <= 0){
        e.die(b);
    }
}

void Vampire::attack(Human &h, Board& b) {
    int damage = ceil((100.0/(100.0 + h.getDef())) * atk);
    h.setHp(h.getHp() - damage);
    hp += 5;

    if(h.getHp() <= 0){
        h.die(b);
    }
}

void Vampire::attack(Halfling &h, Board& b) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + h.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        h.setHp(h.getHp() - damage);
        hp += 5;
    }

    if(h.getHp() <= 0){
        h.die(b);
    }
}

void Vampire::attack(Orc &o, Board& b) {
    int damage = ceil((100.0/(100.0 + o.getDef())) * atk);
    o.setHp(o.getHp() - damage);
    hp += 5;

    if(o.getHp() <= 0){
        o.die(b);
    }
}

void Vampire::attack(Dwarf &d, Board& b) {
    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    d.setHp(d.getHp() - damage);
    hp -= 5;

    if(d.getHp() <= 0){
        d.die(b);
    }
}
