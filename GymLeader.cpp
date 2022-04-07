#include "GymLeader.h"

#include "Trainer.h"
#include "Pokedesk.h"

#include <string>
#include <vector>

using namespace std;

GymLeader::GymLeader(string name):Trainer(name){}

bool GymLeader::changePokemon(){
    if (!hasPokemonRemaining()){
        return false;
    }
    return (rand()%100) < 10;
}

Pokemon* GymLeader::getNewPokemon(){
    vector<Pokemon*> unfainted;
    for (int i=0;i<pokemons.size();i++){

        if (!pokemons[i].hasFainted()) unfainted.push_back(&pokemons[i]);
    }
    
    if (unfainted.size() == 0) return NULL;

    return unfainted[rand()%unfainted.size()];
}

GymLeader* GymLeader::Brock(){
    Pokedesk pd = Pokedesk();

    GymLeader* brock = new GymLeader("Brock");
    Pokemon onix = *pd.getPokemonById(95);

    brock->addPokemon(onix);


    return brock;
}

