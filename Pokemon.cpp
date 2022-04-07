#include "Pokemon.h"

Pokemon::Pokemon(){
    id = 0;
    name = "SHAGGY BLANCO";
    type1 = "Dragon";
    type2 = "Dragon";
    stats = Stats();
    currHP = 10000;
}

Pokemon::Pokemon(int pokeId,string pokeName,string pokeType1, string pokeType2, Stats pokeStats){
    id = pokeId;
    name = pokeName;
    type1 = pokeType1;
    type2 = pokeType2;
    stats = pokeStats;
    currHP = pokeStats.HP;
}

bool Pokemon::hasFainted(){
    return currHP<=0;
}

void Pokemon::heal(){
    currHP = stats.HP;
}

string Pokemon::toString(){
    string out = name+" ("+to_string(currHP)+"/"+to_string(stats.HP)+") ["+type1;
    if (type2.compare("")!=0){
        out += "/"+type2;
    }
    out+="]";
    return out;
}

int Pokemon::attack(){
    if( rand()%2){
        return (rand()%100) * stats.attack /100;
    }
    return 0;
}

void Pokemon::damage(int val){
    currHP -= val;

    currHP = currHP<0 ? 0 : currHP;
}

string Pokemon::getName(){
    return name;
}