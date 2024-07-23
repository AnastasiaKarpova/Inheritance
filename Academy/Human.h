#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n-------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	static const int TYPE_WIDTH = 12;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	int get_age()const;
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(int age);

	// Constructors
	Human(HUMAN_TAKE_PARAMETERS);
	virtual ~Human();

	// Methods:
	/*void print()const
	{
		cout << last_name << " " << first_name << " " << age;
	}*/
	virtual std::ostream& print(std::ostream& os)const;
	virtual std::ofstream& print(std::ofstream& ofs)const;
	virtual std::ifstream& read(std::ifstream& ifs);
};

std::ostream& operator<<(std::ostream& os, const Human& obj);
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj);
std::ifstream& operator>>(std::ifstream& ifs, Human& obj);