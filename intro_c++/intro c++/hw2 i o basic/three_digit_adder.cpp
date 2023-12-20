//File Name: three_digit_adder.cpp
//Author: Chaim Fishman
//ID: 208509349
//Assignment: 2.4
//Description: Program will ask user to enter a 3 digit number.
//The number will be split into 3 separate numbers and added together
//to give the user the 3 digits added.
#include <iostream>
using namespace std;
int main()
{
	int number;
	cout << "enter a three digit number:\n";
	cin >> number;
	cout << "the sum is: " << (number / 100) + ((number % 100) / 10) + (number % 10);
	return 0;
}
/*program does what I want it to do.
enter a three digit number:
753
the sum is: 15*/