#include "wd.h"
#include "potion.h"

WD::WD()
    : Effects{ 0, -5, 0, false, "WD" }
{}

int WD::calcAtk() const {
    return comp->calcAtk() + getAtkMod();
}

int WD::calcDef() const {
    return comp->calcDef() + getDefMod();
}

int WD::calcHp() const{
    return comp->calcHp() + getHpMod();
}
