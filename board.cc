#include "board.h"
#include "gameobject.h"
#include "chamber.h"
#include "stairway.h"
#include "wall.h"
#include "passage.h"
#include "doorway.h"
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"
#include "dragon.h"
#include "gold.h"
#include "race.h"
#include "troll.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

Board::Board(ifstream& b, shared_ptr<Race> p){
	chambers[0] = make_shared<Chamber>(0);
	chambers[1] = make_shared<Chamber>(1);
	chambers[2] = make_shared<Chamber>(2);
	chambers[3] = make_shared<Chamber>(3);
	chambers[4] = make_shared<Chamber>(4);
	player = p;
	frozen = false;
	merchantHostile = false;
	level = 0;

	// read in board
	vector<pair <int, int>> goldCoords = vector<pair <int, int>>();
	vector<pair <int, int>> dragonCoords = vector<pair <int, int>>();
	for (int i = 0; i < BOARD_HEIGHT; ++i) {
		string s;
		getline(b, s);
		stringstream ss{s};
		for (int j = 0; j < BOARD_WIDTH; ++j) {
			char c = ss.get();

			// update charBoard
			if (c >= '0' && c <= '5') {
				charBoard[i][j] = 'P';
			} else if (c >= '6' && c <= '9') {
				charBoard[i][j] = 'G';
			} else {
				charBoard[i][j] = c;
			}

			// update game
			if (c == '|' || c == '-') {
				game[i][j] = make_shared<Wall>();
			} else if (c == '#') {
				game[i][j] = make_shared<Passage>();
			} else if (c == '+') {
				game[i][j] = make_shared<Doorway>();
			} else if (c == '0') {
				game[i][j] = make_shared<RH>();
			} else if (c == '1') {
				game[i][j] = make_shared<BA>();
			} else if (c == '2') {
				game[i][j] = make_shared<BD>();
			} else if (c == '3') {
				game[i][j] = make_shared<PH>();
			} else if (c == '4') {
				game[i][j] = make_shared<WA>();
			} else if (c == '5') {
				game[i][j] = make_shared<WD>();
			} else if (c == '6') {
				game[i][j] = make_shared<Gold>(2, false);
			} else if (c == '7') {
				game[i][j] = make_shared<Gold>(1, false);
			} else if (c == '8') {
				game[i][j] = make_shared<Gold>(4, false);
			} else if (c == '9') {
				game[i][j] = make_shared<Gold>(6, true);
				bool dragonFound = false;
				for (int k = 0; k < dragonCoords.size(); ++k) {
					if (abs(i - dragonCoords[k].first) <= 1 && abs(j - dragonCoords[k].second) <= 1) {
						game[dragonCoords[k].first][dragonCoords[k].second] = make_shared<Dragon>(i, j);
						dragonCoords.erase(dragonCoords.begin() + k);
						dragonFound = true;
					}
				}
				if (!dragonFound) {
					goldCoords.push_back(make_pair(i, j));
				}
			} else if (c == 'H') {
				game[i][j] = make_shared<Human>();
			} else if (c == 'W') {
				game[i][j] = make_shared<Dwarf>();
			} else if (c == 'E') {
				game[i][j] = make_shared<Elf>();
			} else if (c == 'O') {
				game[i][j] = make_shared<Orc>();
			} else if (c == 'M') {
				game[i][j] = make_shared<Merchant>();
			} else if (c == 'D') {
				bool goldFound = false;
				for (int k = 0; k < goldCoords.size(); ++k) {
					if (abs(i - goldCoords[k].first) <= 1 && abs(j - goldCoords[k].second) <= 1) {
						game[i][j] = make_shared<Dragon>(goldCoords[k].first, goldCoords[k].second);
						goldCoords.erase(goldCoords.begin() + k);
						goldFound = true;
					}
				}
				if (!goldFound) {
					dragonCoords.push_back(make_pair(i, j));
				}
			} else if (c == 'L') {
				game[i][j] = make_shared<Halfling>();
			} else if (c == '\\') {
				game[i][j] = make_shared<Stairway>();
			} else if (c == '@') {
				game[i][j] = player;
			} else {
				game[i][j] = nullptr;
			}
		}
	}

	// set objects in chambers to be references to objects in board
	// chamber 0
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 26; ++j) {
			chambers[0]->objects[i][j] = ref(game[i + 3][j + 3]);
		}
	}
	// chamber 1
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 23; ++j) {
			chambers[1]->objects[i][j] = ref(game[i + 3][j + 39]);
		}
	}
	for (int i = 0; i < 31; ++i) {
		chambers[1]->objects[2][i] = ref(game[5][i + 39]);
	}
	for (int i = 0; i < 34; ++i) {
		chambers[1]->objects[3][i] = ref(game[6][i + 39]);
	}
	for (int i = 4; i < 10; ++i) {
		for (int j = 0; j < 15; ++j) {
			chambers[1]->objects[i][j] = ref(game[i + 3][j + 61]);
		}
	}
	// chamber 2
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 12; ++j) {
			chambers[2]->objects[i][j] = ref(game[i + 10][j + 38]);
		}
	}
	// chamber 3
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 21; ++j) {
			chambers[3]->objects[i][j] = ref(game[i + 15][j + 4]);
		}
	}
	// chamber 4
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 11; ++j) {
			chambers[4]->objects[i][j] = ref(game[i + 16][j + 65]);
		}
	}
	for (int i = 3; i < 6; ++i) {
		for (int j = 0; j < 39; ++j) {
			chambers[4]->objects[i][j] = ref(game[i + 16][j + 37]);
		}
	}
}

