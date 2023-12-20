//File Name: digit_order.cpp
//Author: Chaim Fishman
//ID: 208509349
//Email: csfwny@gmail.com
//Description: This program will ask a user to enter a positive interger. 
//will check to see for legal entry. the program will take then number 
//and tell the user if he wrote it in descending order.
//Date Created: 11/10/2020
#include <iostream>
using namespace std;
int main() {
	int number, i=1;
//keep track of numbers to be compared to one another
	int lastNumber = -1, nextNumber;
//set a bool to true which will be switched if numbers are not in order
	bool yesNo = true;
	cout << "enter a number:\n";
	do
	{
		cin >> number;
		if (number < 0)//assuming 0 is legal input and will
			cout << "ERROR\n";
	} while (number < 0);
	while (number/10)//keep going while the expression being divided by 10 returns a value (to count number of digits)
	{
		nextNumber = number % 10;//get the value of the number we are looking at right now
		number /= 10;//divide the input by 10 to get the next number next time or end the loop when we finish
		if (nextNumber < lastNumber)//compare the last number stored with the new 
		{
			yesNo = false;//set to false if the new number looked at is smaller then the last number
		}
		lastNumber = nextNumber;//store the new number to be looked at next time as the old number
	}
	if (yesNo)//finally if the input was in ascending order from least valueable digit to greatest output yes if not no.
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
/*
enter a number:
4321
YES
enter a number:
2345632
NO
enter a number:
0          <<<<<<<<<<<<I assume for this is the intended out put the hw was asking for.
YES
enter a number:
-99
ERROR
573
YES*/