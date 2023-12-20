//File Name: recursive_sort.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project for: Intro to Computer Science hw11.4
//Description: this program will take in an array of 
//numbers and sort it using a recursive sort function.
#include <iostream>
using namespace std;

void swap(int* ptr, int ia, int ib);



void reverse(int* ptr, int size);

int main() {
	int* arr;
	int num;
	cout << "enter a number: ";
	cin >> num;
	arr = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	cout << "before: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	reverse(arr, num);
	cout << "after: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}


void swap(int* ptr, int ia, int ib)
{
	int temp = *(ptr + ia);
	*(ptr + ia) = *(ptr + ib);
	*(ptr + ib) = temp;
}


void reverse(int* ptr, int size)
{
	
	if (ptr < ptr + size-2)
		reverse(ptr + 1, size - 2);
	swap(ptr, 0, size - 1);
}



/*
enter a number:
5
enter array values: 1 2 3 4 5
before:
1 2 3 4 5
after:
5 4 3 2 1
*/