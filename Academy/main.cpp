#include <iostream>
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
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	// Constructors
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	// Methods:
	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " ";
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
	return os;
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student : public Human 
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	// Constructors
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	Student(const Human& human, STUDENT_TAKE_PARAMETERS) :Human(human)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	// Methods
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << speciality << " " << group << " " << rating << " " << attendance << " ";
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	} 

	//Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	// Methods
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << speciality << " " << experience << " years ";
	}
};

#define GRADUATESTUDENT_TAKE_PARAMETERS const std::string& subject //const std::string& the_topic_of_the_diploma, const std::string& tutor
#define GRADUATESTUDENT_GIVE_PARAMETERS subject //the_topic_of_the_diploma, tutor

class GraduateStudent : public Student
{
	//std::string the_topic_of_the_diploma; //тема диплома
	//std::string tutor; //куратор диплома
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
	const std::string& subject()const
	{
		return subject;
	}
	/*void set_the_topic_of_the_diploma(const std::string& the_topic_of_the_diploma)
	{
		this->the_topic_of_the_diploma = the_topic_of_the_diploma;
	}
	void set_tutor(const std::string& tutor)
	{
		this->tutor = tutor;
	}*/
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	
	//Constructors:
	GraduateStudent(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATESTUDENT_TAKE_PARAMETERS):
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		/*set_the_topic_of_the_diploma(the_topic_of_the_diploma);
		set_tutor(tutor);*/
		this->subject = subject; 
		cout << "GSConstructor:\t" << this << endl;
	}
	GraduateStudent(const Student& student) :Student(student)
	{
		/*set_the_topic_of_the_diploma(the_topic_of_the_diploma); 
		set_tutor(tutor);*/
		set_subject(subject);
		cout << "GSConstructor:\t" << this << endl;
	}
	~GraduateStudent()
	{
		cout << "GSDestructor:\t" << this << endl;
	}

	// Methods
	std::ostream& print(std::ostream& os)const override
	{
		return Student::print(os) << subject /*the_topic_of_the_diploma << " " << tutor*/ << " ";
	}
};

//#define INHERITANCE_1
//#define INHERITANCE_2

void Print(Human* group[], const int n)
{
	/*for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}*/
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}

void Clear(Human* group[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}

void main()
{
	setlocale(LC_ALL, "");
	cout << "HelloAcademy" << endl;
#ifdef INHERITANCE_1 
	cout << delimiter << endl;

	Human human("Richter", "Jeffrey", 40);
	human.print();

	cout << delimiter << endl;

	Student student("Pimkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90);
	student.print();

	cout << delimiter << endl;

	Teacher teacher("White", "Walter", 50, "chemistry", 25);
	teacher.print();

	cout << delimiter << endl;

	//GraduateStudent GStudent("Michael", "Stepnov", 21, "Construction", "BS_43", 5, 98, "Multi-storey construction", "Kulikov A.V.");
	GraduateStudent GStudent("Schrader", "Hank", 40, "Chiminalistic", "OBN", 50, 70, "How to catch Heisenberg");
	GStudent.print();

	cout << delimiter << endl;
#endif //INHERITANCE_1

#ifdef INHERITANCE_2
	Human human("Vercetty", "Tommy", 30);
	human.ptint();
	cout << delimiter << endl;

	Student student(humen, "Theft", "Vice", 95, 98);
	student.ptint();
	cout << delimiter << endl;

	GraduateStudent graduate(student, "How to make money");
	graduate.print();
#endif //INHERITANCE_2
	
	
	Human* group[] =
	{
	new Student("Pimkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90),
	new Teacher("White", "Walter", 50, "chemistry", 25),
	//new GraduateStudent("Michael", "Stepnov", 21, "Construction", "BS_43", 5, 98, "Multi-storey construction", "Kulikov A.V."),
	new GraduateStudent ("Schrader", "Hank", 40, "Chiminalistic", "OBN", 50, 70, "How to catch Heisenberg"),
	new Student("Vercetti", "Tommy", 30, "Theft", "Vice", 95, 98),
	new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	Print(group, sizeof(group) / sizeof(group[0]));
	Clear(group, sizeof(group) / sizeof(group[0]));
	
	
}