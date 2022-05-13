#include "effects.h"
#include "potion.h"
#include "base.h"

Effects::Effects(int atk, int def, int hp, bool perm, string desc)
    : Potion{desc}, atkMod{atk}, defMod{def}, hpMod{hp}, permanent{perm}
{}

Effects::~Effects() {} ;

int Effects::getHpMod() const {
    return hpMod;
}

int Effects::getAtkMod() const {
    return atkMod;
}

int Effects::getDefMod() const {
    return defMod;
}

bool Effects::isPermanent() const {
    return permanent;
}

void Effects::setComponent(shared_ptr<Potion> comp) {
    this->comp = comp;
}
