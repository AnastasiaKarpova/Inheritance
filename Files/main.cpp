#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

#define WRITE_FRON_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

	
#ifdef WRITE_FRON_FILE
	cout << "Hello Files" << endl;
	
	std::ofstream fout;  //1)������� �����
	fout.open("File.txt", std::ios_base::app); //2) ��������� �����. ��� �������� ������,
	//�� �������� � ����� ������ ���� �� ����� ������.
//std::ios_base::app (append) - ���������� � ����� �����
	fout << "Hello Files" << endl; //3)����� � �����
	fout.close();          //4) ��������� �����. ������ ����������� ����� ���������,
	// ���� �� ��������� ������, ��� ����� �������� � �������������� ������������.



	system("notepad File.txt");
#endif // WRITE_FRON_FILE

#ifdef READ_FROM_FILE
	//1)�������� � �������� ������ ����� ����������
	std::ifstream fin("file.txt");  
	//2) ��� ������ ����������� ����� ��������� �������� ����� ��� ���
	if (fin.is_open())   
	{
		//TODO: read from file

		// 3) ������ �� �����
		while (!fin.eof())  //���� �� ����� �����, ������ �����
		{
			const int SIZE = 102400;
			char buffer[SIZE]{};
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}

		//4) ����� ���� ����� ��������� ������ � ��� ������, ���� �� ��� ������
		fin.close();  
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
#endif // READ_FROM_FILE

	
}