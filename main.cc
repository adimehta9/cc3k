#include "board.h"
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "effects.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

// takes in a string of length 2 representing a direction and returns the
//   change in coordinates
pair <int, int> getChange(string& dir) {
	pair <int, int> change = make_pair(0, 0);
	if (dir[0] == 'e') {
		change.second = 1;
	}
	else if (dir[0] == 'w') {
		change.second = -1;
	}
	else {
		if (dir[0] == 'n') {
			change.first = -1;
		}
		else if (dir[0] == 's') {
			change.first = 1;
		}
		if (dir[1] == 'e') {
			change.second = 1;
		}
		else if (dir[1] == 'w') {
			change.second = -1;
		}
	}

	return change;
}

int main(int argc, char** argv) {
	bool restart = true;
	while (restart) {
		// get type of race
		cout << "Enter the type of race you would like to play as: ";
		char r;
		cin >> r;
		string race;
		shared_ptr<Race> player;
		if (r == 's') {
			player = make_shared<Shade>();
			race = "Shade";
		}
		else if (r == 'd') {
			player = make_shared<Drow>();
			race = "Drow";
		}
		else if (r == 'v') {
			player = make_shared<Vampire>();
			race = "Vampire";
		}
		else if (r == 'g') {
			player = make_shared<Goblin>();
			race = "Goblin";
		}
		else if (r == 't') {
			player = make_shared<Troll>();
			race = "Troll";
		}

		// create board from file
		ifstream layout;
		if (argc == 2) {
			layout.open(argv[1]);
		}
		else {
			layout.open("default.txt");
		}
		Board b{ layout, player };
		if (argc == 1) {
			b.spawn();
		}

		bool gameWon = false;

		// game loop
		char c;
		string action = "Player character has spawned.";
		while (true) {
			// display board and stats
			b.showBoard();
			int hp = player->getHp();
			int atk = player->getAtk();
			int def = player->getDef();
			int gold = player->getGold();
			int level = b.getLevel();
			cout << "Race: " << race << " Gold: " << setw(50) << left << gold << "Floor: " << level + 1 << endl;
			cout << "HP: " << hp << endl;
			cout << "Atk: " << atk << endl;
			cout << "Def: " << def << endl;
			cout << "Action: " << action << endl;
			cout << "Enter a command: ";
			cin >> c;

			if (c == 'a') {
				string dir;
				cin >> dir;
				pair <int, int> change = getChange(dir);
				pair <int, int> playerLoc = b.getCoords(player.get());
				int x = playerLoc.first + change.first;
				int y = playerLoc.second + change.second;
				shared_ptr<GameObject> enemy = b.getObject(x, y);
				if (enemy == nullptr || enemy->getDesc() != "enemy") {
					action = "PC unsucessfully tried to attack an enemy";
				}
				else {
					shared_ptr<Enemy> e = static_pointer_cast<Enemy>(enemy);
					e->beAttacked(*player, b);
					if (e->getHp() <= 0) {
						action = "PC has killed enemy";
					}
					else {
						action = "PC has attacked enemy and enemy now has " + to_string(e->getHp()) + " HP left";
					}
				}
			}
			else if (c == 'u') {
				string dir;
				cin >> dir;
				pair <int, int> change = getChange(dir);
				pair <int, int> playerLoc = b.getCoords(player.get());
				int x = playerLoc.first + change.first;
				int y = playerLoc.second + change.second;
				shared_ptr<GameObject> potion = b.getObject(x, y);
				if (potion == nullptr || potion->getDesc().length() > 2) {
					action = "PC unsuccessfully tried to use a potion";
				}
				else {
					shared_ptr<Effects> p = static_pointer_cast<Effects>(potion);
					player->usePotion(p, b);
					action = "PC used potion " + p->getDesc();
				}
			}
			else if (c == 'f') {
				b.changeFrozen();
				action = "Enemies have been frozen";
			}
			else if (c == 'r') {
				break;
			}
			else if (c == 'q') {
				restart = false;
				break;
			}
			else {
				char c2;
				cin >> c2;
				string dir = string(1, c) + c2;
				pair <int, int> change = getChange(dir);
				pair <int, int> playerLoc = b.getCoords(player.get());
				int x = playerLoc.first + change.first;
				int y = playerLoc.second + change.second;
				shared_ptr<GameObject> next = b.getObject(x, y);
				if (next != nullptr && next->getDesc() != "gold" &&
					next->getDesc() != "doorway" && next->getDesc() != "passage"
					&& next->getDesc() != "stairway" || b.getChar(x, y) == ' ') {
					action = "PC has tried moving to an invalid square";
				}
				else {
					player->move(x, y, b);
					action = "PC has moved";
				}
			}

			// check if game has ended
			int curLevel = b.getLevel();
			if (curLevel >= 5) {
				gameWon = true;
				restart = false;
				break;
			}

			if (level - curLevel == 0) {
				b.nextTurn();
			}

			if (player->isDead()) {
				restart = false;
				break;
			}
		}

		// end game
		if (!gameWon) {
			cout << "Game Over" << endl;
		}
		else if (gameWon) {
			cout << " __     ______  _    _  __          _______ _   _ _ " << endl;
			cout << " \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | |" << endl;
			cout << "  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | |" << endl;
			cout << "   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | |" << endl;
			cout << "    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |_|" << endl;
			cout << "    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_(_)" << endl;
			cout << "Now give us 100% please" << endl;
			int score = player->getGold();
			if (race == "Shade") {
				score *= 1.5;
			}
			cout << "Your score is " << score;
		}
	}
}
