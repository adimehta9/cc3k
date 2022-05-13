#ifndef BOARD_H
#define BOARD_H
#include "chamber.h"
#include <memory>
#include <vector>

using namespace std;

class GameObject;
class Race;

const int BOARD_HEIGHT = 25;
const int BOARD_WIDTH = 79;

class Board {
private:
	shared_ptr<GameObject> game[BOARD_HEIGHT][BOARD_WIDTH];
	char charBoard[BOARD_HEIGHT][BOARD_WIDTH];
	shared_ptr<Chamber> chambers[5];
	int level;
	bool frozen;
	bool merchantHostile;
	// returns the square at index i in the chamberNo chamber
	shared_ptr<GameObject>& indexChamber(int chamberNo, int i) const;
	// returns a random empty square in a random chamber
	shared_ptr<GameObject>& randSquare() const;
public:
	shared_ptr<Race> player;
	shared_ptr<GameObject> holder;
	Board(ifstream& b, shared_ptr<Race> p);
	void showBoard() const;
	void spawn();
	void reset();
	void nextTurn();
	shared_ptr<GameObject> getObject(int x, int y) const;
	void setObject(int x, int y, shared_ptr<GameObject> obj);
	char getChar(int x, int y) const;
	void setChar(int x, int y, char c);
	// takes in a reference to a gameObject and returns the (x,y) coordinates
	// obj cannot be a reference to a nullptr
	pair <int, int> getCoords(const GameObject* obj) const;
	void nextLevel();
	int getLevel() const;
	void changeFrozen();
	bool isMerchantHostile() const;
	void changeMerchantHostile();
};

#endif
