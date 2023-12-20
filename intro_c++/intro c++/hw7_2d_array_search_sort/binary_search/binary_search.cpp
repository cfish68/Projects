//File Name: binary_search.cpp
//For: HW #6 question #1. intro to computer science.
//Author: Chaim Fishman
//ID: 208509349
//Description: This program will have an array of size 10 and have the user input an ascending order
//sequence of numbers. If the numbers are not ascending the program will read out an ERROR and 
//have the user input a new sequence till the input matches the paramaters.
//The program will ask the user to enter a number to search for
//call a function to see if the number exists in the array
//and let the user know if it exitst.
//Date Created: 12/01/2020
#include <iostream>
using namespace std;
bool binary_search(int arr[], int size, const int search, int& index);//use binary search algorithm on sorted array
void input_array(int arr[], int size);//have user input sorted array
int main() {
	int const max_size = 10;
	int input[max_size];
	int search_number;
	int index;
	input_array(input, max_size);//get input from user to fill up array
	cout << "enter 1 number:\n";
	cin >> search_number;
	(binary_search(input, max_size, search_number ,index)) ?//call function as bool paramater for this statement
		cout << "the number " << search_number << " was found at index " << index << endl//if fundction returns true
		: cout << "not found\n";//if function returns false
	return 0;
}
bool binary_search(int arr[], int size, const int search, int& index) {
	int lower = 0, upper = size - 1;
	while (lower <= upper) {
		int middle = (lower + upper) / 2;
		index = middle;
		// item is middle element
		if (search == arr[middle])
		{
			return true;
		}
		// search upper half
		if (search > arr[middle])
			lower = middle + 1;

		// search lower half
		if (search < arr[middle])
			upper = middle - 1;

	}
	return false;
}
void input_array(int arr[], int size) {
	bool not_ascending = true;
	cout << "enter 10 numbers:\n";
	while (not_ascending)//if input is not_ascending keep getting input.
	{
		not_ascending = false;
		for (int i = 0; i < size; i++)//get appropriate number of inputs from user
		{
			cin >> arr[i];
			if (i > 0 && arr[i] <= arr[i - 1])//set not ascending to true if non ascending input
			{
				not_ascending = true;
			}//if statement
		}//for loop
		if (not_ascending)//let user know if there was an error in input
			cout << "ERROR\n";
	}//while loop
}
/*
regular test with number present
enter 10 numbers:
1 2 3 4 5 6 7 8 9 10
enter 1 number:
4
the number 4 was found at index 3


test wrong input, and test number that is not in the array.
enter 10 numbers:
1 2 3 4 4 5 6 7 8 9
ERROR
1 2 3 2 4 5 6 7 8 9
ERROR
1 2 3 4 5 6 7 8 9 10
enter 1 number:
0
not found
enter 10 numbers:
 1 3 54 67 70 80 99 101 120 400
enter 1 number:
5
not found*/