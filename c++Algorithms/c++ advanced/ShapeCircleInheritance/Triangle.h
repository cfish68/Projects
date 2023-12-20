#pragma once
#include "Shape.h"
class Triangle: public Shape
{
public:
	Triangle();
	virtual bool isSpecial();
	virtual void printSpecial();
	virtual float area()const;
	~Triangle();
};