//File Name: recursive_search.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project: Intro to Computer Science hw 11.2
//Descrioption: User will input size of array and elements of that size
//the main will call function that will search through the array recursively 
//and return the smallest number.
#include <iostream>
using namespace std;
int smallest(int*, int);
int main() {
	int* array;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num <= 0)
			cout << "ERROR" << endl;
	} while (num <= 0);
	array = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> array[i];
	cout << "the smallest is: " << array[smallest(array, num)] << endl;
	return 0;
}
int smallest(int* ptr, int size)
{
 //base case
	if (size <= 1)
		return 0;
	int i = smallest(ptr + 1, size - 1);
	if (*(ptr + i + 1) > *ptr)
	{
		return 0;
	}
	return i + 1;
}