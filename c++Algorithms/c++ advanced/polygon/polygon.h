//File: polygon header for - two poligons
//Author: Chaim Fishman
//ID: 208509349
#pragma once
#include "point.h"
class polygon
{
public:
	//constructor
	polygon() : number(0), points(0){};
	polygon(int n);
	//copy constructor
	polygon(const polygon &x);
	~polygon();
	void addpoint(point x, int i);
	int perimiter();
	bool compare(polygon other);
private:
	int number;
	point* points;
};