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

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 5;
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const;
	int get_experience()const;
	void set_speciality(const std::string& speciality);
	void set_experience(int experience);

	//Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS);
	~Teacher();

	// Methods
	/*void print()const
	{
		Human::print();
		cout << speciality << " " << experience;
	}*/
	std::ostream& print(std::ostream& os)const override;
	std::ofstream& print(std::ofstream& ofs)const override;
	std::ifstream& read(std::ifstream& ifs)override;
};