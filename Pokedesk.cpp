#include "Pokedesk.h"

#include <iostream>
#include <fstream>
#include <string>

#include "utils.h"
#include "Person.h"

using namespace std;

Pokedesk::Pokedesk(){
    // Parse given csv and load pokemons with stats
    ifstream infile("pokedexlist.csv");

    if (!infile.is_open()){
        // Check if file is there
        cout<<"Can't find pokedesklist.csv"<<endl;
        exit(1);
    }

    // Iterate over the lines
    string line = "";
    getline(infile,line);
    while (getline(infile,line)){
        // Split using UDF split_tokens on ','
        vector<string> tokens = split_tokens(line,',');

        int id = stoi(tokens[0]);

        // Get respective values
        string name = tokens[1],
                type1 = tokens[2],
                type2 = tokens[3];

        int hp = stoi(tokens[5]),
            attack = stoi(tokens[6]),
            defense = stoi(tokens[7]),
            spAtk = stoi(tokens[8]),
            spDef = stoi(tokens[9]),
            speed = stoi(tokens[10]),
            generation = stoi(tokens[11]);
        bool legendary = false;

        if (tokens[12].compare("True") == 0){
            legendary = true;
        }

        // Make the stats and the pokemon
        Stats stat(hp,attack,defense,spAtk,spDef,speed);
        Pokemon pokemon(id,name,type1,type2,stat);
        pokemons.push_back(pokemon);
    }
}

Pokemon* Pokedesk::scanNearby(){
    Person pokedesk = Person("Pokedesk");
    if ( (rand()%2)){
        int id = rand() % pokemons.size() ;
        Pokemon* pokemon = getPokemonById( id );

        pokedesk.say("...");
        pokedesk.say("There's something here!");
        pokedesk.say("It's a!");
        pokedesk.say(pokemon->toString());

        return pokemon;
    }
    pokedesk.say("Nothing here!");
    return NULL;
}

Pokemon* Pokedesk::getPokemonById(int id){
    for (int i=0;i<pokemons.size();i++){
        if (pokemons[i].id == id) return &pokemons[i];
    }
    return NULL;
};

Pokemon Pokedesk::getBulbasaur(){
    return *getPokemonById(1);
}

Pokemon Pokedesk::getSquirtle(){
    return *getPokemonById(7);
}

Pokemon Pokedesk::getCharmander(){
    return *getPokemonById(4);
}

Pokemon Pokedesk::getPikachu(){
    return *getPokemonById(25);
}

int Pokedesk::getCount(){
    return pokemons.size();
}