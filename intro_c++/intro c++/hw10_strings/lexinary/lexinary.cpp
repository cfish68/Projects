//File Name: lexinary.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project for: hw10.3 for Intro to Computer Science
//Description: This program will you dinamic allocation 
//and strings to store a list of words in a 2d array
//and give the user options to add words, delete words
//and print words. 
//Last Modified: Too many times to keep track of!!!!!!!!!
//When you mess up with print function, may as well shoot yourself in the foot!
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
#pragma warning (disable:4996)
//newStr Add a word to the dictionary.
//Input to the function is the array lexicon, its size, and the word to be added
//.As a result of calling this function, the size of the array will increase by 1 and the new array will be in lexicographical order
//.Note, if the new word already appears in the dictionary, the array is unchanged
char** newStr(char**& ptr, int& size);
void copy_insert(char** from, char** to, int sizefrom, char* input);
char** delStr(char**& ptr, int& size, char* input);
void printAll(char** ptr, int size);
char* searchStr(char** ptr, int size, const char* string);
void printChar(char** ptr, int size);

enum choice{ADD, REMOVE, SEARCH, PRINTCHAR, PRINTALL, EXIT};

int main() {
	int size = 0, choice;
	char input[80];
	char** list = NULL;
	do
	{
		cout << "Enter 0-5:\n";
		cin >> choice;
		switch (choice)
		{
		case ADD:
			cout << "Enter the word:\n";
			list = newStr(list, size);
			printAll(list, size);
			break;
		case REMOVE:
			cout << "Enter the word to delete:\n";
			cin >> input;
			list = delStr(list, size, input);
			printAll(list, size);
			break;
		case SEARCH: cout << "Enter the word to search for:\n";
			cin >> input;
			(searchStr(list, size, input)) ? cout << "Found\n" : cout << "Not Found\n";
			break;
		case PRINTCHAR:
			 printChar(list, size);
			 break;
		case PRINTALL: printAll(list, size);
			break;
		case EXIT:
			return 0;
		}
	} while (1);
}
char** newStr(char**& ptr, int& size)
{
	char input[80];
	cin >> input;
	if (!searchStr(ptr, size, input))
	{
		char** nptr = new char*[size + 1];
		copy_insert(nptr, ptr, size, input);
		for (int i = 0; i < size; i++)
		{
			delete[] ptr[i];
		}
		delete [] ptr;
		size++;
		return nptr;
	}
	else return ptr;
	
}

void copy_insert(char** to, char** from, int sizefrom, char* input)
{
	int i = 0, j = 0;
	for (;sizefrom!=i && strcmp(*(from + i), input) < 0; i++)//copy everything belonging b4 input
	{
		int len = strlen(*(from + i)) + 1;
		*(to + j) = new char[len];
		strncpy(to[j], from[i], len);
		j++;
	}
	
	
	int len = strlen(input)+1;
	*(to + j) = new char[len];
	strncpy(*(to + j), input, len);
	j++;


	for (; i < sizefrom; i++)//copy everything belonging after input
	{
		int len = strlen(from[i])+1;
		to[j] = new char[len];
		strncpy(to[j], from[i],  len);
		j++;
	}
}

char** delStr(char**& ptr, int& size, char* input)
{
	if (searchStr(ptr, size, input))
	{
		{
			char** nptr = new char* [size - 1];
			//copy_insert(ptr, nptr, size - 1, input);
			for (int i = 0, j = 0; i < (size - 1); i++)
			{
				if (strcmp(*(ptr + i), input))
				{
					int len = strlen(*(ptr + i)) + 1;
					*(nptr + j) = new char[len];
					strncpy(*(nptr + j), *(ptr + i), len);
					j++;
				}
			}
			if (size - 1 == 0)//we need to reset it to NULL so we don't have a problem with it later.
			{
				nptr = NULL;
			}
			for (int i = 0; i < size - 1; i++)
			{
				delete[] ptr[i];
			}
			delete[] ptr;
			size--;
			return nptr;
		}
	}
	return ptr;
}
void printAll(char** ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << ' ';
	}
	cout << endl;
}
char* searchStr(char** str, const int size, const char* input)
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(str[i], input))
		{
			return *(str + i);
		}
	}
	return NULL;
}
void printChar(char** ptr, int size)
{
	char input;
	cout << "Enter the char:\n";
	cin >> input;
	for (int i = 0; i < size; i++)
	{
		if (**(ptr + i) == input)
			cout << *(ptr + i) << ' ';
	}
	cout << endl;
}
/*
Does not work for capital letters!!!
Enter 0-5:
0
Enter the word:
Hello
Hello
Enter 0-5:
0
Enter the word:
Yoni
Hello Yoni
Enter 0-5:
0
Enter the word:
do
Hello Yoni do
Enter 0-5:
1
Enter the word to delete:
do
Hello Yoni
Enter 0-5:
0
Enter the word:
remember
Hello Yoni remember
Enter 0-5:
0
Enter the word:
you
Hello Yoni remember you
Enter 0-5:
0
Enter the word:
are
Hello Yoni are remember you
Enter 0-5:
0
Enter the word:
awesome!
Hello Yoni are awesome! remember you
Enter 0-5:
5*/