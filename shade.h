#ifndef SHADE_H
#define SHADE_H
#include "race.h"

class Enemy;
class Merchant;
class Dragon;
class Elf;
class Human;
class Halfling;
class Orc;
class Dwarf;

class Shade : public Race {
public:
	Shade();
	void beAttacked(Enemy& e) override;
	void attack(Merchant& m, Board& b) override;
	void attack(Dragon& d, Board& b) override;
	void attack(Elf& e, Board& b) override;
	void attack(Human& h, Board& b) override;
	void attack(Halfling& h, Board& b) override;
	void attack(Orc& o, Board& b) override;
	void attack(Dwarf& d, Board& b) override;
};

#endif
