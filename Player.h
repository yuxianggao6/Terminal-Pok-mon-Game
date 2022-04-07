#ifndef PLAYER_H
#define PLAYER_H

#include "Trainer.h"
#include <string>

using namespace std;

class Player: public Trainer{
    public:
    Player(string name);
    //void makeMove(Battle* battle);
    bool changePokemon();
    Pokemon* getNewPokemon();

};

#endif