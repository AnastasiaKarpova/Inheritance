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
std::ostream& Teacher::print(std::ostream& os)const
{
	return Human::print(os) << speciality << " " << experience << " years ";
}

std::ofstream& Teacher::print(std::ofstream& ofs)const
{
	Human::print(ofs); 
	ofs.width(SPECIALITY_WIDTH);
	ofs << speciality; 
	ofs.width(EXPERIENCE_WIDTH); 
	ofs << experience;
	return ;
}

std::ifstream& Teacher::read(std::ifstream& ifs)
{
	Human::read(ifs);
	char sz_speciality[SPECIALITY_WIDTH + 1]{};
	ifs.read(sz_speciality, SPECIALITY_WIDTH);
	for (int i = SPECIALITY_WIDTH - 2; sz_speciality[i] != ' '; i--)sz_speciality[i] = 0;
	while (sz_speciality[0] == ' ')for (int i = 0; sz_speciality[i]; i++)sz_speciality[i] = sz_speciality[i + 1];
	speciality = sz_speciality; 
	ifs >> experience;
	return ifs;
}

