#include "race.h"
#include "base.h"
#include "board.h"
#include "passage.h"
#include "effects.h"
#include "gold.h"
#include <iostream> // REMOVE
#include <string>
#include <memory>
#include <utility>

using namespace std;

Race::Race(string desc, int hp, int atk, int def)
	: Character{desc, hp, atk, def }, maxHp{ hp },
	  potions{static_cast<shared_ptr<Potion>>(make_shared<Base>())}, gold{ 0 },
	  onObject{ false }
{}

void Race::move(int x, int y, Board& b) {
	pair <int, int> playerCoords = b.getCoords(this);
	shared_ptr<GameObject> next = b.getObject(x, y);

	if (next != nullptr && next->getDesc() == "doorway") {
		x += x - playerCoords.first;
		y += y - playerCoords.second;
		next = b.getObject(x, y);
	}

	if (next != nullptr && next->getDesc() == "stairway") {
		b.nextLevel();
		return;
	}

	if (next != nullptr && next->getDesc() == "gold") {
		shared_ptr<Gold> g = static_pointer_cast<Gold>(next);
		if (!g->dragonHoard) {
			gold += g->getGold();
		}
	}
	
	b.setObject(x, y, b.player);
	b.setChar(x, y, '@');

	if (onObject) {
		b.setObject(playerCoords.first, playerCoords.second, b.holder);
		if (b.holder->getDesc() == "passage") {
			b.setChar(playerCoords.first, playerCoords.second, '#');
		} else if (b.holder->getDesc() == "gold") {
			b.setChar(playerCoords.first, playerCoords.second, 'G');
		}
		b.holder = nullptr;
		onObject = false;
	} else {
		b.setObject(playerCoords.first, playerCoords.second, nullptr);
		b.setChar(playerCoords.first, playerCoords.second, '.');
	}

	if (next != nullptr && next->getDesc() == "passage") {
		onObject = true;
		b.holder = next;
	} else if (next != nullptr && next->getDesc() == "gold") {
		shared_ptr<Gold> g = static_pointer_cast<Gold>(next);
		if (g->dragonHoard) {
			onObject = true;
			b.holder = next;
		}
	}
}

void Race::usePotion(shared_ptr<Effects> potion, Board& b) {
	pair <int, int> pCoords = b.getCoords(potion.get());
	b.setObject(pCoords.first, pCoords.second, nullptr);
	b.setChar(pCoords.first, pCoords.second, '.');
	if (hp + potion->getHpMod() <= maxHp) {
		hp += potion->getHpMod();
	}
	atk += potion->getAtkMod();
	def += potion->getDefMod();
	if (!potion->isPermanent()) {
		potion->setComponent(potions);
		potions = potion;
	}
}

void Race::removePotions() {
	atk -= potions->calcAtk();
	def -= potions->calcDef();
	potions = make_shared<Base>();
}

int Race::getGold() {
	return gold;
}
