#include "Battle.h"
#include "Trainer.h"

#include <iostream>

using namespace std;

Battle::Battle(Trainer* trainer1,Trainer* trainer2){
    this->trainer1 = trainer1;
    this->trainer2 = trainer2;
}

int Battle::start(){

    // Get pokemons from both trainers
    p1 = trainer1->getNewPokemon();
    p2 = trainer2->getNewPokemon();
    trainer1->say("I choose you "+p1->toString());
        trainer2->say("I choose you "+p2->toString());

    // Iterate till both have remaining pokemons
    while (trainer1->hasPokemonRemaining() &&
            trainer2->hasPokemonRemaining()){
        cout<<endl;

        // Deffault is attack
        bool t1IsAttacking = true;
        bool t2IsAttacking = true;

        // Check if they wanna switch pokemons
        if (trainer1->changePokemon()) {
            trainer1->say("Come back "+p1->toString());
            p1 = trainer1->getNewPokemon();
            trainer1->say("Come back "+p1->toString());
            t1IsAttacking = false;
        }
        if (trainer2->changePokemon()) {
            trainer2->say("Come back "+p2->toString());
            p2 = trainer2->getNewPokemon();
            trainer2->say("Go "+p2->toString());
            t2IsAttacking = false;
        }

        // If they hadn't changed attack
        if (t1IsAttacking){
            int delta = p1->attack();
            cout<< p1->toString()<<" attacked!"<<endl;
            // Attack hit
            if (delta != 0){
                cout<<"Health was reduced by "<<delta<<endl;
                p2->damage(delta);
                // If pokemon dies and trainer has more, replace
                if (p2->hasFainted() && !trainer2->hasPokemonRemaining()){
                    break;
                }
                else{
                    p2 = trainer2->getNewPokemon();
                }
            }
            else{
                // Attack dodged
                cout<<"BUT "<<p2->toString()<<"dodged the attack!"<<endl;
            }
        }

        // Refer to above
        if (t2IsAttacking){
            int delta = p2->attack();
            cout<< p2->toString()<<" attacked!"<<endl;
            if (delta != 0){
                cout<<"Health was reduced by "<<delta<<endl;
                p1->damage(delta);
                if (p1->hasFainted() && !trainer1->hasPokemonRemaining()){
                    break;
                }
                else{
                    p1 = trainer1->getNewPokemon();
                }
            }
            else{
                cout<<"BUT "<<p1->toString()<<"dodged the attack!"<<endl;
            }
        }

        cout<<endl;
        cout<<"New State:"<<endl;
        cout<<p1->toString()<<endl;
        cout<<p2->toString()<<endl<<endl;
    }

    // Winner decider.
    if (!trainer1->hasPokemonRemaining() &&
        !trainer2->hasPokemonRemaining()){
        return 0;
    }
    if (trainer1->hasPokemonRemaining()){
        return 1;
    }
    else{
        return -1;
    }
}