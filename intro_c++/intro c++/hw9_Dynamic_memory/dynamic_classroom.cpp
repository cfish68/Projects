//File Name: Classroom_database.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project: Homework 8.1 for Intro to Computer Communication.
//Description: This program will have the user input classroom
#include <iostream>
using namespace std;
void output_menue();
int* newClass(int*& database, int& size);


void insert(int* database, int size, int input);


bool binary_search(int* database, int size, int input, int &index);


int* delClass(int*& database, int& size);


void printAll(const int* database, const int size);


void printCode(const int* database, const int size);


enum choice { ADD, DELETE, SEARCH, PRINTCODE, PRINTALL, EXIT };
int main() {
	int size = 0;
	int* database = new int[size];
	int choice;
	output_menue();
	do
	{
		cin >> choice;
		switch (choice)
		{
		case ADD:   database = newClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case DELETE: database = delClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case PRINTALL: printAll(database, size);
			cout << "Enter your next choice:\n";
			break;
		case SEARCH:int input, garbage;
			cout << "Enter the code of the classroom to search for:\n";
			cin >> input;
			(binary_search(database, size, input, garbage)) ? cout << "Found\n" : cout << "Not Found\n";
			cout << "Enter your next choice:\n";
			break;
		case PRINTCODE: printCode(database, size);
			cout << "Enter your next choice:\n";
			break;
		case EXIT:// delete[]database;
			return 0;
		default: cout << "ERROR\n";
		}
	} while (choice != 5);
}
void output_menue() {
	cout << "Enter 0 to add a new classroom.\n" <<
		"Enter 1 to delete a hybrid classroom." <<
		"\nEnter 2 to search for a specific classroom." <<
		"\nEnter 3 to print all the classsrooms for a specific Machon." <<
		"\nEnter 4 to print all the hybrid classrooms." <<
		"\nEnter 5 to exit.\n" <<
		"Enter your choice:\n";

}
int* newClass(int*& database, int& size)
{
	int input;
	cout << "Enter the code of the classroom to add:\n";
	cin >> input;
	int garbage;
	if (binary_search(database, size, input, garbage) == false)
	{
		int* oldDatabase = database;
		database = new int[size + 1];
		for (int i = 0; i < size; i++)//copy oldDatabase
		{
			*(database + i) = *(oldDatabase + i);
		}
		delete[]oldDatabase;//after done copying delete the old data base.
	//insert new hybrid classroom into new array
		insert(database, size, input);
		size++;
	}
	printAll(database, size);
	return database;
}

int* delClass(int*& database, int& size)
{
	int input, index=0;
	cout << "Enter the code of the classroom to delete:\n";
	cin >> input;
	if (binary_search(database, size, input, index))
	{
		int* oldDatabase = database;
		database = new int[size - 1];
		for (int i = 0, j = 0; j < size-1; i++, j++)//copy oldDatabase
		{
			if (i==index)
			{
				i++;
			}
			*(database + j) = *(oldDatabase + i);
		}
		delete[]oldDatabase;
			size--;
	}
	printAll(database, size);
	return database;
}

bool binary_search(int* database, int size, const int input, int& index) {
	int lower = 0, upper = size - 1;
	while (lower <= upper) {
		int middle = (lower + upper) / 2;
		index = middle;
		// item is middle element
		if (input == *(database + middle))
		{
			return true;
		}
		// search upper half
		if (input > *(database + middle))
			lower = middle + 1;

		// search lower half
		if (input < *(database + middle))
			upper = middle - 1;

	}
	return false;
}

void insert(int* database, int size, int input)
{
	int i;
	for (i = 0; i < size; i++)//find where input belongs in sorted array.
	{
		if (*(database + i) > input)
		{
			for (int j = size; j >= i; j--)//once you've found where input blongs make space for it.
			{
				*(database + j) = *(database + j - 1);
			}
			break; //leave the outer for loop so i does not get incremented after we've made space for it.
		}
	}
	*(database + i) = input;//save input into space made for it.
}


void printAll(const int* database, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(database + i) << ' ';
	}
	cout << endl;
}
void printCode(const int* database, const int size)
{
	int value;
	cout << "Enter the code of the Machon:\n";
	do {
		cin >> value;
		if ((value < 10 || value > 99))
			cout << "ERROR\n";
	} while (value < 10 || value > 99);
	int i = 0;
	for (i; i < size; i++)
	{
		if (*(database + i) / 1000 == value)
		{
			break;
		}
	}
	while (*(database + i) / 1000 == value && i < size)
	{
		cout << *(database + i) << ' ';
		i++;
	}
	cout << endl;
}


/*

22222
11111 22222 33333 44444
Enter your next choice:
3
Enter the code of the Machon:
555
ERROR
55

Enter your next choice:
1
Enter the code of the classroom to delete:
33333
11111 22222 44444
Enter your next choice:
1
Enter the code of the classroom to delete:
33333
11111 22222 44444
Enter your next choice:
4
11111 22222 44444
Enter your next choice:
2
Enter the code of the classroom to search for:
11111
Found
Enter your next choice:
1
Enter the code of the classroom to delete:
11111
22222 44444
Enter your next choice:
0
Enter the code of the classroom to add:
12345
12345 22222 44444
Enter your next choice:*/