void Board::showBoard() const {
	for(int x = 0; x < BOARD_HEIGHT; x++){
		for( int y = 0; y < BOARD_WIDTH; y++){
			cout << charBoard[x][y];
		}
		cout << endl;
	}
}

shared_ptr<GameObject>& Board::indexChamber(int chamberNo, int i) const {
	for (int j = 0; j < chambers[chamberNo]->objects.size(); ++j) {
		if (i < chambers[chamberNo]->objects[j].size()) {
			return chambers[chamberNo]->getObject(j, i);
		} else {
			i -= chambers[chamberNo]->objects[j].size();
		}
	}
}

shared_ptr<GameObject>& Board::randSquare() const {
	while (true) {
		int chamb = rand() % 5;
		int square = rand() % chambers[chamb]->getSize();
		shared_ptr<GameObject>& loc = indexChamber(chamb, square);
		if (loc == nullptr) {
			return loc;
		}
	}
}

char Board::getChar(int x, int y) const {
	return charBoard[x][y];
}

void Board::setChar(int x, int y, char c) {
	charBoard[x][y] = c;
}

pair <int, int> Board::getCoords(const GameObject* obj) const {
	for (int i = 0; i < BOARD_HEIGHT; ++i) {
		for (int j = 0; j < BOARD_WIDTH; ++j) {
			if (game[i][j].get() == obj) {
				return make_pair(i, j);
			}
		}
	}
}

