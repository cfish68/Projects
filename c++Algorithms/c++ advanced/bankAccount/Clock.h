#pragma once
#include <iostream>
using namespace std;
class Clock 
{
public:
	//default
	Clock();
	Clock(int hour);
	Clock(int hour, int min);
	//constructor with all parameters.
	Clock(int hour, int min, int second);//set to default if anyerrors.

	//copy constructor
	Clock(const Clock& x);

	//getters setters
	int getHour();
	int getMin();
	int getSecond();
	int setHour(int h);
	int setMinute(int m);
	int setSecond(int s);
	//operator +=seconds
	Clock operator+=(int seconds);
	friend ostream& operator<<(ostream& os, Clock time);
	friend istream& operator>>(istream& is, Clock& time);
private:
	int hour;
	int min;
	int second;

};