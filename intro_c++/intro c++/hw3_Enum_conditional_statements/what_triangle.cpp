//file name: what_triangle.cpp
//Author: Chaim Fishman
//ID: 208509349
//Description: this program will ask the user to enter 3 \
//sides of a triangle and tell the user what type of 
//triangle it is.
//Last modified: 11/03/2020
#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	
	cout << "enter 3 numbers:\n";
	cin >> a >> b >> c;
	if(a == b && b == c)
	{
		cout << "equilateral triangle\n";
	}
	else if( (a == b && a != c) ||
		(b == c && c != a) ||
		(a == c && a != b) )
	{
		cout << "isosceles triangle\n";
	}
//check for case that cannot form triangle
//note: if any 2 sides on a triangle are smaller
//than the third side. then the triangle
//superceeds the laws of physics.
	else if (a + b < c ||
		a + c < b ||
		c + b < a)
	{
		cout << "cannot form a triangle\n";
	}
//only option left is a scalene triangle
	else
	{
		cout << "scalene triangle\n";
	}
	return 0;
}
/*
enter 3 numbers:
5 5 5\
equilateral triangle
enter 3 numbers:
1 2 3
scalene triangle
enter 3 numbers:
1 2 2
isosceles triangle
enter 3 numbers:
1 7 5
cannot form a triangle
enter 3 numbers:
3 4 5
scalene triangle
enter 3 numbers:
5 1 7
cannot form a triangle
*/