#include <vector>
#include <string>

#include <iostream>

#include "utils.h"

using namespace std;

vector<string> split_tokens(string text, char sep){
    vector<string> tokens;
    tokens.push_back("");

    for (int i=0;i<text.length();i++){
        if (text[i] == sep){
            tokens.push_back(" ");
        }
        else{
            tokens[tokens.size() - 1] += text[i];
        }

        for (int i=0;i<tokens.size();i++){
            tokens[i] = strip_string(tokens[i]);
        }
    }
    return tokens;
}

string strip_string(string text,char c){
    while (text.size() && text[0] == c){
        text = text.substr(1);
    }

    while (text.size() && text[text.size() - 1] == c){
        text = text.substr(0,text.size()-1);
    }

    return text;
}