//File Name: recursive_AB.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project For: Intro to Computer Science homework 11.1
//Description: This program wil read in a number from the user and use a recursive 
//function to print out the amount of a and b's that the number called for
//ex: for 4 aaaabbbb.
#include <iostream>
using namespace std;
void printABs(int x);
int main() {
	int num;
	cout << "enter a number:" << endl;
	cin >> num;
	printABs(num);
	return 0;
}
void printABs(int x)
{	
	if(x > 0)
	cout << 'a';
	if (x > 0)//will terminate the recursion when base case will equal one.
		printABs(x - 1);//call function recursively going closer to base case each time
	if(x > 0)
	cout << 'b';

}
/*enter a number:
15
aaaaaaaaaaaaaaabbbbbbbbbbbbbbb
enter a number:
1
ab*/