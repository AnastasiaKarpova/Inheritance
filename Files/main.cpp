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
	
	std::ofstream fout;  //1)Создаем поток
	fout.open("File.txt", std::ios_base::app); //2) Открываем поток. При открытии потока,
	//мы указыаем в какой именно файл мы будем писать.
//std::ios_base::app (append) - дописывать в конец файла
	fout << "Hello Files" << endl; //3)Пишем в поток
	fout.close();          //4) Закрываем поток. Потоки обязательно нужно закрывать,
	// если не закрывать потоки, это может привести к непредвиденным последствиям.



	system("notepad File.txt");
#endif // WRITE_FRON_FILE

#ifdef READ_FROM_FILE
	//1)Создание и открытие потока можно совместить
	std::ifstream fin("file.txt");  
	//2) При чтении обязательно нужно проверять открылся поток или нет
	if (fin.is_open())   
	{
		//TODO: read from file

		// 3) Чтение из файла
		while (!fin.eof())  //Пока не конец файла, читаем поток
		{
			const int SIZE = 102400;
			char buffer[SIZE]{};
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}

		//4) Поток есть смысл закрывать только в том случае, если он был открыт
		fin.close();  
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
#endif // READ_FROM_FILE

	
}