//File: Circles
//Author: Chaim Fishman
//ID: 208509349
//This is the file containing the methods for the
//class of Circle
#include "Circle.h"
point::point(int m, int n) { x = m; y = n; };
int point::g_x()
{
	return x;
}
int point::g_y()
{
	return y;
}
void Circle::circle(int m, int n, int r)
{
	point pt(m, n);
	center = pt;
	rad = r;
	ar = area();
	circumference = cir();
}

float Circle::area() 
{
	const float PI = 3.14;
	return (PI * (rad * rad));
}
float Circle::cir()
{
	const float PI = 3.14;
	return (2 * PI * rad);
}
//getters
point Circle::getCenter()
{
	return center;
}
int Circle::get_rad()
{
	return rad;
}
float Circle::get_ar()
{
	return ar;
}
float Circle::get_cir()
{
	return circumference;
}
int Circle::g_x() {
	return center.g_x();
}
int Circle::g_y()
{
	return center.g_y();
}
