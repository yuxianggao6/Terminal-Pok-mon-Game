#ifndef BATTLE_H
#define BATTLE_H

//#include "Trainer.h"
#include "Pokemon.h"

class Trainer;

class Battle{
    private:
    Trainer* trainer1;
    Trainer* trainer2;

    Pokemon *p1;
    Pokemon *p2;

    public:
    Battle(Trainer* trainer1,Trainer* trainer2);
    int start();

};

#endif