//File Name: Classroom_database.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project: Homework 8.2 for Intro to Computer Communication.
//Description: This program will have the user input classrooms and store it in a database. 
//(which has the lifetime of the program.) The user will be able to add delete print search print certain codes..
//The list will be in ascending oreder as classes get added and removed.
//the maximum amount of classes able to be inputed is 50.
#include <iostream>
using namespace std;
void output_menue();
//function to output the menue simply to make the main function more readable


void newClass(int* database, int& size);
//read into this function is a pointer to the begining of
//array and the size of data in the array.
//user will be alloted to input a class that has not been inputed already.
//the maximum size is 50
//the inputed class will be inserted in correct spot to keep array in ascending order.


void delClass(int* database, int& size);
//read into this function is a pointer to the begining of the database
//and the amount of classes.
//user will input class to delete if class exits, class will be nullified
//and size will be decrementd.





//File Name: Classroom_database.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project: Homework 8.1 for Intro to Computer Communication.
//Description: This program will have the user input classroom
#include <iostream>
using namespace std;
void output_menue();
void newClass(int* database, int& size);
void delClass(int* database, int& size);
void printAll(int* database, int size);
bool searchClass(int* database, int size);
void printCode(int* database, int size);
enum choice { ADD, DELETE, SEARCH,  PRINTCODE, PRINTALL, EXIT };
int main() {
	int database[50];
	int size = 0;
	int choice;
	output_menue();
	do
	{
		cin >> choice;
		switch (choice)
		{
		case ADD:  newClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case DELETE: delClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case PRINTALL: printAll(database, size);
			cout << "Enter your next choice:\n";
			break;
		case SEARCH: (searchClass(database, size)) ? cout << "Found\n" : cout << "Not Found\n";
			cout << "Enter your next choice:\n";
			break;
		case PRINTCODE: printCode(database, size);
			cout << "Enter your next choice:\n";
			break;
		case EXIT: return 0;
		default: cout << "ERROR\n";
		}
	} while (choice!=5);
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
void newClass(int* database, int& size) 
{
	int value;
	cout << "Enter the code of the classroom to add:\n";
	cin >> value;
	int i = 0;
	for(i = 0; i < size; i++)
	{
		if (*(database + i) > value)
		{
			for (int j = size; j >= i; j--)
			{
				*(database + j) = *(database + j - 1);
			}
			break;
		}
		if (*(database + i) == value)
			return;
	}
	*(database + i) = value;
	size++;
	printAll(database, size);
}
void delClass(int* database, int& size) 
{
	int value;
	cout << "Enter the code of the classroom to delete:\n";
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (*(database + i) == value)
		{
			for (int j = i; j < size-1; j++)
			{
				*(database + j) = *(database + j + 1);
			}
			size--;
	
			break;
		}
	}
	printAll(database, size);
}
void printAll(int* database, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << *(database + i) << ' ';
	}
	cout << endl;
}
bool searchClass(int* database, int size)
{
	int value;
	cout << "Enter the code of the classroom to search for:\n";
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (value == *(database + i))
		{
			return true;
		}
	}
	return false;
}
void printCode(int* database, int size)
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

