#include "Circle.h"
#include <cmath>
Circle::Circle():Shape(1)
{
	std::cout << "Enter radius:\n";
	std::cin >> radius;
}
Circle::Circle(float r):Shape(1)
{
	radius = r;
}

Circle::~Circle(){}


//speical if Point is (0,0).
bool Circle::isSpecial()
{
	if (*points == (0, 0))//if this works its a neat trick.
		return true;
	return false;
}

float Circle::area()const
{
	float pi = 3.14;
	return pi * (pow(radius, 2));
}
void Circle::printSpecial()
{
	std::cout << "A canonical circle with a radius " << radius << std::endl;
}