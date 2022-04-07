#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
    private:
    string name;

    public:
    Person(string name);
    void say(string text);
    string promptString(string text="");
    int promptInt(string text="");
    string getName();
};



#endif