//File Name:ele_s_adder.cpp
//Author: Chaim Fishman
//ID: 208509349
//Description: This program will ask a user to enter 2 numbers
//corresponding to a variable to be used in a series of expressoins
//to be evaluated expression(secod user input) times. 
//The prgram will finally output the sum of the expressions.
//Created:11/10/2020
#include <iostream>
using namespace std;
int main() {
	int deno_expo = 1, sum = 0, numa = 1;
	int var, expcount;

	cout << "enter 2 numbers:\n";
	cin >> var;
	do
	{
		cin >> expcount;
		if (expcount <= 0)
			cout << "ERROR\n";
	} while (expcount <= 0);
//make as many expressions as the user asked for in second number entered
	for (int i = 0; i < expcount; i++, deno_expo += 2,numa *= -1)
	{
		int x = var;
//give x the value of var^exponent
		for (int j = 1; j < deno_expo; j++)
		{
			x *= var;
		}
		sum += ((float)numa / deno_expo) * x;
		
	}
	cout << sum;
	return 0;
}
/*
enter 2 numbers:
3 2
-6
check if (-)number gives correct output
enter 2 numbers:
-3 2
6 //correct!!!
enter 2 numbers:
-3
-5
ERROR
-4
ERROR
3
-42*/