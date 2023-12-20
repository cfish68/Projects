//File Name: set_difference.cpp
//Course: Intro to Computer Science
//Author: Chaim Fishman
//ID: 208509349
//Description: Two sets will be inputed. the output will be 
//the difference of set1-set2. Same as set rules.
//Created:11/25/2020.
#include <iostream>
using namespace std;//global
const int max_sum = 6;//global variable, largest size list we will have in this program.,( to change set size simply change max_sum.)
void input(int arr[]);//function will get 6 inputs from user and place them into array that made call.
void output_difference(int arr1[], int arr2[]);//funcrtion will out put the differnece between 2 sets.
int main() {
	int set1[max_sum], set2[max_sum];
	cout << "enter first 6 numbers:\n";
	input(set1);//read in input for set1
	cout << "enter next 6 numbers:\n";
	input(set2);//read in input for set2
	cout << "set difference is:\n";
	output_difference(set1, set2);//read out difference of set1-set2
	return 0;
}
void input(int arr[])
{
	for (int i = 0; i < max_sum; i++)//read in 6 input and store them in array passed to function.
	{
		cin >> arr[i];
	}
}

void output_difference(int arr1[], int arr2[])
{
	bool empty = true;//set empty set to true. if any number will be read out, we will turn it to false.
	
	for (int i = 0; i < max_sum; i++)//look at every number in the first array
	{
		bool read_out = true;//assume number we are looking at in first set is not in second set, unless it is.
		for (int j = 0; j < max_sum; j++)//compare to every number in the second array
		{
			if (arr1[i] == arr2[j])
			{
				read_out = false;
			}//if (arr1[i] == arr2[j])
		}//for (int j = 0; j < max_sum; j++)
		if (read_out)//if this is true number looked at is not in second array
		{
			cout << arr1[i] << ' ';
			empty = false;
		}
	}//for (int i = 0; i < max_sum; i++)
	if (empty)//if this is true no numbers were read out
	{
		cout << "empty\n";
	}
}//last closing braces for function void output..
/*
test
enter first 6 numbers:
1 2 3 4 5 6
enter next 6 numbers:
6 5 4 3 2 1
set difference is:
empty
enter first 6 numbers:
1 2 3 4 5 6
enter next 6 numbers:
11 2 33 4 55 6
set difference is:
1 3 5*/