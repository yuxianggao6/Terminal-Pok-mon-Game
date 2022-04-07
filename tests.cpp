#include "tests.h"

#include "Pokedesk.h"
#include "GymLeader.h"
#include "utils.h"
#include <iostream>

// Borrowed from https://stackoverflow.com/questions/52273110/how-do-i-write-a-unit-test-in-c
#define IS_TRUE(x) { if (!(x)) {std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; return 0;} }

int valid_pikachu(){
    Pokedesk pd;
    Pokemon pika = pd.getPikachu();

    IS_TRUE(pika.getName().compare("Pikachu") == 0);

    return 1;
}

int valid_squirtle(){
    Pokedesk pd;
    Pokemon sq = pd.getSquirtle();

    IS_TRUE(sq.getName().compare("Squirtle") == 0);

    return 1;
}

int valid_bulbasaur(){
    Pokedesk pd;
    Pokemon bulba = pd.getBulbasaur();

    IS_TRUE(bulba.getName().compare("Bulbasaur") == 0);

    return 1;
}

int valid_charmander(){
    Pokedesk pd;
    Pokemon charmander = pd.getCharmander();

    IS_TRUE(charmander.getName().compare("Charmander") == 0);

    return 1;
}

int valid_pokedesk_count(){
    Pokedesk pd;
    IS_TRUE(pd.getCount() == 800);

    return 1;
}

int valid_brock(){
    Trainer* trainer = GymLeader::Brock();

    IS_TRUE(trainer->getName().compare("Brock") == 0);
    IS_TRUE(trainer->getNewPokemon()->getName().compare("Onix") == 0);

    delete trainer;
    return 1;
}

int valid_use_and_add_pokeballs(){
    Trainer* trainer = GymLeader::Brock();

    int hadPokeballs1 = 0;
    while(trainer->hasPokeBalls()){
        trainer->usePokeBall();
        hadPokeballs1++;
    }
    
    trainer->addPokeBalls(100);

    int hadPokeballs2 = 0;
    while(trainer->hasPokeBalls()){
        trainer->usePokeBall();
        hadPokeballs2++;
    }

    IS_TRUE(hadPokeballs2 == 100);

    delete trainer;
    return 1;
}

int valid_add_pokemon(){
    Trainer* trainer = GymLeader::Brock();
    Pokedesk pd;

    Pokemon pika = pd.getPikachu();

    int oldCount = trainer->pokemons.size();

    trainer->addPokemon(pika);

    IS_TRUE(trainer->pokemons.size() == (oldCount+1));

    return 1;
}

int valid_split_tokens(){
    string text = "one two three four";
    vector<string> tokens = split_tokens(text,' ');

    IS_TRUE(tokens.size() == 4);

    IS_TRUE(tokens[0].compare("one") == 0);
    IS_TRUE(tokens[1].compare("two") == 0);
    IS_TRUE(tokens[2].compare("three") == 0);
    IS_TRUE(tokens[3].compare("four") == 0);

    return 1;
}

int valid_strip_string(){
    string text = "  wh12345t    ";
    IS_TRUE(strip_string(text).compare("wh12345t") == 0);

    return 1;
}

int main(){
    int totalTests = 10;
    int passingTest = 0;
    
    passingTest += valid_pikachu();
    passingTest += valid_bulbasaur();
    passingTest += valid_squirtle();
    passingTest += valid_charmander();
    passingTest += valid_pokedesk_count();
    passingTest += valid_brock();
    passingTest += valid_use_and_add_pokeballs();
    passingTest += valid_add_pokemon();
    passingTest += valid_split_tokens();
    passingTest += valid_strip_string();


    cout<<passingTest<<"/"<<totalTests<<" are passing!"<<endl;
}