#ifndef BA_H
#define BA_H
#include "effects.h"
#include <memory>


class BA: public Effects{
public:
    BA();
    int calcAtk() const override;
    int calcDef() const override;
    int calcHp() const override;
};

#endif
