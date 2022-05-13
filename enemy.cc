#include "enemy.h"
#include "board.h"
#include "gold.h"
#include "race.h"
#include <memory>
#include <utility>
#include <ctime>
#include <cstdlib>

using namespace std;

Enemy::Enemy(int hp, int atk, int def, char c)
    : Character{ "enemy", hp, atk, def }, c{ c }
{}

void Enemy::checkRadius(Board& board) {
    pair <int, int> enemyCoords = board.getCoords(this);
    pair <int, int> playerCoords = board.getCoords(board.player.get());
    if (abs(playerCoords.first - enemyCoords.first) <= 1 && abs(playerCoords.second - enemyCoords.second) <= 1) {
        board.player->beAttacked(*this);
    }
}


void Enemy::die(Board& board){
    srand(time(NULL));

    int randVal = rand() % 2;
    pair <int, int> p = board.getCoords(this);
    board.setChar(p.first, p.second, 'G');

    if(randVal){
        board.setObject(p.first, p.second, make_unique<Gold>(1, false));
    } else{
        board.setObject(p.first, p.second, make_unique<Gold>(2, false));
    }
}

void Enemy::move(Board& b, shared_ptr<Enemy> e) const {
    srand(time(NULL));

    pair <int, int> enemyCoords = b.getCoords(this);
    int enemyX = enemyCoords.first;
    int enemyY = enemyCoords.second;
    bool loop = true;
    while (loop) {
        loop = false;
        int randVal = rand() % 8;
        if (randVal == 0 && b.getObject(enemyX + 1, enemyY) == nullptr) {
            b.setObject(enemyX + 1, enemyY, e);
            b.setChar(enemyX + 1, enemyY, c);
        } else if (randVal == 1 && b.getObject(enemyX + 1, enemyY + 1) == nullptr) {
            b.setObject(enemyX + 1, enemyY + 1, e);
            b.setChar(enemyX + 1, enemyY + 1, c);
        } else if (randVal == 2 && b.getObject(enemyX, enemyY + 1) == nullptr) {
            b.setObject(enemyX, enemyY + 1, e);
            b.setChar(enemyX, enemyY + 1, c);
        } else if (randVal == 3 && b.getObject(enemyX - 1, enemyY + 1) == nullptr) {
            b.setObject(enemyX - 1, enemyY + 1, e);
            b.setChar(enemyX - 1, enemyY + 1, c);
        } else if (randVal == 4 && b.getObject(enemyX - 1, enemyY) == nullptr) {
            b.setObject(enemyX - 1, enemyY, e);
            b.setChar(enemyX - 1, enemyY, c);
        } else if (randVal == 5 && b.getObject(enemyX - 1, enemyY - 1) == nullptr) {
            b.setObject(enemyX - 1, enemyY - 1, e);
            b.setChar(enemyX - 1, enemyY - 1, c);
        } else if (randVal == 6 && b.getObject(enemyX, enemyY - 1) == nullptr) {
            b.setObject(enemyX, enemyY - 1, e);
            b.setChar(enemyX, enemyY - 1, c);
        } else if (randVal == 7 && b.getObject(enemyX + 1, enemyY - 1) == nullptr) {
            b.setObject(enemyX + 1, enemyY - 1, e);
            b.setChar(enemyX + 1, enemyY - 1, c);
        } else {
            loop = true;
        }
    }
    b.setObject(enemyX, enemyY, nullptr);
    b.setChar(enemyX, enemyY, '.');

}
