#include<Windows.h>
#include<iostream>
using namespace std;

namespace Geometry
{
	enum Color
	{
		CONSOLE_RED = 0XCC,  //СТАРШАЯ C - ЦВЕТ ФОНА, МЛАДШАЯ C - ЦВЕТ ТЕКСТА
		CONSOLE_GREEN = 0XAA,
		CONSOLE_BLUE = 0X99,
		CONSOLE_DEFAULT = 0x07
	};

	class Shape
	{
	protected:
		Color color;
	public:
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		void set_side(double side)
		{
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, Color color) :Shape(color)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}
		void set_width(double width)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return (width + height) * 2;
		}
		void draw()const override
		{
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, 500, 100, 900, 300);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника: " << get_width() << endl;
			cout << "Высота прямоугольника: " << get_height() << endl;
			Shape::info();
		}
	};

	class Ellipse : public Shape
	{
		double radius;
	public:
		Ellipse(double radius, Color color) :Shape(color)
		{
			set_radius(radius);
		}
		~Ellipse() {}
		void set_radius(double radius)
		{
			this->radius = radius;
		}
		double get_radius()const
		{
			return radius;
		}
		double get_area()const override
		{
			return 3.14 * radius * radius;
		}
		double get_perimeter()const override
		{
			return 2 * 3.14 * radius;
		}
		void draw()const override
		{
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, 100, 100, 400, 400);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга: " << get_radius() << endl;
			Shape::info();
		}
	};

	class Triangle :public Shape
	{
		double sideA;
		double sideB;
		double footing; //основание треугольника
		double height;
	public:
		Triangle(double sideA, double sideB, double footing, double height, Color color):Shape(color) 
		{
			set_sideA(sideA);
			set_sideB(sideB);
			set_footing(footing);
			set_height(height);
		}
		~Triangle() {}
		void set_sideA(double sideA)
		{
			this->sideA = sideA;
		}
		void set_sideB(double sideB)
		{
			this->sideB = sideB;
		}
		void set_footing(double footing)
		{
			this->footing = footing;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		double get_sideA()const
		{
			return sideA;
		}
		double get_sideB()const
		{
			return sideB;
		}
		double get_footing()const
		{
			return footing;
		}
		double get_height()const
		{
			return height;
		}
		double get_area()const override
		{
			return (footing * height)/2; // 1/2 * основание * высоту
		}
		double get_perimeter()const override
		{
			return sideA + sideB + footing;
		}
		void draw()const override
		{
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 10, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Боковая сторона треугольника 1: " << get_sideA() << endl;
			cout << "Боковая сторона треугольника 2: " << get_sideB() << endl;
			cout << "Основание треугольника: " << get_footing() << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_RED);
	Geometry::Square square(5, Geometry::Color::CONSOLE_RED);
	/*cout << "Длина стороны: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();

	Geometry::Rectangle rect(100, 50, Geometry::Color::CONSOLE_BLUE);
	rect.info();

	cout << endl;

	Geometry::Ellipse ellipse(6, Geometry::Color::CONSOLE_GREEN);
	ellipse.info();

	cout << endl;

	Geometry::Triangle triangle(13, 13, 13, 10, Geometry::Color::CONSOLE_BLUE);
	triangle.info();
}