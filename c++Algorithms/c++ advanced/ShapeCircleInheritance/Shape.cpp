//define class shape.

#include "Shape.h"
#include <cmath>
#include <iostream>
using namespace std;

//default constructor
Shape::Shape():numOfPoints(0), points(NULL){}
Shape::Shape(int vertices)
{
	numOfPoints = vertices;
	points = new Point[numOfPoints];
	cout << "Enter values of " << numOfPoints << " points:\n";
	for (int i = 0; i < numOfPoints; i++)
	{
		cin >> points[i];
	}
}
//deep copy
Shape::Shape(const Shape& x)
{
	numOfPoints = x.numOfPoints;
	delete points;
	points = new Point[numOfPoints];
	for (int i = 0; i < numOfPoints; i++)
		points[i] = x.points[i];
}
//shallow copy
Shape::Shape(Shape&& x)
{
	numOfPoints = x.numOfPoints;
	delete points;
	points = x.points;
	x.points = NULL;
	return;
}

Shape::~Shape()
{
	delete points;
}
float Shape::getLength(Point one, Point two)const
{
	return sqrt(pow((one.getY() - two.getY()), 2) + (pow((one.getX() - two.getX()), 2)));
}

istream& operator>>(std::istream& in, Shape* x)
{
	delete x->points;
	x->points = new Point[x->numOfPoints];
	cout << "Enter values of " << x->numOfPoints << " points:\n";
	for (int i = 0; i < x->numOfPoints; i++)
	{
		cin >> x->points[i];
	}
	return in;
}
ostream& operator<<(std::ostream& out, Shape* x)
{
	for (int i = 0; i < x->numOfPoints; i++)
		out << ' ' << x->points[i];
	out << "\narea is: " << x->area() << '\n';
	if (x->isSpecial() == true) {
		x->printSpecial();
	}
	out << endl;
	return out;
}