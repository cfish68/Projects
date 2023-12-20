//Author: Chaim Fishman
//ID:208509349
//c++ hw 3.3


#include"String.h"
#include <iostream>
using namespace std;
int main()
{
	int i = 0;
	//size of maximum string is 29 letters
	char x[30], n;
	//input first string
	cin >> x;
	//save into first string
	String a(x);
	//input second string
	cin >> x;
	//create string b with string input
	String b(x);
	//number where to insert a into b and save in c later.
	cin >> i;
	//use the bool methods made to check which one is the correct one.
	if (a < b)
	{
		cout << "a<b\n";
	}
	else if (a > b)
	{
		cout << "a>b\n";
	}
	else cout << "a=b\n";
	//insert a into i spot in b and save it in c
	String c = b.insert(i, a);
	//letter to be inserted
	cin >> n;
	//where do you want to insert letter
	cin >> i;
	//using a natural sense of subscript insert the letter into appropriate spot
	if (c[i] != NULL)
	{
		*c[i] = n;
	    c.print();
	}
	return 0;
}