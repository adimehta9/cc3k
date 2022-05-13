#include "ba.h"
#include "potion.h"

BA::BA()
    : Effects{ 5, 0, 0, false, "BA" }
{}

int BA::calcAtk() const {
    return comp->calcAtk() + getAtkMod();
}

int BA::calcDef() const {
    return comp->calcDef() + getDefMod();
}

int BA::calcHp() const{
    return comp->calcHp() + getHpMod();
}