void printAll(int* database, int size);
//inputed into this function is a pointer to the begining of the array
//and its size.
//the array will output to the user the classes on the list.
bool searchClass(int* database, int size);
//inputed into this function is a pointer to the begining of the array
//and its size.
//the function iwll return true if inputed data is in the array.
void printCode(int* database, int size);
//inputed into this function is a pointer to the begining of the array
//and its size.
//the array will output to the user all the classes of selected program.
enum choice { ADD, DELETE, SEARCH,  PRINTCODE, PRINTALL, EXIT };
int main() {
	int database[50];
	int size = 0;
	int choice;
	output_menue();
	do
	{
		cin >> choice;
		switch (choice)
		{
		case ADD:  newClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case DELETE: delClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case PRINTALL: printAll(database, size);
			cout << "Enter your next choice:\n";
			break;
		case SEARCH: (searchClass(database, size)) ? cout << "Found\n" : cout << "Not Found\n";
			cout << "Enter your next choice:\n";
			break;
		case PRINTCODE: printCode(database, size);
			cout << "Enter your next choice:\n";
			break;
		case EXIT: return 0;
		default: cout << "ERROR\n";
		}
	} while (choice!=5);
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
void newClass(int* database, int& size) 
{
	int value;
	cout << "Enter the code of the classroom to add:\n";
	cin >> value;
	int i = 0;
	for(i = 0; i < size; i++)//find appropriate spot to input value
	{
		if (*(database + i) > value)
		{
			for (int j = size; j >= i; j--)//move all of elements of appropriate spot and everything on the right one spot to the right.
			{
				*(database + j) = *(database + j - 1);
			}
			break;
		}
		if (*(database + i) == value)//if input exits already exit the function.
			return;
	}
	*(database + i) = value;
	size++;
	printAll(database, size);
}
void delClass(int* database, int& size) 
{
	int value;
	cout << "Enter the code of the classroom to delete:\n";
	cin >> value;
	for (int i = 0; i < size; i++)//find where class exits
	{
		if (*(database + i) == value)//if we found the class
		{
			for (int j = i; j < size-1; j++)//delete it by moving everything on its right one to the left
			{
				*(database + j) = *(database + j + 1);
			}
			size--;
	
			break;
		}
	}
	printAll(database, size);
}
void printAll(int* database, int size)
{
	for(int i = 0; i < size; i++)//print all values stored in database
	{
		cout << *(database + i) << ' ';
	}
	cout << endl;
}
bool searchClass(int* database, int size)
{
	int value;
	cout << "Enter the code of the classroom to search for:\n";
	cin >> value;
	for (int i = 0; i < size; i++)//binary_search should've been used.
	{
		if (value == *(database + i))
		{
			return true;
		}
	}
	return false;
}
void printCode(int* database, int size)
{
	int value;
	cout << "Enter the code of the Machon:\n";
	do {
		cin >> value;
		if ((value < 10 || value > 99))//make sure input is legal
			cout << "ERROR\n";
	} while (value < 10 || value > 99);//if input was ilegal we will redo this step
		int i = 0;
	for (i; i < size; i++)
	{
		if (*(database + i) / 1000 == value)//compare to teh first 2 digits of class
		{
			break;
		}
	}
	while (*(database + i) / 1000 == value && i < size)//output all the appropritate classes.
	{
		cout << *(database + i) << ' ';
		i++;
	} 
	cout << endl;
}








//File Name: Classroom_database.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project: Homework 8.1 for Intro to Computer Communication.
//Description: This program will have the user input classroom
#include <iostream>
using namespace std;
void output_menue();
void newClass(int* database, int& size);
void delClass(int* database, int& size);
void printAll(int* database, int size);
bool searchClass(int* database, int size);
void printCode(int* database, int size);
enum choice { ADD, DELETE, SEARCH, PRINTCODE, PRINTALL, EXIT };
int main() {
	int database[50];
	int size = 0;
	int choice;
	output_menue();
	do
	{
		cin >> choice;
		switch (choice)
		{
		case ADD:  newClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case DELETE: delClass(database, size);
			cout << "Enter your next choice:\n";
			break;
		case PRINTALL: printAll(database, size);
			cout << "Enter your next choice:\n";
			break;
		case SEARCH: (searchClass(database, size)) ? cout << "Found\n" : cout << "Not Found\n";
			cout << "Enter your next choice:\n";
			break;
		case PRINTCODE: printCode(database, size);
			cout << "Enter your next choice:\n";
			break;
		case EXIT: return 0;
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
void newClass(int* database, int& size)
{
	int value;
	cout << "Enter the code of the classroom to add:\n";
	cin >> value;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (*(database + i) > value)
		{
			for (int j = size; j >= i; j--)
			{
				*(database + j) = *(database + j - 1);
			}
			break;
		}
		if (*(database + i) == value)
			return;
	}
	*(database + i) = value;
	size++;
	printAll(database, size);
}
void delClass(int* database, int& size)
{
	int value;
	cout << "Enter the code of the classroom to delete:\n";
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (*(database + i) == value)
		{
			for (int j = i; j < size - 1; j++)
			{
				*(database + j) = *(database + j + 1);
			}
			size--;

			break;
		}
	}
	printAll(database, size);
}
void printAll(int* database, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(database + i) << ' ';
	}
	cout << endl;
}
bool searchClass(int* database, int size)
{
	int value;
	cout << "Enter the code of the classroom to search for:\n";
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (value == *(database + i))
		{
			return true;
		}
	}
	return false;
}
void printCode(int* database, int size)
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