#ifndef WA_H
#define WA_H
#include "effects.h"
#include <memory>


class WA: public Effects{
public:
    WA();
    int calcAtk() const override;
    int calcDef() const override;
    int calcHp() const override;
};

#endif
