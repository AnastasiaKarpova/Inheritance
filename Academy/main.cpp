#include <iostream>
#include <fstream> 
#include <string>
#include "Academy.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "GraduateStudent.h"
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n-------------------------------------\n"

//#define INHERITANCE_1
//#define INHERITANCE_2
//#define SAVE_CHECK
//#define LOAD_CHECK

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
	human.print();
	cout << delimiter << endl;

	Student student(human, "Theft", "Vice", 95, 98);
	student.print();
	cout << delimiter << endl;

	GraduateStudent graduate(student, "How to make money");
	graduate.print();

#endif //INHERITANCE_2
	
#ifdef SAVE_CHECK 
	Human* group[] =
	{
	new Student("Pimkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90),
	new Teacher("White", "Walter", 50, "chemistry", 25),
	//new GraduateStudent("Michael", "Stepnov", 21, "Construction", "BS_43", 5, 98, "Multi-storey construction", "Kulikov A.V."),
	new GraduateStudent("Schrader", "Hank", 40, "Chiminalistic", "OBN", 50, 70, "How to catch Heisenberg"),
	new Student("Vercetti", "Tommy", 30, "Theft", "Vice", 95, 98),
	new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	Clear(group, sizeof(group) / sizeof(group[0]));
#endif // SAVE_CHECK
	
#ifdef LOAD_CHECK
	int n = 0;
	Human** group = Load("group.txt", n);
	Print(group, n);
	Clear(group, n);
#endif // LOAD_CHECK
		
}