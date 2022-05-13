#include "drow.h"
#include "enemy.h"
#include "merchant.h"
#include "dragon.h"
#include "elf.h"
#include "human.h"
#include "halfling.h"
#include "orc.h"
#include "dwarf.h"
#include <math.h>

Drow::Drow()
    : Race{ "drow", 150, 25, 15 }
{}

void Drow::beAttacked(Enemy& e) {
    e.attack(*this);
}

void Drow::attack(Merchant& m, Board& b) {
    int damage = ceil((100.0/(100.0 + m.getDef()))) * atk;
    m.setHp(m.getHp() - damage);

    if(m.getHp() <= 0){
        m.die(b);
    }
}

void Drow::attack(Dragon& d, Board& b) {
    int damage = ceil((100.0/(100.0 + d.getDef()))) * atk;
    d.setHp(d.getHp() - damage);

    if(d.getHp() <= 0){
        d.die(b);
    }
}

void Drow::attack(Elf& e, Board& b) {
    int damage = ceil((100.0/(100.0 + e.getDef()))) * atk;
    e.setHp(e.getHp() - damage);

    if(e.getHp() <= 0){
        e.die(b);
    }
}

void Drow::attack(Human& h, Board& b) {
    int damage = ceil((100.0/(100.0 + h.getDef()))) * atk;
    h.setHp(h.getHp() - damage);

    if(h.getHp() <= 0){
        h.die(b);
    }
}

void Drow::attack(Halfling& h, Board& b) {
    int damage = ceil((100.0/(100.0 + h.getDef()))) * atk;
    h.setHp(h.getHp() - damage);

    if(h.getHp() <= 0){
        h.die(b);
    }
}

void Drow::attack(Orc& o, Board& b) {
    int damage = ceil((100.0/(100.0 + o.getDef()))) * atk;
    o.setHp(o.getHp() - damage);

    if(o.getHp() <= 0){
        o.die(b);
    }
}

void Drow::attack(Dwarf& d, Board& b) {
    int damage = ceil((100.0/(100.0 + d.getDef()))) * atk;
    d.setHp(d.getHp() - damage);

    if(d.getHp() <= 0){
        d.die(b);
    }
}
