//File Name: project3\\delete_repeats.cpp
//Author: Chaim Fishman
//ID: 208509349
//Email: csfwny@gmail.com
//Descrription: user will input up to 100 values. 
//program will return to user all values entered minus the numbers that were re-entered.
//and will let the user know how many values are in returned array.
//Created: 11/24/2020
#include <iostream>
using namespace std;
const int max_size = 100;//maximum size we should have array.
void del_repeats(int arr1[], int& size);
int input(int arr[]);//give me the input for array
int main() {
	int size=0;
	int iVec[max_size] = {0};//input set all elements to 0
	cout << "enter up to 100  values, to stop enter 0:\n";
	for (int i = 0; i < 500; i++)
	{
		cin >> iVec[i];
		if (iVec[i] == 0)
			break;
		size++;
		
	}
	//size = input(iVec);//function will return the size and elemets to array iVec  (maxsize is global.)
	del_repeats(iVec, size);
	cout << "the new vector is:\n";
	int j = 0;
	for (int i = 0; i < size; i++, j++)//repeat are zero so skip 0 and print out value till you print out the remaining values
	{
		while (iVec[j] == 0)
			j++;
		cout << iVec[j] << ' ';
	}
	cout << "\nnumber of elements: " << size << endl;
	return 0;
}
int input(int arr[]) {
	int size = 0;
	for (int i = 0; i < 500 && arr[i - 1] != 0; i++)
	{
		cin >> arr[i];
		size++;
	}
	return size;
}
void del_repeats(int arr[], int& size)//set all repeats to 0 
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				arr[i] = 0;
				counter++;
				break;
			}

		}
	}
	size -= counter;
	return; 
}

/*enter up to 100  values, to stop enter 0:
1 1 1 1 1 0
the new vector is:
1
number of elements: 1
enter up to 100  values, to stop enter 0:
2 8 9 6 4 1 4 5 8 4 5 9 6 5 8 4 7 0
the new vector is:
2 8 9 6 4 1 5 7
number of elements: 8*/