#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
using namespace std;

namespace Geometry
{
	enum Color
	{
		//CMYK - 
		//RGB
		RED   = 0x000000FF,
		GREEN = 0x0000FF00,
		BLUE  = 0x00FF0000,
		YELLOW = 0x0000FFFF,
		DARK_GREEN = 0x0000AA00,
		CONSOLE_RED = 0XCC,  //СТАРШАЯ C - ЦВЕТ ФОНА, МЛАДШАЯ C - ЦВЕТ ТЕКСТА
		CONSOLE_GREEN = 0XAA,
		CONSOLE_BLUE = 0X99,
		CONSOLE_DEFAULT = 0x07
	};
#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color
	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
		static const int MIN_START_X = 100;
		static const int MIN_START_Y = 50;
		static const int MAX_START_X = 1000;
		static const int MAX_START_Y = 500;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 32;
		static const int MIN_SIZE = 50;
		static const int MAX_SIZE = 500;
		static int count;
	public:
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		Shape(SHAPE_TAKE_PARAMETERS) :color(color) 
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
			count++;
		}
		virtual ~Shape() 
		{
			count--;
		}

		//Encapsulation:
		int get_count()const
		{
			return count;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this-> start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y < MIN_START_Y)start_y = MIN_START_Y;
			if (start_y > MAX_START_Y)start_y = MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			this->line_width = 
				line_width < MIN_LINE_WIDTH ? MIN_LINE_WIDTH : 
				line_width > MAX_LINE_WIDTH ? MAX_LINE_WIDTH : 
				line_width;
		}
		int filter_size(int size)const
		{
			return
				size < MIN_SIZE ? MIN_SIZE :
				size>MAX_SIZE ? MAX_SIZE :
				size;
		}

		// Methods:

		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};
	int Shape::count = 0;

	/*class Square :public Shape
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
	};*/

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}
		void set_width(double width)
		{
			this->width = filter_size(width);
		}
		void set_height(double height)
		{
			this->height = filter_size(height);
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
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x+width, start_y+height);

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
		Ellipse(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
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

	//class Triangle :public Shape
	//{
	//	double sideA;
	//	double sideB;
	//	double footing; //основание треугольника
	//	double height;
	//public:
	//	Triangle(double sideA, double sideB, double footing, double height, SHAPE_TAKE_PARAMETERS):Shape(SHAPE_GIVE_PARAMETERS) 
	//	{
	//		set_sideA(sideA);
	//		set_sideB(sideB);
	//		set_footing(footing);
	//		set_height(height);
	//	}
	//	~Triangle() {}
	//	void set_sideA(double sideA)
	//	{
	//		this->sideA = sideA;
	//	}
	//	void set_sideB(double sideB)
	//	{
	//		this->sideB = sideB;
	//	}
	//	void set_footing(double footing)
	//	{
	//		this->footing = footing;
	//	}
	//	void set_height(double height)
	//	{
	//		this->height = height;
	//	}
	//	double get_sideA()const
	//	{
	//		return sideA;
	//	}
	//	double get_sideB()const
	//	{
	//		return sideB;
	//	}
	//	double get_footing()const
	//	{
	//		return footing;
	//	}
	//	double get_height()const
	//	{
	//		return height;
	//	}
	//	double get_area()const override
	//	{
	//		return (footing * height)/2; // 1/2 * основание * высоту
	//	}
	//	double get_perimeter()const override
	//	{
	//		return sideA + sideB + footing;
	//	}
	//	void draw()const override
	//	{
	//		//HWND hwnd = GetConsoleWindow();
	//		HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
	//		HDC hdc = GetDC(hwnd);
	//		HPEN hPen = CreatePen(PS_SOLID, 10, color);
	//		HBRUSH hBrush = CreateSolidBrush(color);
	//		SelectObject(hdc, hPen);
	//		SelectObject(hdc, hBrush);
	//		

	//		DeleteObject(hBrush);
	//		DeleteObject(hPen);

	//		ReleaseDC(hwnd, hdc);
	//	}
	//	void info()const override
	//	{
	//		cout << typeid(*this).name() << endl;
	//		cout << "Боковая сторона треугольника 1: " << get_sideA() << endl;
	//		cout << "Боковая сторона треугольника 2: " << get_sideB() << endl;
	//		cout << "Основание треугольника: " << get_footing() << endl;
	//		cout << "Высота треугольника: " << get_height() << endl;
	//		Shape::info();
	//	}
	//};

	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS){}
		~Square(){}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		void set_radius(double radius)
		{
			this->radius = filter_size(radius);
		} 
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return 2 * radius;
		}
		double get_area()const override
		{
			return M_PI * radius * radius;
		}
		double get_perimeter()const override
		{
			return M_PI * get_diameter();
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

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

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
	public:
		Triangle(SHAPE_TAKE_PARAMETERS): Shape(SHAPE_GIVE_PARAMETERS){}
		~Triangle(){}
		virtual double get_height()const = 0;
		void info()const override
		{
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class EquilateralTriangle :public Triangle //равносторонний
	{
		double side;
				
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		void set_side(double side)
		{
			this->side = filter_size(side);
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const override
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area()const override
		{
			return (side * get_height()) / 2;
		}
		double get_perimeter()const override
		{
			return 3*side;
		}
		void draw()const override
		{
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};

			::Polygon(hdc, vertices, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			Triangle::info();
		}
	};
	class IsoscelesTriangle :public Triangle  //равнобедренный
	{
		double side;
		double base;
	public:
		IsoscelesTriangle(double side, double base, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
			set_base(base);
		}
		~IsoscelesTriangle() {}
		void set_side(double side)
		{
			this->side = filter_size(side);
			if (this->side <= base / 2)this->side = base * 3 / 5;
		}
		void set_base(double base)
		{
			this->base = filter_size(base);
		}
		double get_side()const
		{
			return side;
		}
		double get_base()const
		{
			return base;
		}
		double get_height()const override
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const override
		{
			//return (sqrt((pow(base, 2) - (pow(side, 2)/4))*side))/2;
			return base * get_height() / 2;
		}
		double get_perimeter()const override
		{
			return 2*side + base;
		}
		void draw()const override
		{
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{start_x, start_y + side},
				{start_x + base, start_y + side},
				{start_x + base / 2, start_y + side - get_height()}
			};

			::Polygon(hdc, vertices, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона треугольника: " << get_side() << endl;
			cout << "Осноание треугольника: " << get_base() << endl;
			Triangle::info();
		}
	};
	class RightTriangle :public Triangle //прямоугольгный
	{
		double a;
		double b;
		double c;
	public:
		RightTriangle(double a, double b, double c, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_a(a);
			set_b(b);
			set_c(c);
		}
		~RightTriangle() {}
		void set_a(double a)
		{
			this->a = a;
		}
		void set_b(double b)
		{
			this->b = b;
		}
		void set_c(double c)
		{
			this->c = c;
		}
		double get_a()const
		{
			return a;
		}
		double get_b()const
		{
			return b;
		}
		double get_c()const
		{
			return c;
		}
		double get_area()const override
		{
			return (a * b) / 2;
		}
		double get_perimeter()const override
		{
			return a + b + c;
		}
		double get_height()const override
		{

		}
		double get_area()const override
		{

		}
		double get_perimeter()const override
		{
			return a + b + c;
		}
		void draw()const override
		{
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{start_x, start_y + a},
				{start_x + c, start_y + b},
				{start_x + c / 2, start_y + b - get_height()}
			};

			::Polygon(hdc, vertices, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны 1: " << get_a() << endl;
			cout << "Длина стороны 2: " << get_b() << endl;
			cout << "Длина стороны 3: " << get_c() << endl;
			Triangle::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_RED);
	Geometry::Square square(50, 100, 100, 5, Geometry::Color::RED);
	/*cout << "Длина стороны: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();

	Geometry::Rectangle rect(500, 300, 200, 100, 1, Geometry::Color::BLUE);
	rect.info();

	cout << endl;

	/*Geometry::Ellipse ellipse(6, Geometry::Color::GREEN);
	ellipse.info();

	cout << endl;*/

	/*Geometry::Triangle triangle(300, 300, 50, 20, Geometry::Color::GREEN);
	triangle.info();*/

	cout << endl;

	Geometry::Circle disk(1000, 500, 100, 5, Geometry::Color::YELLOW);
	disk.info();

	cout << endl;

	Geometry::EquilateralTriangle e_triangle(150, 300, 100, 1, Geometry::Color::GREEN);
	e_triangle.info();

	cout << endl;

	Geometry::IsoscelesTriangle iso_triangle(200, 100, 500, 200, 50, Geometry::Color::GREEN);
	iso_triangle.info(); 

	cout << endl;

	Geometry::RightTriangle r_triangle(150, 200, 300, 300, 100, 1, Geometry::Color::GREEN);
	r_triangle.info();

	cout << "Количество фигур: " << disk.get_count() << endl;
}