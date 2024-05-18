#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <map>
#include <string>

std::map<int, std::string> configureLayers();
std::string generatePassword(int complexity, int size);
int getRandomIndex(int start, int end);

#endif
