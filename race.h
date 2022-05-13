#ifndef RACE_H
#define RACE_H
#include "character.h"
#include "board.h"
#include <memory>

class Potion;
class Effects;
class Enemy;
class Merchant;
class Dragon;
class Elf;
class Human;
class Halfling;
class Orc;
class Dwarf;

class Race: public Character {
    protected:
        int maxHp;
        std::shared_ptr<Potion> potions;
        int gold;
        bool onObject;

    public:
        Race(std::string desc, int hp, int atk, int def);
        void move(int x, int y, Board& b);
        void usePotion(std::shared_ptr<Effects> potion, Board& b);
        void removePotions();
        virtual void beAttacked(Enemy& e) = 0;
        virtual void attack(Merchant& m, Board& b) = 0;
        virtual void attack(Dragon& d, Board& b) = 0;
        virtual void attack(Elf& e, Board& b) = 0;
        virtual void attack(Human& h, Board& b) = 0;
        virtual void attack(Halfling& h, Board& b) = 0;
        virtual void attack(Orc& o, Board& b) = 0;
        virtual void attack(Dwarf& d, Board& b) = 0;
        int getGold();
};

#endif
