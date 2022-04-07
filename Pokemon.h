#ifndef POKEMON_H
#define POKEMON_H

#include <string>

#include "Stats.h"

using namespace std;

class Pokemon{
    friend class Pokedesk;
    private:
    int id;
    string name;
    string type1;
    string type2;
    int currHP;
    Stats stats;
    bool legendary;

    public:
    Pokemon();
    Pokemon(int pokeId,string pokeName,string pokeType1,string pokeType2,Stats pokeStats);
    bool hasFainted();
    void heal();
    int attack();
    string toString();
    void damage(int val);
    string getName();
};



#endif