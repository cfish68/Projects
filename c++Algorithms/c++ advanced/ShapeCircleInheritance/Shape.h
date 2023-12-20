//base class shape will use to help define triangle rectangle and circle
//into "one unit of shape"

#pragma once
#include "Point.h"
#include <iostream>
#include <cmath>

class Shape
{
public:
	Shape();//defualt cost
	Shape(int veritces);//points as well and prompt user to enter amount of points
	Shape(const Shape& x);//copy cost
	Shape(Shape&& x);//move cost

	virtual ~Shape()=0;

	friend std::istream& operator>>(std::istream& in, Shape* x);//universal for all the different shapes.
	friend std::ostream& operator<<(std::ostream& out, Shape* x);//universal for all the different shapes.
	virtual float area()const=0;//all shapes defined must calculate there own area
	virtual bool isSpecial()=0;//all shapes defined must know if they're special
	virtual void printSpecial()=0;//all shapes defined have to have a special printing 
	float getLength(Point one, Point two)const;

protected:
	int numOfPoints;
	Point* points;
};