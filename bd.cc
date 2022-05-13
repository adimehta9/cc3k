#include "bd.h"
#include "potion.h"

BD::BD()
    : Effects{ 0, 5, 0, false, "BD" }
{}

int BD::calcAtk() const {
    return comp->calcAtk() + getAtkMod();
}

int BD::calcDef() const {
    return comp->calcDef() + getDefMod();
}

int BD::calcHp() const{
    return comp->calcHp() + getHpMod();
}
