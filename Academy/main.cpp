#include <fstream> 
#include "Academy.h"

#define delimiter "\n-------------------------------------\n"

void Load()
{

}


//#define INHERITANCE_1
//#define INHERITANCE_2
//#define WRITE_GROUP
//#define READ_GROUP
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
	
#ifdef WRITE_GROUP
	
	std::ofstream fout;  
	fout.open("Academys.txt", std::ios_base::app); 
	fout << group << endl;
	fout.close();


	system("notepad Academys.txt");
#endif // WRITE_GROUP

#ifdef READ_GROUP
	std::ifstream fin("Academys.txt");
	
	if (fin.is_open())
	{
		while (!fin.eof()) 
		{
			const int SIZE = 1024000;
			char buffer[SIZE]{};
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}

		
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
#endif // READ_GROUP

	int n = 0;
	Human** group = Load("group.txt", n);
	Print(group, n);
	Clear(group, n);
}