//File Name: tri_rec_area.cpp
//Author: Chaim Fishman 
//ID: 208509349
//Email: csfwny@gmail.com
//Description: this program will ask a user for 2 sides of a rectangle
//and a redius for a circle and print out the area for rectangle 
//and circle using functions.
//Created: 11/17/2020
#include <iostream>
using namespace std;
int area(int side_a, int side_b);//function to retun area of rectangle
long double area(int r);//function to return area of circle. long incase user entered a large number because its squared.
bool illegal(int a);
void input(int& istr);
int main()
{
	int side_a, side_b, radius, area_rec;
	double area_circ;//might very well be a floating point value
	cout << "enter length and width of the rectangle:\n";
	do
	{
		cin >> side_a >> side_b;
		if (side_a < 1 || side_b < 1)//see if number is illegal 
		{
			cout << "ERROR\n";
		}
	} while (side_a < 1 || side_b < 1);//keep looping if number is illegal
//	input(side_a);//call the function input to get value from user             how I would've done it. (to isolate the error)
//	input(side_b);//call the function input to get value from user
	area_rec = area(side_a, side_b);//call the function to get the area of rec
	cout << area_rec << endl;
	cout << "enter radius of the circle:\n";
	input(radius);//call the function to get value from user
	area_circ = area(radius);//call the function to get area of circle
	cout << area_circ << endl;
	return 0;
}
int area(int side_a, int side_b)//function to retun area of rectangle
{
	return side_a * side_b;
}
long double area(int r)//function to return area of circle
{
	const double pi = 3.14159;//intorduce pi with given value which will stay the same.
	return pi * (double)(r * r);//return to function call area of circle    casting to r^2 not necessary compiler doesn't like the auto casting.
}
bool illegal(int a)//check if number entered is legal
{
	if (a < 1)
		return true;//if illegal
	else
		return false;//legal
}
void input(int& istr)
{
	do
	{
		cin >> istr;
		if (illegal(istr))//call function to see if number is illegal 
		{
			cout << "ERROR\n";
		}
	} while (illegal(istr));//keep looping if number is illegal
}
/*
enter length and width of the rectangle:
0
ERROR
5
0
ERROR
3
15
enter radius of the circle:
0
ERROR
1
3.14159
enter length and width of the rectangle:
2 4
8
enter radius of the circle:
1
3.14159
enter length and width of the rectangle:
1 2
2
enter radius of the circle:
100000
4.42985e+09*/