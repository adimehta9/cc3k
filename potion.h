#ifndef POTION_H
#define POTION_H
#include "gameobject.h"


class Potion : public GameObject {
public:
    Potion(std::string desc);
    virtual int calcAtk() const = 0;
    virtual int calcDef() const = 0;
    virtual int calcHp() const = 0;
};


#endif
