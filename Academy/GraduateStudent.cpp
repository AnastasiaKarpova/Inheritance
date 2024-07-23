#include "GraduateStudent.h"
#include "Human.h"
#include "Student.h"


#define GRADUATESTUDENT_TAKE_PARAMETERS const std::string& subject //const std::string& the_topic_of_the_diploma, const std::string& tutor
#define GRADUATESTUDENT_GIVE_PARAMETERS subject //the_topic_of_the_diploma, tutor


const std::string& GraduateStudent::get_subject() const
{
	return subject;
}
void GraduateStudent::set_subject(const std::string& subject)
{
	this->subject = subject;
}
//Constructors:
GraduateStudent::GraduateStudent(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATESTUDENT_TAKE_PARAMETERS) :
	Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
{
	/*set_the_topic_of_the_diploma(the_topic_of_the_diploma);
	set_tutor(tutor);*/
	set_subject(subject);
	cout << "GSConstructor:\t" << this << endl;
}
GraduateStudent::GraduateStudent(const Student& student, const std::string& subject) :Student(student)
{
	/*set_the_topic_of_the_diploma(the_topic_of_the_diploma);
	set_tutor(tutor);*/
	set_subject(subject);
	cout << "GSConstructor:\t" << this << endl;
}
GraduateStudent::~GraduateStudent()
{
	cout << "GSDestructor:\t" << this << endl;
}

// Methods
	/*void print()const
	{
		Student::print();
		cout << subject;
	}*/
std::ostream& GraduateStudent::print(std::ostream& os)const
{
	return Student::print(os) << subject; /*the_topic_of_the_diploma << " " << tutor*/
}
std::ofstream& GraduateStudent::print(std::ofstream& ofs)const
{
	Student::print(ofs);
	ofs.width(SUBJECT_WIDTH);
	ofs << subject;
	return ofs;
}
std::ifstream& GraduateStudent::read(std::ifstream& ifs) 
{
	Student::read(ifs);
	std::getline(ifs, subject);
	return ifs;
}
