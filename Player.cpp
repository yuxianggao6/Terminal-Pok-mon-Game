#include "Player.h"

#include <iostream>

using namespace std;

Player::Player(string name):Trainer(name){}


bool Player::changePokemon(){
    if (!hasPokemonRemaining()){
        return false;
    }

    string opt = promptString("Should I change pokemon or not???? (Yes/no)");
    if (opt[0] == 'Y' || opt[0] == 'y'){
        say("Damn right I am!");
        return true;
    }
    else{
        say("I just calculated all the risks. I don't think I should switch right now!");
        return false;
    }
}


Pokemon* Player::getNewPokemon(){
    vector<Pokemon*> unfainted;
    for (int i=0;i<pokemons.size();i++){

        if (!pokemons[i].hasFainted()) unfainted.push_back(&pokemons[i]);
    }
    
    if (unfainted.size() == 0) return NULL;

    return unfainted[rand()%unfainted.size()];

}