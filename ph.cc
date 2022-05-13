#include "ph.h"
#include "potion.h"

PH::PH()
    : Effects{ 0, 0, -10, true, "PH" }
{}

int PH::calcAtk() const {
    return comp->calcAtk() + getAtkMod();
}

int PH::calcDef() const {
    return comp->calcDef() + getDefMod();
}

int PH::calcHp() const{
    return comp->calcHp() + getHpMod();
}
