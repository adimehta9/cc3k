#ifndef EFFECTS_H
#define EFFECTS_H
#include "potion.h"
#include <memory>
using namespace std;

class Effects: public Potion{
protected:
    shared_ptr<Potion> comp;
    int atkMod;
    int defMod;
    int hpMod;
    bool permanent;

public:
    Effects(int atk, int def, int hp, bool perm, std::string desc);
    ~Effects() = 0;
    int getHpMod() const;
    int getAtkMod() const;
    int getDefMod() const;
    bool isPermanent() const;
    void setComponent(shared_ptr<Potion> comp);
};

#endif
