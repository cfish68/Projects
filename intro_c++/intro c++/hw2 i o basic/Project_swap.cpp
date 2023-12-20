//File Name: Swap.cpp.
//Author: Chaim Fishman.
//ID:208509349.
//Assignment:1.2
//Description: Program will read 2 numbers read 
//them out swap them and read them out again.
//Last Changed: 10/27/2020
#include <iostream>
using namespace std;
int main()
{
	int x, y;
	int temp;
	cout << "enter two numbers:\n";
	cin >> x >> y;
	cout << "x=" << x << " ,y=" << y << endl;
	//swap x and y using temp as storage.
	temp = x;
	x = y;
	y = temp;
	cout << "x=" << x << " ,y=" << 3 << endl;
	return 0;
}
/*enter two numbers:
3 5
x=3 ,y=5
x=5 ,y=3
program works as it does what I want it to do.
*/