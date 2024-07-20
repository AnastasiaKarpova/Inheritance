#include "Human.h"

class Human;
std::ofstream& operator<<(std::ostream& ofs, const Human& obj);

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

const std::string& Human::get_last_name()const
{
	return last_name;
}
const std::string& Human::get_first_name()const
{
	return first_name;
}
int Human::get_age()const
{
	return age;
}
void Human::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(int age)
{
	this->age = age;
}

// Constructors
Human::Human(HUMAN_TAKE_PARAMETERS)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;
}
virtual Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}

// Methods:
/*void print()const
{
	cout << last_name << " " << first_name << " " << age;
}*/
virtual std::ostream& Human::print(std::ostream& os)const
{
	return os << last_name << " " << first_name << " " << age << " ";
}

virtual std::ifstream& read(std::)
{

}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
	return os;
}
std::ofstream& operator<<(std::ostream& ofs, const Human& obj)
{
	return obj.print(ofs);
}