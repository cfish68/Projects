#pragma once
#include "Shape.h"
class Rectangle :public Shape
{
public:
	Rectangle();
	~Rectangle();
	virtual bool isSpecial();
	virtual void printSpecial();
	virtual float area()const;
};