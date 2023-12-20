//File Name: project4\\sorted_indices.cpp
//Author: Chaim Fishman 
//ID: 208509349
//Email: csfwny@gmail.com
//Description: user will input 6 values between 0-1, the values
//will be stored in array. a fuction will make a list of 
//of where you could find the values from least to greatest
//Created: 11/24/2020
#include <iostream>
using namespace std;
const int max_term = 6;
void sorted_list(float input[], int sorted[]);
int main() {
	float input[max_term];
	int sorted[max_term];
	cout << "enter  6 numbers between 0 and 1:\n";
	for(int i = 0; i < max_term; i++)//input 6 numbers between 0-1
	{
		cin >> input[i];
		if (input[i] <= 0 || input[i] >= 1)
		{
			cout << "ERROR\n";
			i = -1;//2ill be incremented to 1 right away.
		}
	}
	sorted_list(input, sorted);//sort the list input into list sorted
	cout << "sorted indices:\n";
	for(int i = 0; i < max_term; i++)//ou put sorted list
	{
		cout << sorted[i] << ' ';
	}
	return 0;
}
void sorted_list(float input[], int sorted[])//will return list of the order of elements (in array given in a new array)
{
	int min = 0;
	for (int i = 0; i < max_term; i++)
	{
		for (int j = 0; j < max_term; j++)//do this all the way through to find 
		{
			if (input[j] < input[min])
				min = j;
		}
		sorted[i] = min;
		input[min] = 1;//aet to 1 that way can't be minimum anymore
	}
}
/*
enter  6 numbers between 0 and 1:
.6 .5 .4 .3 .2 .1
sorted indices:
5 4 3 2 1 0
enter  6 numbers between 0 and 1:
.1 .2 .3 .4 .6 .5
sorted indices:
0 1 2 3 5 4
enter  6 numbers between 0 and 1:
.1
0
ERROR
.1 .2 .3 .4 .5 .6
sorted indices:
0 1 2 3 4 5*/