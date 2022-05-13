#include "gold.h"

Gold::Gold(int val, bool dragonHoard)
	: GameObject{ "gold" }, val{ val }, dragonHoard{ dragonHoard }
{}

int Gold::getGold() const {
	return val;
}
