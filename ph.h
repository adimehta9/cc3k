#ifndef PH_H
#define PH_H
#include "effects.h"
#include <memory>

class PH: public Effects{
public:
    PH();
    int calcAtk() const override;
    int calcDef() const override;
    int calcHp() const override;
};

#endif
