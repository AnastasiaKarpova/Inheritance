#include "Human.h"

class Human;

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
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}

// Methods:
/*void print()const
{
	cout << last_name << " " << first_name << " " << age;
}*/
std::ostream& Human::print(std::ostream& os)const
{
	//os << strchr(typeid(*this).name(), ' ') + 1 << ":\t";
	return os << last_name << " " << first_name << " " << age << " ";
}
std::ofstream& Human::print(std::ofstream& ofs)const
{
	ofs.width(TYPE_WIDTH);
	ofs << std::left;
	ofs << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";
	ofs.width(LAST_NAME_WIDTH);
	ofs << last_name; 
	ofs.width(FIRST_NAME_WIDTH);
	ofs << first_name; 
	ofs.width(AGE_WIDTH);
	ofs << age;
	return ofs;
}

std::ifstream& Human::read(std::ifstream& ifs)
{
	ifs >> last_name >> first_name >> age;
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
	return os;
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}

std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.read(ifs);
}

