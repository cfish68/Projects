//File Name: calculate.cpp
//Author: Chaim Fishman
//ID: 208509349
//Description this program will ask the user to enter to numbers
//and a +, -, * or / operator and calculate the two numbers
//read the solution back to the user
#include <iostream>
using namespace std;
int main()
{
//intooduce enumaration for operators to make it easier
//to choose the right case later
	enum op { ADD = '+', SUB = '-', MULT = '*', DIV = '/' };
	int num1, num2;
//couldve been called op chose to call iop as a bit of 
//a play on istream
	char iop; 
	cout << "enter 2 numbers:\n";
	cin >> num1 >> num2;
	cout << "enter an operator:\n";
	cin >> iop;
	
//use iop as a chooser for the switch
//select the appropriate case ADD, SUB, MULT OR SUB
//default will be chosen if and only if the iop did not get 
//the aprropriate chararacter
	switch (iop)
	{
	case ADD:
		cout << num1 << " + " << num2  << " = "
			<< (num1 + num2) << endl;
		break;
	case SUB:
		cout << num1 << " - " << num2 << " = "
			<< (num1 - num2) << endl;
		break;
	case MULT:
		cout << num1 << " * " << num2 << " = " 
			<< (num1 * num2) << endl;
		break;
	case DIV:
		cout << num1 << " / " << num2 << " = "
			<< ((float)num1 / num2) << endl;
		break;
	default:
		cout << "ERROR\n";
	}
	return 0;
}
/*
enter 2 numbers:
9 2 /
enter an operator:
9 / 2 = 4.5
enter 2 numbers:
2 2 2
enter an operator:
ERROR
enter 2 numbers:
9 7 +
enter an operator:
9 + 7 = 16
enter 2 numbers:
9 2 -
enter an operator:
9 - 2 = 7
enter 2 numbers:
9 2 *
enter an operator:
9 * 2 = 18
*/