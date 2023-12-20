//filename:even_or_odd.cpp
//Name: Chaim Fishman 
//ID:208509349
//description: this program will take in a number (under 3 digits) 
//and will tell the user if the numbers he entered are both even 
//both odd or both odd and even.
//Last modified:11/2/2020
#include <iostream>
using namespace std;
int main() {
	int num, units, tens;
//I made a mistake the first time I compiled this program where 
//I put a one instead of zero in in an if statement so 
//deemed this necessary.
	int odd = 1, even = 0;
	cout << "enter a number:" << endl;
	cin >> num;
//Check if num equals a legal number paramater less then 100 set
//by homework and less less then 0 then and equal to 0 can't be
//even or odd
	if (num >= 100 || num <= 0)
	{
		cout << "ERROR" << endl;
	}
//To save program run time only go into next if
//statements if num is correct number
	else {
		//get the value of the ones digit
		units = num % 10;
		//get teh vlaue of the tens digit
		tens = num / 10;
		//if they are both even
		if (units % 2 == even && tens % 2 == even)
		{
			cout << "even digits only" << endl
				<< (units * tens) << endl;
		}
		//if they are both odd
		if (units % 2 == odd && tens % 2 == odd)
		{
			cout << "odd digits only" << endl
				<< (units + tens) << endl;
		}
		//if one is odd and one is even
		if (units % 2 == even && tens % 2 == odd ||
			units % 2 == odd && tens % 2 == even)
			cout << "mixed number" << endl;
	}
}
/*check different possibilities to make sure program
runs correctly.
enter a number:
225
ERROR
enter a number:
25
mixed number
enter a number:
42
even digits only
8
enter a number:
0
ERROR
enter a number:
-22
ERROR
enter a number:
31
odd digits only
4

*/