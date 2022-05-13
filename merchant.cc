#include "merchant.h"
#include "race.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "gold.h"
#include <ctime>
#include <cstdlib>
#include <math.h>

Merchant::Merchant()
	: Enemy{ 30, 70, 5, 'M' }
{}

void Merchant::beAttacked(Race& r, Board& b) {
	r.attack(*this, b);
    b.changeMerchantHostile();
}

void Merchant::attack(Shade& s) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + s.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        s.setHp(s.getHp() - damage);
    }
}

void Merchant::attack(Drow& d) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + d.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        d.setHp(d.getHp() - damage);
    }
}

void Merchant::attack(Vampire& v) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + v.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        v.setHp(v.getHp() - damage);
    }
}

void Merchant::attack(Troll& t) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + t.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        t.setHp(t.getHp() - damage);
    }
}

void Merchant::attack(Goblin& g) {
    srand(time(NULL));

    int damage = ceil((100.0/(100.0 + g.getDef())) * atk);
    int randVal = rand() % 2;

    if(randVal == 0){
        g.setHp(g.getHp() - damage);
    }
}

void Merchant::die(Board& board){
    pair <int, int> p = board.getCoords(this);
    board.setChar(p.first, p.second, 'G');
    board.setObject(p.first, p.second, make_unique<Gold>(4, false));
}

void Merchant::checkRadius(Board& board) {
    pair <int, int> enemyCoords = board.getCoords(this);
    pair <int, int> playerCoords = board.getCoords(board.player.get());
    if (abs(playerCoords.first - enemyCoords.first) <= 1
        && abs(playerCoords.second - enemyCoords.second) <= 1 && board.isMerchantHostile()) {
        board.player->beAttacked(*this);
    }
}
