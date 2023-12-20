//File Name: how_many_days_of_the_month
//Name: Chaim Fishman
//ID:208509349
//Description: this program will ask the user to enter
//a number 1-12 representing the month and will let the user
//know how many days are in that month
//(Febuary is assumed to be in a non-leap year)
#include <iostream>
using namespace std;
int main() {
	enum month{JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	int n;
	cout << "enter a number:\n";
	cin >> n;
//cases are grouped based on the amount of days 
//a month has in it. the n will decide which month to 
//go to.
	switch (n) 
	{
	case JAN:
	case MAR:
	case MAY:
	case JUL:
	case AUG:
	case OCT:
	case DEC:
		cout << "31 days in the month\n";
		break;
	case APR:
	case JUN:
	case SEP:
	case NOV:
		cout << "30 days in the month\n";
		break;
	case FEB:
		cout << "28 days in the month\n";
		break;
	default: 
		cout << "ERROR\n";
		break;
	}
	return 0;
}
/*
enter a number:
2
28 days in the month
enter a number:
4
30 days in the month
enter a number:
1
31 days in the month
enter a number:
13
ERROR
*/