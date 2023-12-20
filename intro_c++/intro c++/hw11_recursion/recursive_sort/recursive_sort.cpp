//File Name: recursive_sort.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project for: Intro to Computer Science hw11.3
//Description: this program will take in an array of 
//numbers and sort it using a recursive sort function.
#include <iostream>
using namespace std;

void swap(int* ptr, int ia, int ib);


int smallest(int* ptr, int size);


void sort(int* ptr, int size);


int main()
{
	int* arr;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num <= 0)
			cout << "ERROR" << endl;
	} while (num <= 0);
	arr = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	cout << "before: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	sort(arr, num);
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


int smallest(int* ptr, int size)
{
	//base case
	if (size <= 1)
		return 0;
	int i = smallest(ptr + 1, size - 1);
	if (*(ptr + i + 1) > * ptr)
	{
		return 0;
	}
	return i + 1;
}

void sort(int* ptr, int size)
{
	swap(ptr, 0, smallest(ptr, size));//if the smallest is already in left most index, it will swap with itself. wasteful but works just fine.
	if (size > 1)
	{
		sort(ptr + 1, size - 1);
	}
}
/* 
enter a number:
5
enter array values: 1 2 1 2 2
before:
1 2 1 2 2
after:
1 1 2 2 2


enter a number:
5
enter array values: 5 4 3 2 1
before:
5 4 3 2 1
after:
1 2 3 4 5

sorted array entered
enter a number:
5
enter array values: 1 2 3 4 5
before:
1 2 3 4 5
after:
1 2 3 4 5*/