void Board::spawn() {
	srand(time(NULL));

	// spawn player
	int playerChamb = rand() % 5;
	int playerSquare = rand() % chambers[playerChamb]->getSize();
	shared_ptr<GameObject>& playerLoc = indexChamber(playerChamb, playerSquare);
	playerLoc = player;
	pair <int, int> playerCoords = getCoords(playerLoc.get());
	charBoard[playerCoords.first][playerCoords.second] = '@';

	// spawn stairway
	int stairChamb = playerChamb;
	while (stairChamb == playerChamb) {
		stairChamb = rand() % 5;
	}
	int stairSquare = rand() % chambers[stairChamb]->getSize();
	shared_ptr<GameObject>& stairLoc = indexChamber(stairChamb, stairSquare);
	stairLoc = make_shared<Stairway>();
	pair <int, int> stairCoords = getCoords(stairLoc.get());
	charBoard[stairCoords.first][stairCoords.second] = '\\';

	// spawn potions
	for (int i = 0; i < 10; ++i) {
		shared_ptr<GameObject>& potionLoc = randSquare();
		shared_ptr<GameObject> newPotion;
		int potionType = rand() % 6;
		if (potionType == 0) {
			newPotion = make_shared<RH>();
		} else if (potionType == 1) {
			newPotion = make_shared<BA>();
		} else if (potionType == 2) {
			newPotion = make_shared<BD>();
		} else if (potionType == 3) {
			newPotion = make_shared<PH>();
		} else if (potionType == 4) {
			newPotion = make_shared<WA>();
		} else if (potionType == 5) {
			newPotion = make_shared<WD>();
		}
		potionLoc = newPotion;
		pair <int, int> potionCoords = getCoords(potionLoc.get());
		charBoard[potionCoords.first][potionCoords.second] = 'P';
	}

	// spawn gold
	for (int i = 0; i < 10; ++i) {
		shared_ptr<GameObject>& goldLoc = randSquare();
		int goldVal;
		int goldType = rand() % 8;
		bool dragonHoard = false;
		if (goldType <= 5) {
			goldVal = 2;
		} else if (goldType == 6) {
			goldVal = 6;
			dragonHoard = true;
		} else if (goldType >= 7) {
			goldVal = 1;
		}
		shared_ptr<GameObject> newGold = make_unique<Gold>(goldVal, dragonHoard);
		goldLoc = newGold;
		pair <int, int> goldCoords = getCoords(goldLoc.get());
		charBoard[goldCoords.first][goldCoords.second] = 'G';
		// spawn dragon
		if (dragonHoard) {
			int row = goldCoords.first;
			int col = goldCoords.second;
			if (row + 1 < BOARD_HEIGHT && game[row + 1][col] == nullptr) {
				game[row + 1][col] = make_unique<Dragon>(row, col);
				charBoard[row + 1][col] = 'D';
			}
			else if (row - 1 >= 0 && game[row - 1][col] == nullptr) {
				game[row - 1][col] = make_unique<Dragon>(row, col);
				charBoard[row - 1][col] = 'D';
			}
			else if (col + 1 < BOARD_WIDTH && game[row][col + 1] == nullptr) {
				game[row][col + 1] = make_unique<Dragon>(row, col);
				charBoard[row][col + 1] = 'D';
			}
			else if (col - 1 >= 0 && game[row][col - 1] == nullptr) {
				game[row][col - 1] = make_unique<Dragon>(row, col);
				charBoard[row][col - 1] = 'D';
			}
			else if (row + 1 < BOARD_HEIGHT && col + 1 < BOARD_WIDTH && game[row + 1][col + 1] == nullptr) {
				game[row + 1][col + 1] = make_unique<Dragon>(row, col);
				charBoard[row + 1][col + 1] = 'D';
			}
			else if (row + 1 < BOARD_HEIGHT && col - 1 >= 0 && game[row + 1][col - 1] == nullptr) {
				game[row + 1][col - 1] = make_unique<Dragon>(row, col);
				charBoard[row + 1][col - 1] = 'D';
			}
			else if (row - 1 >= 0 && col + 1 < BOARD_WIDTH && game[row - 1][col + 1] == nullptr) {
				game[row - 1][col + 1] = make_unique<Dragon>(row, col);
				charBoard[row - 1][col + 1] = 'D';
			}
			else if (row - 1 >= 0 && col - 1 >= 0 && game[row - 1][col - 1] == nullptr) {
				game[row - 1][col - 1] = make_unique<Dragon>(row, col);
				charBoard[row - 1][col - 1] = 'D';
			}
		}
	}

	// spawn enemies
	for (int i = 0; i < 20; ++i) {
		shared_ptr<GameObject>& enemyLoc = randSquare();
		shared_ptr<GameObject> newEnemy;
		int enemyType = rand() % 18;
		if (enemyType <= 4) {
			newEnemy = make_shared<Human>();
		} else if (enemyType <= 7) {
			newEnemy = make_shared<Dwarf>();
		} else if (enemyType <= 12) {
			newEnemy = make_shared<Halfling>();
		} else if (enemyType <= 14) {
			newEnemy = make_shared<Elf>();
		} else if (enemyType <= 16) {
			newEnemy = make_shared<Orc>();
		} else if (enemyType <= 18) {
			newEnemy = make_shared<Merchant>();
		}
		enemyLoc = newEnemy;
		pair <int, int> enemyCoords = getCoords(enemyLoc.get());
		if (enemyType <= 4) {
			charBoard[enemyCoords.first][enemyCoords.second] = 'H';
		} else if (enemyType <= 7) {
			charBoard[enemyCoords.first][enemyCoords.second] = 'W';
		} else if (enemyType <= 12) {
			charBoard[enemyCoords.first][enemyCoords.second] = 'L';
		} else if (enemyType <= 14) {
			charBoard[enemyCoords.first][enemyCoords.second] = 'E';
		} else if (enemyType <= 16) {
			charBoard[enemyCoords.first][enemyCoords.second] = 'O';
		} else if (enemyType <= 18) {
			charBoard[enemyCoords.first][enemyCoords.second] = 'M';
		}
	}
}

