//File name: perfect_numbers.cpp
//Author: Chaim Fishman
//ID:208509349
//Email: csfwny@gmail.com
//Description: Program will get user inputed number and 
//print all perfect numbers less than that number
//and will print all perfect numbers under 500.
//Created: 11/17/2020
#include <iostream>
using namespace std;
void ioprint(int input);
bool perfect(int a);
int main()
{
	cout << "enter a number:\n";
	int input;
	cin >> input;
		ioprint(input-1);//call teh function to print the perfect numbers>>hw asks for anything less then the input
		cout << endl;
		ioprint(500);//call function to print perfect numbers less then 500
	return 0;
}
void ioprint(int input)
{

	for (int i = 6; i < input; i++)
	{
		if (perfect(i))//call function check if number is perfect if it is print it
		{
			cout << i << ' ';
		}
	}
}
bool perfect(int a)//check if a number is perfect
{
	int sum = 0;
	for (int i = (a / 2) + 1; i > 1; i--)//initialization a/2 not because we don't need to check anything that more then half,+1 incase odd
	{
		
		if (!(a % i) && a != i)//if a mod i returns 0 make it true. if not make it false
			sum += a / i;//sum will equal all numbers that a is divisible by
	}
	return sum+1 == a;//+ 1 added here because not added earlier.
}
/*
note: most tests were done to check if program works but numbers were printed out in wrong oreder for moodle
enter a number:
500
6 28 496
6 28 496
enter a number:
10000
8128 496 28 6 
496 28 6 
enter a number:
2

496 28 6 
enter a number:
450
28 6 
496 28 6 
enter a number:
-15

496 28 6 
enter a number:
5

496 28 6
enter a number:
500
6 28 496
6 28 496*/