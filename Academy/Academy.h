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

Human* group[] =
{
new Student("Pimkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90),
new Teacher("White", "Walter", 50, "chemistry", 25),
//new GraduateStudent("Michael", "Stepnov", 21, "Construction", "BS_43", 5, 98, "Multi-storey construction", "Kulikov A.V."),
new GraduateStudent("Schrader", "Hank", 40, "Chiminalistic", "OBN", 50, 70, "How to catch Heisenberg"),
new Student("Vercetti", "Tommy", 30, "Theft", "Vice", 95, 98),
new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
};

void Print(Human* group[], const int n);
void Save(Human* group[], const int n, std::string filename);
Human* HumanFactory(const std::string& type);
bool NotAppropriareType(const std::string& buffer);
Human** Load(const std::string& filename, int& n);
void Clear(Human* group[], const int n);
