//File: main for - two poligons
//Author: Chaim Fishman
//ID: 208509349

#include "polygon.h"
#include <iostream>
using namespace std;
int main()
{
	int sides, x, y;
	char la;
	cout << "enter number of sides: ";
	cin >> sides;
	//create a polygon x with inputed amount of sides
	polygon a(sides);
	//input the points for polygon a
	cout << "enter the point values:\n";
	for (int i = 0; i < sides; i++)
	{
		cin >> la >> x >> la >> y >> la;
		point t(x, y);
		a.addpoint(t, i);
	}
	cout << "enter number of sides: ";
	cin >> sides;
	polygon b(sides);
	cout << "enter the point values:\n";
	for (int i = 0; i < sides; i++)
	{
		cin >> la >> x >> la >> y >> la;
		point t(x, y);
		b.addpoint(t, i);
	}
	bool equal = a.compare(b);
	if (equal == true)
	{
		cout << "equal.perimeter: " << a.perimiter() << endl;
	}
	else {
		cout << "perimeter: " << a.perimiter() << endl;
		cout << "perimeter: " << b.perimiter() << endl;
	}
	return 0;
}
/*
enter number of sides: 3
in constructor
enter the point values:
(10,10) (10,14) (13,10)
enter number of sides: 3
in constructor
enter the point values:
(10,10) (10,14) (13,10)
in copy-constructor
in destructor
equal.perimeter: 12
in destructor
in destructor*/