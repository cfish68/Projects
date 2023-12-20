//File Name: project 2\\repetition_in_array.cpp
//Author: Chaim Fishman
//ID:208509349
//Email: csfwny@gmail.com
//Description: Program will ask for two lists and compare the 
//second list to the first list and tell the user how many times
//the second list is repeated in the first list
//Created: 11/24/2020
#include <iostream>
using namespace std;
void input_size(int& input, int al_size);//will input size from userand make sure its legal
void arr_input(int arr[], int size);//will take input for array values from user
int main() {
	int counter = 0;
	int vector1[500], vector2[100];//declare arrays as hw specified
	int vector1_size, vector2_size;
	cout << "enter size of first array:\n";
	input_size(vector1_size, 500);//will input size from user and make sure its legal
	cout << "enter first array values:\n";
	arr_input(vector1, vector1_size);//will take input for array values from user
	cout << "enter size of second array:\n";
	input_size(vector2_size, 100);//will input size from user and make sure its legal
	cout << "enter second array values:\n";
	arr_input(vector2, vector2_size);
	for (int i = 0, j = 0; i < vector1_size; i++)//if the loop reached the end of the first inputed arr we finished.
	{
		if (vector1[i] == vector2[j])//if input from both vlaues being looked at are equal
		{
			j++;//look at the next number of given arr
			if (j == vector2_size)//if we compared the last given inputs already 
			{
				counter++;//arr1 has another sequence that matches arr2
				j = 0;//start from the beginging  of second arr again
				if (vector1[i] == vector2[j])//when sequnce is true vlaue being looked at might be first value of next sequence
				{
					j = 1;//hw bening tricky and allowing sequence to start with last number of last sequence
				}
			}
		}
		else if(vector1[i] == vector2[0])//if values matched but they stopeed matching we want the second arr to be looked at from begining.
		{
			j = 1;
		}
		else
			j = 0;
	}
	cout << "result: " << counter << " times\n";
	return 0;
}
void input_size(int& input, int al_size)
{
	do
	{
		cin >> input;
		if (input > al_size || input < 0)//can't have a negative sized arr. and we most certainly do not want to have an arr bigger then the slot in memory given to it.
			cout << "ERROR\n";
	} while (input > al_size || input < 0);
}
void arr_input(int arr[], int size)
{
	for (int i = 0; i < size; i++)//will have user enter values for arr an apprpriate amount of times set earlier by the user.
	{
		cin >> arr[i];
	}
}
/*enter size of first array:
9
enter first array values:
1 2 3 1 2 3 1 2 3
enter size of second array:
1 2 3
enter second array values:
result: 3 times
enter size of first array:
15
enter first array values:
1 2 3 1 2 1 2 1 2 3 1 2 3
1 2
enter size of second array:
3
enter second array values:
1 2 3
result: 3 times
enter size of first array:
501
ERROR
-15
ERROR
10
enter first array values:
1 2 2 2 1 1 1 2
1
2
enter size of second array:
2
enter second array values:
1 2
result: 3 times
*/