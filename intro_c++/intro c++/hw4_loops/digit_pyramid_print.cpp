//File Name: digit_pyramid_print.cpp
//Author: Chaim Fishman
//ID:208509349
//Description: This program will ask a user for a 1 digit number
//and print out a pyramid as such if the number was 4
//4, 3, 2, 1 
//   3, 2, 1
//      2, 1
//         1
//created:11/10/2020
#include <iostream>
using namespace std;
int main() {
	int input;
	cout << "enter a one digit number:\n";
	do
	{
		cin >> input;
		if (input < 1 || input>9)
		{
			cout << "ERROR\n";
		}
	} while (input < 1 || input>9);
	for (int i = 0; i < input; i++)//how many lines we want to print
	{
		for (int s = i; s > 0; s--)//spaces in the line we are up to
			cout << "   ";
		for (int n = (input - i); n > 0; n--)//print out the numbers with a(,) and space.
		{
			cout << n;
			if (n==1)//if we are at the last number of the line we don't want a comma
			{
				break;
			}
			cout << ", ";
		}
		cout << endl;
	}
	return 0;
}
/*
enter a one digit number:
7
7, 6, 5, 4, 3, 2, 1
   6, 5, 4, 3, 2, 1
	  5, 4, 3, 2, 1
		 4, 3, 2, 1
			3, 2, 1
			   2, 1
				  1
				  works as it should*/