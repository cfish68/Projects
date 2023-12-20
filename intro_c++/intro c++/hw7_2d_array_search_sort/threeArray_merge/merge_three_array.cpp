//File name: merge_three_array.cpp
//For: hw #7 question #2, intro to cs
//Author: Chaim Fishman
//ID: 208509349
//Email: csfwny@gmail.com
//Description: user will be propted to input intergers to 3 arrays up to size 10, 
//in descending order, ERROR will be read out if not. terminating with 0 if less then 10 inputs,.
//the program will call a function to merge the three inputs in sorted order.
//Created: 12/01/2020
#include <iostream>
using namespace std;
const int max_size = 10;
void input_array(int arr[], int& size);
void merge(int arr1[], int size1, int arr2[], int size2, int arr1and2[], int& size_merged);
int main() {
	
	int first_input[max_size] = { 0 };
	int second_input[max_size] = { 0 };
	int third_input[max_size] = { 0 };
	int store_merged[max_size * 2] = { 0 };
	int output[max_size * 3] = { 0 };
	int size1, size2, size3, size_output, size_merged;
	cout << "enter values for the first vector:\n";
	input_array(first_input, size1);
	cout << "enter values for the second vector:\n";
	input_array(second_input, size2);
	cout << "enter values for the third vector:\n";
	input_array(third_input, size3);
	merge(first_input, size1, second_input, size2, store_merged, size_merged);
	merge(third_input, size3, store_merged, size_merged, output, size_output);
	cout << "merged vector is:\n";
	for (int i = 0; i < size_output; i++)//out put merged vector
		cout << output[i] << ' ';
	cout << endl;
	
}
void input_array(int arr[], int& size) 
{
	bool ascending = true;//not what we want inputed
	cout << "enter 10 numbers:\n";
	while (ascending)//if input is not_ascending keep getting input.
	{
		ascending = false;
		int i = 0;
		for (i = 0; i < max_size; i++)//get appropriate number of inputs from user
		{
			cin >> arr[i];
			if (arr[i] == 0)//if input is 0 break out of the loop.
				break;
			if (i > 0 && arr[i] >= arr[i - 1])//set ascending to true if non ascending input
			{
				ascending = true;
			}//if statement
		}//for loop
		if (ascending)//let user know if there was an error in input
			cout << "ERROR\n";
		size = i;
	}//while loop
}
void merge(int arr1[], int size1, int arr2[], int size2, int arr1and2[], int& size_merged) {
	int i1 = 0, i2 = 0, i3=0;
	while (i1 < size1 && i2 < size2)
	{
		arr1and2[i3++] = (arr1[i1] > arr2[i2])//element in arr1 is smaller then element arr2
			? arr1[i1++] ://if true arr1 element gets set as next element in merged array
			arr2[i2++];//if flase arr2 element gets set as next element in merged array
		//above 3 statements are using post incrementers to return the value being looked at and then incrementing.
	}
	while (i1 < size1)//if any elements in first array are left, copy them
		arr1and2[i3++] = arr1[i1++];
	while (i2 < size2)//if any elements in second array are left, copy them
		arr1and2[i3++] = arr2[i2++];
	size_merged = size1 + size2;
}
/*
test regular input
enter values for the first vector:
enter 10 numbers:
3 2 1 0
test3enter values for the second vector:
enter 10 numbers:
3 2 1 0
enter values for the third vector:
enter 10 numbers:
3 2 1 0
merged vector is:
3 3 3 2 2 2 1 1 1
test differnet cases
enter values for the first vector:
enter 10 numbers:
1 2 3 0
ERROR
test3 22 21 19 18 17 16 15 13 12 10
enter values for the second vector:
enter 10 numbers:
17 16 15 14 13 12 11 10 9 8
test10enter values for the third vector:
enter 10 numbers:
5 4 3 2 0
merged vector is:
22 21 19 18 17 17 16 16 15 15 14 13 13 12 12 11 10 10 9 8 5 4 3 2*/