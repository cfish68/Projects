//File Name: Two_Number_calculator.
//Author: Chaim Fishman
//ID: 208509349
//Assignment: 1.3
//Description: program will get 2 numbers from user
//and print out answer for the 2 numbers added, subtracted, multiplied and divided.
//Last Modified: 10/27/2020
#include <iostream>
using namespace std;
int main()
{
	float x, y;
	cout << "enter two numbers:\n";
	cin >> x >> y;
	cout << x << '+' << y << '=' << x + y << endl;
	cout << x << '-' << y << '=' << x - y << endl;
	cout << x << '*' << y << '=' << x * y << endl;
	cout << x << '/' << y << '=' << x / y << endl;
	return 0;
	
}
/*Program works as expected.
enter two numbers:
8 4
8+4=12
8-4=4
8*4=32
8/4=2
enter two numbers:
8 5
8+5=13
8-5=3
8*5=40
8/5=1.6
enter two numbers:
8.5 4
8.5+4=12.5
8.5-4=4.5
8.5*4=34
8.5/4=2.125*/