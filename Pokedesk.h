#ifndef POKEDESK_H
#define POKEDESK_H

#include <vector>
#include <string>

#include "Pokemon.h"

using namespace std;

class Pokedesk{
    private:
    vector<Pokemon> pokemons;
    

    public:
    Pokedesk();
    Pokemon* getPokemonById(int id);
    Pokemon* scanNearby();

    
    Pokemon getBulbasaur();
    Pokemon getSquirtle();
    Pokemon getCharmander();
    Pokemon getPikachu();

    int getCount();
    

};


#endif