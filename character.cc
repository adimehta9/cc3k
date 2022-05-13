#include "character.h"
using namespace std;

Character::Character(string desc, int hp, int atk, int def)
	: GameObject{ desc }, hp { hp }, atk{ atk }, def{ def }
{}

bool Character::isDead() {
	return hp <= 0;
}

void Character::setHp(int newHp) {
	hp = newHp;
}

int Character::getHp() {
	return hp;
}

int Character::getAtk() {
	return atk;
}

int Character::getDef() {
	return def;
}
