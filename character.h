#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"

class Character : public GameObject {
protected:
	int hp;
	int atk;
	int def;
public:
	Character(std::string desc, int hp, int atk, int def);
	bool isDead();
	void setHp(int maxHp);
	int getHp();
	int getAtk();
	int getDef();
};

#endif
