//File Name: fifteen_number_arr.cpp
//Author: Chaim Fishman
//ID: 208509349
//Email: csfwny@gmail.com
//Description: this program will have a 15 int array 
//ask the user to enter 15 numbers from 1-15
//and will tell the user "GOOD" if all numbers 1-15 
//were entered if a number is missing it will say "NOT GOOD".
//Created 11/23/2020
#include <iostream>
using namespace std;
int main()
{
	int input;
	const int size = 15;
	bool entered_num[size] = { false };//declare array of type bool initialized to false.(which is false to begin with but clarity)
	cout << "enter 15 numbers:\n";
	for (int i = 0; i < size; i++)//this will loop 15 times to give 15 elements opportunity to become true
	{
		cin >> input;
		if (input > 0 && input <= size)//set number enterd to true. disregard irrelevant number.
		{
			entered_num[input - 1] = true;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (entered_num[i] == false)//if one of the elemets is still false user did not input all 15 numbers
		{
			cout << "NOT GOOD\n";
			return 0;
		}
	}
	cout << "GOOD\n";//if program did not exit earlier then all elements are true.
	return 0;
}
/*enter 15 numbers:
1 2 3 3 4 5 6 7 8 9 10 11 12 14 13
NOT GOOD
enter 15 numbers:
5 4 3 2 1 6 7 8 9 10 15 14 13 12 11
GOOD
enter 15 numbers:
1 2 3 4 1 5 6 7 8 9 10 11 12 13 14
NOT GOOD
enter 15 numbers:
-1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
NOT GOOD*/