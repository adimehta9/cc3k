#ifndef BD_H
#define BD_H
#include "effects.h"
#include <memory>

class BD: public Effects{
public:
    BD();
    int calcAtk() const override;
    int calcDef() const override;
    int calcHp() const override;
};

#endif
