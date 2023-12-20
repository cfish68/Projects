//File Name: random_number_list.cpp
//Author: Chaim Fishman
//ID: 208509349
//Description: This program will print out 10 random numbers from 1 to 1000
//and tell the user if they are in sorted from least to greatest or not
//Created: 11/9/2020
//Last Modified 11/09/2020
#include <iostream>
#include <ctime>
using namespace std;
int main() {
//create 2 *** to be able to compare the numbers and see
//if the random numbers are in ascending order.
	int lastNumber = 0;
	int newNumber;
//bool created to keep track if list is ascending order
//start of with list is ascending order till proven not true.
	bool listType = true;
	srand (time(nullptr));
//create a loop go 10 times
	for (int i = 0; i < 10; i++)
	{
		newNumber = rand() % 1000 + 1;
		cout << newNumber << ' ';
		if (newNumber < lastNumber)//if this holds true it means list type is not sorted
			listType = false;
		lastNumber = newNumber; //store the random number to be compared later
	}
	if (listType)//reminding listType is a bool=true unless list is not sorted and would be changed in the line above
	{
		cout << endl << "sorted list";
	}
	else//if list is not sorted and listType=false(the likely scenerio)
		cout << endl << "not sorted list";

	return 0;
}
/*copies of program run. watching for if programm 
ran correctly, especially that there were no logic errors with for loop
37 625 910 543 20 644 497 324 788 118
not sorted list
176 499 586 32 326 817 630 513 165 130
not sorted list
206 931 523 226 854 390 642 935 698 334
not sorted list
it is quite unlikely to get 
a sorted list.*/