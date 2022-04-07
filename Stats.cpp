#include "Stats.h"

Stats::Stats(int HP, int attack, int defense, int spAtk, int spDef,int speed){
    this->HP = HP;
    this->attack = attack;
    this->defense = defense;
    this->spAtk = spAtk;
    this->spDef = spDef;
    this->speed = speed;
}

Stats::Stats(const Stats& other){
    this->HP = other.HP;
    this->attack = other.attack;
    this->defense = other.defense;
    this->spAtk = other.spAtk;
    this->spDef = other.spDef;
    this->speed = other.speed;
}

Stats::Stats(){
    this->HP = 0;
    this->attack = 0;
    this->defense = 0;
    this->spAtk = 0;
    this->spDef = 0;
    this->speed = 0;
}