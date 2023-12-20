//File Name: HW_One_Uno.cpp
//Author: Chaim Fishmank
//ID: 208509349
//Assignment: 1.1
//Description: Program Takes 2 numbers from user (a and b) and uses the formula (5a+3)/(6b+2)=answer.

#include <iostream>
using namespace std;
int main()
{
	int a, b;
	float answer;
	cout << "enter two numbers:" << endl;
	cin >> a >> b;
//use 5.0 and 6.0 so answer will be with a floating point.
	answer = (5.0 * a + 3) / (6.0 * b + 2);
	cout << "c=" << answer << endl;
	return 0;
}
/*Check if program gives correct output: 
enter two numbers:
2 0
c=6.5
check a scenerio that might not work:
0 0
c=1.5
Program works in both scenerios and does what I want it to do.*/