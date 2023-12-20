//File: point header for - two poligons
//Author: Chaim Fishman
//ID: 208509349
#pragma once
class point
{
public:
	//constructors
	point() : x(0), y(0) {};
	point(int x1, int y1);
	//copy constructor
	point(const point& x);
	//getters
	int get_x();
	int get_y();
	//methods
	int distance(point e);
	
private:
	int x;
	int y;
};
