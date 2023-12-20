//File Name: gap_size.cpp
//Author: Chaim Fishman
//ID:208509349
//Course: Intro to Computer Communications
//Project: HomeWork 8 project 1. 
//Description: The User will be asked to input 2 arrays
//of up to size 80, Size will be determined by user prior
//to the input.
//The program will then check if the sequence of the second array exists
//in the first array and the variables of the first array, in the second
//array are the same distance from each other. 
//the program will then output the minimum!! gap-size of existing sequence
//if no such sequence exits -1 will be printed out.
#include <iostream>
using namespace std;
int arr_input(int* arr, int size);
int find_gap_size(int* arr1, int size1, int* arr2, int size2);
int gap_checker(int* arr1, int size1, int* arr2, int size2);
int main() {
	int big[80], small[80], size_big, size_small;
	cout << "Enter the size of big:\n";
	cin << size_big;
	arr_input(big, size_big);
	cout << "Enter the size of small:\n";
	cin << size_small;
	arr_input(big, size_small);
	cout << "Size of jump: ";
	cout << find_gap_size(big, size_big, small, size_small);
	cout << endl;
	return 0;
}
void arr_input(int* arr, int size) {
	cout << "Enter X numbers\n";
	for (int i = 0; i < size; i++) {
		cin << *(arr + i);
	}
	return;
}
int find_gap_size(int* arr1, int size1, int* arr2, int size2) {
	gap_size;
	f_size = -1;
	//find all terms in arr1 that matches first term in arr2
	for(int i = 0; i < size1-size2+1; i++)
		if (*(arr1 + i) == *arr2) {
			gap_size = gap_checker(arr1 + i, size1 - i, arr2 + 1, size2 - 1);
			if (f_size == -1) {//if we haven't changed f_size yet
				f_size = gap_size;
			}
			else if (gap_size < f_size && gap_size != -1)
				f_size = gap_size;
		}
	return f_size;
}
int gap_checker(int* arr1, int size1, int* arr2, int size2) {
	//find next element and gapsize.
	int gapsize = -1;
	for (int i = 0; i < size1; i++) {
		if (*arr1 + i == *arr2) {//if we find a first element gapsize check if hey all exist
			//check the rest of the elements of that gapsize.
			for (int j = 1; j < size2; j++) {
				//check if next gapsize is in arr
				if (*(arr1 + (i * j - 1)) != *(arr2 + j)) {
					break;
				}
				if (j + 1 == size2) {//if we have a gapsize for all arr2
					gapsize = i - 1;
				}
			}
		}
		if (gapsize > -1) {//we found smallest gapsize for this element
			break;
		}
	}
	return gapsize;
}