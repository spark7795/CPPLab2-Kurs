// CPPLab2-KursIvan-ver2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

class Figure
{
public:
	virtual double getSquare() = 0;
	virtual void showFigureType() = 0;
};
class Rectangle : public Figure
{
private:
	double width;
	double height;
public:
	Rectangle(double w, double h) : width(w), height(h) {}
	Rectangle() {}
	double getSquare() override
	{
		return width * height;
	}
	void showFigureType()
	{
		cout << "Rectangle" << endl;
	}
};
class Square : public Rectangle {
private:
	double side;
public:
	Square(double s) : side(s) {}
	double getSquare() override
	{
		return side * side;
	}
	void showFigureType()
	{
		cout << "Square" << endl;
	}
};
class Circle : public Figure
{
private:
	double radius;
public:
	Circle(double r) : radius(r)
	{
	}
	double getSquare() override
	{
		return radius * radius * 3.14;
	}
	void showFigureType()
	{
		std::cout << "Circle" << std::endl;
	}
};
// Объем усеченной пирамиды с прямоугольными основаниями
class Pyramid_S1 {
protected:

public:
	double S1;
	void calcS1(int SideA1, int SideB1) {
		S1 = SideA1*SideB1;
	}
};
class Pyramid_S2 {
protected:

public:
	double S2;
	void calcS2(int SideA2, int SideB2) {
		S2 = SideA2*SideB2;
	}
};
class Pyramid_V : public Pyramid_S1, public Pyramid_S2
{
protected:

public:
	const double multiplier = 0.3333;
	double getVol(int h) {
		return (multiplier*h*(S1 + (sqrt(S1 * S2)) + S2));
	}
};


int main()
{
	Figure *rect = new Rectangle(30, 50);
	Figure *circle = new Circle(50);
	Figure *square = new Square(30);
	Pyramid_V pr_vol;
	pr_vol.calcS1(2, 3);
	pr_vol.calcS2(4, 5);
	cout << "Shaped Pyramid volume: " << pr_vol.getVol(3) << endl << endl;
	cout << "Rectangle square: " << rect->getSquare() << endl;
	cout << "Circle square: " << circle->getSquare() << endl;
	cout << "Square square: " << square->getSquare() << endl;
	system("pause");
	return 0;
}