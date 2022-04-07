#ifndef TRAINER_H
#define TRAINER_H

//#include "Battle.h"
#include "Person.h"
#include "Pokemon.h"
#include <vector>

using namespace std;

class Battle;

class Trainer :public Person{
    private:
    int pokeBallCount;

    public:

    Trainer(string name);
    vector<Pokemon> pokemons;
    bool hasPokemonRemaining();
    virtual bool changePokemon() = 0;
    virtual Pokemon* getNewPokemon() = 0;
    void addPokemon(Pokemon pokemon);
    void showParty();
    void addPokeBalls(int x);
    bool hasPokeBalls();
    void usePokeBall();
    void showPokeBalls();
    void healPokemons();
    virtual ~Trainer(){};
};

#endif