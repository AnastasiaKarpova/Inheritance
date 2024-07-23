#include "Academy.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "GraduateStudent.h"


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
		if (group[i])
		{
			cout << *group[i] << endl;
			cout << delimiter << endl;
		}
	}
	cout << "Количество человек в группе: " << n << endl;
}
void Save(Human* group[], const int n, const std::string filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
		fout << delimiter << endl;
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str());

}
Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human:")human = new Human("", "", 0);
	if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
	if (type == "Student:")human = new Student("", "", 0, "", "", 0, 0);
	if (type == "GraduateStudent:")human = new GraduateStudent("", "", 0, "", "", 0, 0, "");
	return human;
}
bool NotAppropriareType(const std::string& buffer)
{
	return buffer.find("Human:") == std::string::npos &&
		buffer.find("Student:") == std::string::npos &&
		buffer.find("Teacher:") == std::string::npos &&
		buffer.find("GraduateStudent:") == std::string::npos;
}
Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		n = 0;
		while (!fin.eof())
		{
			std::string buffer;
			//fin.getline();
			std::getline(fin, buffer);
			//move DST, SRC;
			//strcat(DST, SRC);
			if (NotAppropriareType(buffer))continue;
			n++;
		}
		cout << "Количесто записей  файле: " << n << endl;

		group = new Human*[n] {};

		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;

		for (int i = 0; i < n; i++)
		{
			std::string type;
			fin >> type;
			if (NotAppropriareType(type))continue;
			group[i] = HumanFactory(type);
			if (group[i])
				fin >> *group[i];
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	return group;
}

void Clear(Human* group[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}
