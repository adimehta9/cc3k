#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include <memory>

class Race;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Board;

class Enemy : public Character {
	char c;
public:
	Enemy(int hp, int atk, int def, char c);
	virtual void checkRadius(Board& board);
	virtual void die(Board& board);
	virtual void move(Board& b, std::shared_ptr<Enemy> e) const;
	virtual void beAttacked(Race& r, Board& b) = 0;
	virtual void attack(Shade& s) = 0;
	virtual void attack(Drow& d) = 0;
	virtual void attack(Vampire& v) = 0;
	virtual void attack(Troll& t) = 0;
	virtual void attack(Goblin& g) = 0;
};

#endif
