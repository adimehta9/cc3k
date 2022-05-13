#ifndef BASE_H
#define BASE_H
#include "potion.h"

class Base: public Potion {
public:
    Base();
    int calcAtk() const override;
    int calcDef() const override;
    int calcHp() const override;
};


#endif
