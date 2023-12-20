
#pragma once
#include "Shape.h"
class Circle :public Shape
{
public:
	Circle();
	Circle(float r);
	~Circle();
	virtual bool isSpecial();//special Circle with center (0,0)
	virtual void printSpecial();
	virtual float area()const;
private:
	float radius;
};