#include "Person.h"

#include <iostream>

using namespace std;

Person::Person(string name){
    this->name = name;
}

void Person::say(string text){
    cout<<name<<">> "<<text<<endl;
}

string Person::promptString(string text){
    cout<<name<<"<< "<<text;
    string inp;
    cin>>inp;
    cout<<endl;
    return inp;
}

int Person::promptInt(string text){
    cout<<name<<"<< "<<text;
    int inp;
    cin>>inp;
    cout<<endl;
    return inp;
}

string Person::getName(){
    return name;
}