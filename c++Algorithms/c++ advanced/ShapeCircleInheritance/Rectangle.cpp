#include "Rectangle.h"

Rectangle::Rectangle() :Shape(4)
{
	//  is in constructor for shape  std::cout << "Enter values of  4 points:\n";
	//should be checking if it's a legal Rectangle.. hw does not specify this
}
Rectangle::~Rectangle(){}
bool Rectangle::isSpecial()
{
	float len = getLength(points[0], points[3]); 
	//if all sides are equal then it's special
	for (int i = 0; i < 3; i++)
	{
		if (len != getLength(points[i], points[i + 1]))
			return false;
	}
	return true;
}
float Rectangle::area()const
{
	return (getLength(points[0], points[1]) * getLength(points[1], points[2]));
}

void Rectangle::printSpecial()
{
	std::cout << "Square with side length " << getLength(points[0], points[1]) << std::endl;
}
