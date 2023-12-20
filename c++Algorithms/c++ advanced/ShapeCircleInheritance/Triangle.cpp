#include "Triangle.h"
#include <cmath>

Triangle::Triangle() :Shape(3)
{

}
Triangle::~Triangle(){}


bool Triangle::isSpecial()
{
	float len = getLength(points[0], points[4]);
	//if all sides are equal then it's special
	for (int i = 0; i < 2; i++)
	{
		if (len != getLength(points[i], points[i + 1]))
			return false;
	}
	return true;
}
float Triangle::area()const
{
	float a = getLength(points[0], points[1]);
	float b = getLength(points[1], points[2]);
	float ab = a * b;
	//get the coordinated for vectors a and b
	//inorder to get the angle between a and b
	//and be able to return to the user the 
	//area of his triangle.
	float x = points[1].getX() - points[0].getX();
	float y = points[1].getY() - points[0].getY();
	float x1 = points[2].getX() - points[1].getX();
	float y1 = points[2].getY() - points[1].getY();
	
	float dot = (x * x1) + (y*y1);
	float angle = acos(dot / ab);//get the angle to plug into formula for size
	return ((ab * sin(angle)) / 2);//return size after using this formula
}
void Triangle::printSpecial()
{
	std::cout << "An equilateral triangle with a side length " << getLength(points[0], points[1]) << std::endl;
}