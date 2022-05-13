#ifndef WD_H
#define WD_H
#include "effects.h"
#include <memory>

class WD: public Effects{
public:
    WD();
    int calcAtk() const override;
    int calcDef() const override;
    int calcHp() const override;
};

#endif
