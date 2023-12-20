//File Name: fibbonocci.cpp
//Author: Chaim Fishman
//ID:208509349
//Description: this program will ask a user for a number
//and print out the Fibonocci Series corresponding to 
//that number using a loop
#include <iostream>
using namespace std;
int main() {
	int userEntry;
	int newNumber = 1;
	int oldNumber = 0;
	int output = 0;
	cout << "enter a number:\n";
//check to see if number entered is legal
	do
	{
		cin >> userEntry;
		if (userEntry < 0)
			cout << "ERROR\n";
	} while (userEntry < 0);
	
//out put series the amount of times the user asked for
	for (int i = 0; i <= userEntry; i++)
	{
		cout << output << ' ';
		oldNumber = newNumber;//if pictured numbers left to right move over one to the right
		newNumber = output;//same as above
//add up above 2 numbers to output for next number in series could've been done
//in a diffenrent point so it doesn't add up one extra time. this way looks better and it is not
//worth the one line for this specific program
		output = oldNumber + newNumber;
	}
}
/*
enter a number:
-3
ERROR
4
0 1 1 2 3
enter a number:
9
0 1 1 2 3 5 8 13 21 34
*/