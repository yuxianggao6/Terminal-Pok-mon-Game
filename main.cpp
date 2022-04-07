#include <iostream>

#include "Pokedesk.h"
#include "Person.h"
#include "Trainer.h"
#include "Player.h"
#include "Battle.h"
#include "GymLeader.h"

using namespace std;

int main(){
    // Seed the RNG
    srand(time(NULL));

    // Get the pokedesk
    Pokedesk pd = Pokedesk();

    // Initialize professor oak
    Person oak = Person("Oak");
    
    // Prompt the user to enter a few answers
    oak.promptString("Are you a boy or a girl?: ");
    string name = oak.promptString("Whats your name?: ");
    oak.say("Hi trainer "+name+". Welcome to Pokemon World!");
    
    oak.say("1) Bulbasaur");
    oak.say("2) Charmander");
    oak.say("3) Squirtle");

    
    oak.say("Pick a starter");

    // Set the players starter pokemon
    Trainer* player = new Player(name);
    int starterIndex = 5;//player->promptInt("I choose ");

    Pokemon starter;
    switch (starterIndex){
        case 1:
        starter = pd.getBulbasaur();
        break;

        case 2:
        starter = pd.getSquirtle();
        break;

        case 3:
        starter = pd.getCharmander();
        break;

        default:
        oak.say("Hey hey, that's not an option, I am giving you a Pikachu instead!");
        starter = pd.getPikachu();
        break;
    }

    player->addPokemon(starter);

    oak.say("Can you show me your current party?");

    player->say("Yeah sure.");
    player->showParty();

    oak.say("Awesome!");
    oak.say("Now you are ready to start your adventure!");
    oak.say("Go live your life!");
    oak.say("Go catch pokemons!");
    oak.say("Or you just just fight the gym leaders!");
    oak.say("You can go visit the oracle at Route 101 and he'll guide you through the adventure!");
    oak.say("Here, take these pokeballs.");

    // Add 5 pokeballs, courtesy of professor oak
    player->addPokeBalls(5);

    player->showPokeBalls();

    // Oracle is an imaginary character here
    // Since this isn't the full version of pokemon
    Person oracle = Person("Oracle");
    while (true){
        oracle.say("So what do you want to do little one?");
        oracle.say("1) Run in the tall grasses. (50% chance of encountering a pokemon)");
        oracle.say("2) Battle the gym leader.");
        oracle.say("3) Buy 10 Pokeballs.");
        oracle.say("4) List party.");
        oracle.say("5) Show pokeballs.");
        oracle.say("6) Heal Pokemons.");

        // Get the option from the user.
        int option = player->promptInt("I choose ");

        // Can't declare inside switch :(
        Pokemon* poke;
        Trainer* gl;
        Battle *battle;
        int score;


        switch(option){
            case 1:
            // Get the nearby pokemon
            poke = pd.scanNearby();
            if (poke != NULL){
                // repeat as long as you have poke balls
                while (player->hasPokeBalls()){

                    // Ask if user wants to use a poke ball
                    oracle.say("Use a pokeball? (Yes/no)");
                    string wildOption = player->promptString();

                    // Use pokeball
                    if (wildOption[0] == 'y' || wildOption[0] == 'Y'){
                        player->say("Finger's crossed!");

                        // Every pokemon has a 50% catch rate
                        if (rand()%2){
                            oracle.say(poke->toString()+" was caught!");
                            oracle.say("It has been added to your party!");
                            player->addPokemon(*poke);
                            break;
                        }
                        else{
                            oracle.say("Oh no!");
                            oracle.say(poke->toString()+" broke free!");
                        }
                    }
                    // Run away mechanics
                    else{
                        oracle.say("Got away safely!");
                        break;
                    }
                    
                }

                // Figure out if the loop broke because of user or the pokeballs had run out
                if (!player->hasPokeBalls()){
                    oracle.say("You don't have any more pokeballs :(");
                    oracle.say("But relax, you can get more at the next stop!");
                }

            }
            break;

            case 2:
            // Get our boi brock
            gl = GymLeader::Brock();
            gl->showParty();

            // Create a "battle" betwen player and brock
            battle = new Battle(player,gl);
            score = battle->start();

            // If score is 0, it's a draw
            if (score == 0){
                oracle.say("Well played!");
                oracle.say("That was not bad at all!");
                oracle.say("Nice draw!");
            }
            else if (score == 1){
                oracle.say("Congratulations on your victory young trainer!");
                
            }
            else{
                oracle.say("Better luck next time!");
            }

            cout<<endl;
            cout<<player->hasPokemonRemaining();
            
            delete gl;
            delete battle;
            
            break;

            case 3:

            // Add 10 pokeballs
            player->addPokeBalls(10);
            player->say("Thanks for the 10 pokeballs, I now have !");
            player->showPokeBalls();
            break;

            case 4:
            // Show players party
            player->showParty();
            break;

            case 5:
            // Show pokeball count
            player->showPokeBalls();
            break;

            case 6:
            // Equivalent to Nurse Joy healing your pokemons
            player->healPokemons();

            default:
            break;
        }
    }

}