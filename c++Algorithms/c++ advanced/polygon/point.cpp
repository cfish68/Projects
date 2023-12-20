//File: point methods for - two poligons
//Author: Chaim Fishman
//ID: 208509349
#include "point.h"
#include <cmath>
point::point(int x1, int y1)
{
	x = x1; y = y1;
	return;
}
//getters
int point::get_x() { return x; };
int point::get_y() { return y; };
//methods
int point::distance(point e)
{
	int result = ((x - e.get_x()) * (x - e.get_x())) + ((y - e.get_y()) * (y - e.get_y()));
	return sqrt(result);
}
point::point(const point& copy)
{
	x = copy.x;
	y = copy.y;
	return;
}