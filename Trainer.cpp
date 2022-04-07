#include "Trainer.h"
#include "Battle.h"

#include <iostream>

using namespace std;

Trainer::Trainer(string name):Person(name){
    pokeBallCount = 0;
}

bool Trainer::hasPokemonRemaining(){
    bool itDoes = false;
    for( Pokemon pokemon: pokemons){
        itDoes |= !pokemon.hasFainted();
    }
    return itDoes;
}

void Trainer::addPokemon(Pokemon pokemon){
    pokemons.push_back(pokemon);
}

void Trainer::showParty(){
    say("Pokemons:");
    for(Pokemon pokemon: pokemons){
        say(pokemon.toString());
    }

    cout<<endl;
}

void Trainer::addPokeBalls(int x){
    pokeBallCount += x;
}

bool Trainer::hasPokeBalls(){
    return pokeBallCount != 0;
}

void Trainer::usePokeBall(){
    pokeBallCount--;
}

void Trainer::showPokeBalls(){
    say("Pokeballs: "+to_string(pokeBallCount));
    cout<<endl;
}

void Trainer::healPokemons(){
    for(Pokemon& poke: pokemons){
        poke.heal();
    }
}