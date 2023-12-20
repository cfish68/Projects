//File Name:nums_and_lsits.cpp
//Author: Chaim Fishman
//ID: 208509349
//Description: This Program will ask the user to enter 2 numbers 
//then the program will ask the user to enter a list of numbers
//the amount of times the program will take the users numbers will
//depend on the nubmers enterd eralier the first number will be compared
//to the numbers of the list added together.Once the added numbers
//exceed the first number or the amount of entrys exceeds the second number (will
//decide how many times the user can enter a number) the program will not take any more
//entrys and tell the user what the list adds up to.
#include <iostream>
using namespace std;
int main() {
	int addedLimit, entryLimit, listEntry;
	int listAdder = 0;

	cout << "enter 2 positive numbers:\n";
	//both do whille loops under check to see if entry is legal if not try again.
	do
	{
		cin >> addedLimit;
		if (addedLimit < 0)
			cout << "ERROR\n";
	} while (addedLimit < 0);//wanted to set also if is zero but hw does not ask for it
	do
	{
		cin >> entryLimit;
		if (entryLimit < 0)
			cout << "ERROR\n";
	} while (entryLimit < 0);//wanted to set also if is zero but hw does not ask for it
	cout << "enter a list of numbers:\n";
	//for loop adding up listAdder and will only keep gooing if both bool expressions are met.
	//if the listAdder exceeded the limit or entrys exceeded its limit the program will proceed to next statement.
	for (int i = 0; i < entryLimit && listAdder <= addedLimit; i++)
	{
		cin >> listEntry;
		listAdder += listEntry;
	}
	//let the user know how much his list adds up to
	cout << listAdder;
	return 0;
}
/*
added input to see if program will take it.
the program does not and works as it should

checked for negative numbers
enter 2 positive numbers:
25 12
enter a list of numbers:
9 8 7 6 5 4 3 2
enter 2 positive numbers:
-5
ERROR
-3
ERROR
2
-5
ERROR
3
enter a list of numbers:
1 3 4 6
4
30

check if limit entrys work
enter 2 positive numbers:
50 3
enter a list of numbers:
1 1 1 45
3*/