#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;

vector<string> split_tokens(string text, char sep);

string strip_string(string text,char c=' ');

#endif