void Board::reset() {
	merchantHostile = false;
	for( int i = 0; i < 5; i++ ){
		for( int x = 0; x < chambers[i]->objects.size(); x++ ) {
			for ( int y = 0; y < chambers[i]->objects[x].size(); y++) {
				if(chambers[i]->getObject(x, y) != nullptr) {
					chambers[i]->setObject(x, y, nullptr);
				}
			}
		}
	}
	for (int i = 0; i < BOARD_HEIGHT; ++i) {
		for (int j = 0; j < BOARD_WIDTH; ++j) {
			char cur = charBoard[i][j];
			if (cur != '|' && cur != '-' && cur != '#' && cur != '+' && cur != ' ') {
				charBoard[i][j] = '.';
			}
		}
	}

	player->removePotions();
}

void Board::nextTurn() {
	for( int i = 0; i < 5; i++) {
		vector<shared_ptr<GameObject>> moved;
		for( int x = 0; x < chambers[i]->objects.size(); ++x) {
			for ( int y = 0; y < chambers[i]->objects[x].size(); ++y) {
				shared_ptr<GameObject> cur = chambers[i]->getObject(x, y);
				if(cur != nullptr && cur->getDesc() == "troll") {
					shared_ptr<Troll> t = static_pointer_cast<Troll>(cur);
					if (t->getHp() + 5 <= 120) {
						t->setHp(t->getHp() + 5);
					} else {
						t->setHp(120);
					}
				}
				if(cur != nullptr && cur->getDesc() == "enemy" && frozen == false
					&& find(moved.begin(), moved.end(), cur) == moved.end()) {
					shared_ptr<Enemy> e = static_pointer_cast<Enemy>(cur);
					e->checkRadius(*this);
					e->move(*this, e);
					moved.push_back(cur);
				}
			}
		}
	}
}

shared_ptr<GameObject> Board::getObject(int x, int y) const {
	return game[x][y];
}

void Board::setObject(int x, int y, shared_ptr<GameObject> obj) {
	game[x][y] = obj;
}

void Board::nextLevel() {
	reset();
	spawn();
	++level;
}

int Board::getLevel() const {
	return level;
}

void Board::changeFrozen() {
	frozen = !frozen;
}

bool Board::isMerchantHostile() const {
	return merchantHostile;
}

void Board::changeMerchantHostile() {
	merchantHostile = !merchantHostile;
}
