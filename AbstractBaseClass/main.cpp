#include <iostream>
using namespace std;


class Vehicle
{
	int speed;
public:
	virtual void move() = 0;
};

class GroundVehicle:public Vehicle {};  //Абстрактный пацан
class AirVehicle:public Vehicle 
{
public:
	virtual void take_off() = 0;  //Взлет
	virtual void land() = 0;   //Посадка

};

class Bike :public GroundVehicle  //Конкретный пацан
{
public:
	void move()override
	{
		cout << "Harley Davidson едет на двух колесах" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move()override
	{
		cout << "BMW едет на четырех колесах" << endl;
	}
};

class AirPlane :public AirVehicle
{
public:
	void move()override
	{
		take_off();
		cout << "Полет нормальный" << endl;
		land();
	}
	void take_off()override
	{
		cout << "Нужна взлетна полоса" << endl;
	}
	void land()override
	{
		cout << "Садимся на взлетку" << endl;
	}
};

class Helicopter :public AirVehicle
{
public:
	void move()override
	{
		take_off();
		cout << "Летим потихоньку" << endl;
		land();
	}
	void take_off()override
	{
		cout << "Могу взлететь с лубого огорода" << endl;
	}
	void land()override
	{
		cout << "Где захочу, там и сяду" << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;
	//GroundVehicle gv;
	Bike harley_davidson;
	harley_davidson.move();

	Car bmw;
	bmw.move();

	AirPlane boing;
	boing.move();

	Helicopter blackHawk;
	blackHawk.move();
}