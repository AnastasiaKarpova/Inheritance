#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Human.h"
#include "Student.h"
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n-------------------------------------\n"

#define GRADUATESTUDENT_TAKE_PARAMETERS const std::string& subject /*const std::string& the_topic_of_the_diploma, const std::string& tutor*/
#define GRADUATESTUDENT_GIVE_PARAMETERS subject /*the_topic_of_the_diploma, tutor*/

class GraduateStudent : public Student
{
	/*std::string the_topic_of_the_diploma; //тема диплома
	std::string tutor; //куратор диплома*/
	static const int SUBJECT_WIDTH = 25;
	std::string subject;

public:
	/*const std::string& get_the_topic_of_the_diploma()const
	{
		return the_topic_of_the_diploma;
	}
	const std::string& get_tutor()const
	{
		return tutor;
	}*/
	const std::string& subject()const;
	/*void set_the_topic_of_the_diploma(const std::string& the_topic_of_the_diploma)
	{
		this->the_topic_of_the_diploma = the_topic_of_the_diploma;
	}
	void set_tutor(const std::string& tutor)
	{
		this->tutor = tutor;
	}*/
	void set_subject(const std::string& subject);

	//Constructors:
	GraduateStudent(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATESTUDENT_TAKE_PARAMETERS);
	GraduateStudent(const Student& student, const std::string& subject);
	~GraduateStudent();

	// Methods
	/*void print()const
	{
		Student::print();
		cout << subject;
	}*/
	std::ostream& print(std::ostream& os)const override;
	std::ofstream& print(std::ofstream& ofs)const override;
	std::ifstream& read(std::ifstream& ifs)override;
};

