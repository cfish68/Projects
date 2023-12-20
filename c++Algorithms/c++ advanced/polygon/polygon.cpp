//File: polygon for - two poligons
//Author: Chaim Fishman
//ID: 208509349
#include "polygon.h"
#include <iostream>
using namespace std;
//constructor
polygon::polygon(int n)
{
		cout << "in constructor\n";
		number = n;
		points = new point[n];
}
//copy constructor
polygon::polygon(const polygon& x)
{
	cout << "in copy-constructor\n";
	number = x.number;
	points = new point[number];
	for (int i = 0; i < number; i++)
	{
		points[i] = x.points[i];
	}
}

//add each individual point. main will loop through to add to approprate index.
void polygon::addpoint(point x, int i)
{
	points[i] = x;
}

//calculate the perimiter and return it as an integer.
int polygon::perimiter()
{
	int distance = 0;
	for (int i = 0; i < number-1; i++)
	{
		distance += points[i].distance(points[i + 1]);
	}
	distance += points[0].distance(points[number - 1]);
	return distance;
}

//destructor. delete the dynamically allocated array that was created for this polygon.
polygon::~polygon()
{
	cout << "in destructor\n";
	delete[] points;
	return;
}

bool polygon::compare(polygon other)
{
	//if they don't have the same amount of points they can't be equal
	if (number != other.number)
		return false;
	//if the perimiters equal.( they don't necessirly equal, 
	if (perimiter() == other.perimiter())
		return true;
	return false;

}