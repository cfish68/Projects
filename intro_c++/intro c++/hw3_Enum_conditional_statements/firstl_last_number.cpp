//File Name: firstl_last_number
//Author: Chaim Fishman
//ID:208509349
//Description: This program will ask a user to enter three numbers 
//first last and number respectively and the program will
//check if the number is greater less then or in between the
//the two numbers
//Last Modified: 11/03/2020
#include <iostream>
using namespace std; 
int main() {
	int first, last, number;
	cout << "enter 3 numbers" << endl;
	cin >> first >> last >> number;
//if the case is inbetween do this
	if (number >= first && number <= last)
	{
		cout << "between\n";
	}
//if its not between check if its smaller
	else if (number < first)
	{
		cout << "smaller\n";
	}
//if it wasn't any of the above its safe to assume its bigger.
	else
	{
		cout << "bigger\n";
	}
	return 0; 
}
/*Check to see if program works
enter 3 numbers
1 2 1
between
enter 3 numbers
1 2 2
between
enter 3 numbers
4 7 3
smaller
enter 3 numbers
1 9 10
bigger
*/