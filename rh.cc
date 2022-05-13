#include "rh.h"
#include "potion.h"

RH::RH()
    : Effects{0, 0, 10, true, "RH"}
{}

int RH::calcAtk() const {
    return comp->calcAtk() + getAtkMod();
}

int RH::calcDef() const {
    return comp->calcDef() + getDefMod();
}

int RH::calcHp() const{
    return comp->calcHp() + getHpMod();
}
