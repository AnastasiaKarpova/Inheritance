#include "Teacher.h"
#include "Human.h"

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

const std::string& Teacher::get_speciality()const
{
	return speciality;
}
int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(int experience)
{
	this->experience = experience;
}
//Constructors:
Teacher::Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS): Human(HUMAN_GIVE_PARAMETERS)
{
	set_speciality(speciality);
	set_experience(experience);
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}
// Methods
	/*void print()const
	{
		Human::print();
		cout << speciality << " " << experience;
	}*/
std::ostream& Teacher::print(std::ostream& os)const override
{
	return Human::print(os) << speciality << " " << experience << " years ";
}
std::ifstream& read(std::ifstream& ifs)override
{
	Human::read(ifs);
	ifs >> speciality >> ;
	return ifs;
}
