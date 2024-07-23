#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Human.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n-------------------------------------\n"

void Print(Human* group[], const int n);
void Save(Human* group[], const int n, std::string filename);
Human* HumanFactory(const std::string& type);
bool NotAppropriareType(const std::string& buffer);
Human** Load(const std::string& filename, int& n);
void Clear(Human* group[], const int n);
