#include "Academy.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "GraduateStudent.h"

void Academy::Print(Human* group[], const int n)
{
	/*for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}*/
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		if(group[i])cout << *group[i] << endl;
		cout << delimiter << endl;
	}
	cout << "Количество человек в группе: " << n << endl;
}

Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human:")human = new Human("", "", 0);
	if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
	if (type == "Student:")human = new Student("", "", 0, "", 0, 0);
	if (type == "GraduateStudent:")human = new GraduateStudent("", "", 0, "", 0, 0, "");
	return human;
}
void Academy::Clear(Human* group[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}
