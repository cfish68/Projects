//File Name: smallest_m_largest.cpp
//Author: Chaim Fishman
//ID:208509349
//Description: this program will ask for 3 numbers as
//input and tell the user the order of the numbers
//from smallest to largest
//Last Modified: 11/3/2020
#include <iostream>
using namespace std;
int main() {
	int num1, num2, num3, smallest, middle, biggest;
	cout << "enter 3 numbers: " << endl;
	cin >> num1 >> num2 >> num3;
//3*2*1 possiblities muct be met
	if (num1 < num2)//a<b
	{
		if (num2 < num3)//a<b<c
		{
			smallest = num1;
			middle = num2;
			biggest = num3;
		}
		else//b>c
		{
			if (num1 < num3)//a<c<b
			{
				smallest = num1;
				middle = num3;
				biggest = num2;
			}
			else//c<a<b
			{
				smallest = num3;
				middle = num1;
				biggest = num2;
			}
		}
	}
	else//b<a
	{
		if (num1 < num3)//b<a<c
		{
			//num2num1num3
			smallest = num2;
			middle = num1;
			biggest = num3;
		}
		else//a>c
			if (num2 < num3) {
				//bca
				smallest = num2;
				middle = num3;
				biggest = num1;
			}
			else
			{
				smallest = num3;
				middle = num2;
				biggest = num1;
				
			}
			
	}
	cout << smallest << " " << middle << " " << biggest << endl;
	//system("pause");
	return 0;
}
/*
enter 3 numbers:
2 9 4
2 4 9
enter 3 numbers:
7 5 4
4 5 7
enter 3 numbers:
1 2 3
1 2 3
enter 3 numbers:
3 1 2
1 2 3*/
