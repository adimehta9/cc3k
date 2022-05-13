#include "wa.h"
#include "potion.h"

WA::WA()
    : Effects{-5, 0, 0, false, "WA" }
{}

int WA::calcAtk() const {
    return comp->calcAtk() + getAtkMod();
}

int WA::calcDef() const {
    return comp->calcDef() + getDefMod();
}

int WA::calcHp() const{
    return comp->calcHp() + getHpMod();
}
