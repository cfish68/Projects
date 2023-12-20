//File: Circles
//Author: Chaim Fishman
//ID: 208509349
//This is the main file associated with circles program
#include <iostream>
#include "Circle.h"
using namespace std;
int main()
{
	Circle circles[3];
	char t;
	int x, y, r;
	cout << "enter the center point and radius of 3 circles:\n";
	for (int i = 0; i < 3; i++)
	{
		cin >> t >> x >> t >> y >> t >> r;
		if (r < 0)
		{
			cout << "ERROR:\n";
			i--; continue;
		}
		circles[i].circle(x, y, r);
	}
	cout << "perimeter:	A:" << circles[0].get_cir() <<
		" B: " << circles[1].get_cir() << " C: " << circles[2].get_cir() << endl <<
		"area: A: " << circles[0].get_ar() << " B : "
		<< circles[1].get_ar() << " C : " << circles[2].get_ar() << endl <<
		"enter points until(0, 0) :" << endl;
	int a = 0, b = 0, c = 0;
	x = 1, y = 1;
	while (true)
	{
		cin >> t >> x >> t >> y >> t;
		if (x == 0 && y == 0)
			break;
		if (((circles[0].g_x() - x) * (circles[0].g_x() - x)) + ((circles[0].g_y() - y) * (circles[0].g_y() - y)) <= (circles[0].get_rad() * circles[0].get_rad()))
		{
			a++;
		}
		if (((circles[1].g_x() - x) * (circles[1].g_x() - x)) + ((circles[1].g_y() - y) * (circles[1].g_y() - y)) <= (circles[1].get_rad() * circles[1].get_rad()))
		{
			b++;
		}
		if (((circles[2].g_x() - x) * (circles[2].g_x() - x)) + ((circles[2].g_y() - y) * (circles[2].g_y() - y)) <= (circles[2].get_rad() * circles[2].get_rad()))
		{
			c++;
		}
	}
	cout << "num of points in circle : A:" << a << " B: " << b << " C: " << c << endl;
	return 0;
}
/*
program output
enter the center point and radius of 3 circles:
(0,0) 3
(1,1) 2
(5,5) 2
perimeter:      A:18.84 B: 12.56 C: 12.56
area: A: 28.26 B : 12.56 C : 12.56
enter points until(0, 0) :
(0,1)
(1,0)
(0,4)
(0,0)
num of points in circle : A:2 B: 2 C: 0*/