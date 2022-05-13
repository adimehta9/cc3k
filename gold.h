#ifndef GOLD_H
#define GOLD_H
#include "gameobject.h"

class Gold : public GameObject {
		int val;

	public:
		bool dragonHoard;
		Gold(int val, bool dragonHoard);
		int getGold() const;
};
#endif
