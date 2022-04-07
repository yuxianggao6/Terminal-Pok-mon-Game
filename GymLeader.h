#ifndef GYMLEADER_H
#define GYMLEADER_H

#include <string>
#include "Trainer.h"

using namespace std;

class GymLeader: public Trainer{
    public:
    GymLeader(string name);
    bool changePokemon();
    Pokemon* getNewPokemon();

    // Factory methods
    static GymLeader* Brock();
};

#endif