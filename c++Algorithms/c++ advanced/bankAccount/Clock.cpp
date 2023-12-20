#include "Clock.h"
#include <iomanip>
//default
Clock::Clock() : hour(0), min(0), second(0) {};
Clock::Clock(int hour) : Clock(hour, 0, 0) {};
Clock::Clock(int hour, int minute) : Clock(hour, minute, 0) {};
//constructor with all parameters.
Clock::Clock(int hour, int min, int second)//set to default if anyerrors.
{
	if (hour < 0 || hour > 24 || min < 0 || min > 59 || second < 0 || second > 59)
		throw "Wrong time format\n";
	this->hour = hour;
	this->min = min;
	this->second = second;
	
}
//copy constructor
Clock::Clock(const Clock& x)
{
	hour = x.hour;
	min = x.min;
	second = x.second;
}

//getters setters
int Clock::getHour()
{
	return hour;
}
int Clock::getMin()
{
	return min;
}
int Clock::getSecond()
{
	return second;
}
int Clock::setHour(int h)
{
	if (h < 0 || h > 24)
		throw "Wrong time format\n";
	hour = h;
}
int Clock::setMinute(int m)
{
	if (m < 0 || m > 59)
		throw "Wrong time format\n";
	min = m;
}
int Clock::setSecond(int s)
{
	if (s < 0 || s > 59)
		throw "Wrong time format\n";
	second = s;
}
//operator +=seconds
Clock Clock::operator+=(int seconds)
{
	second += seconds;
	min += second / 60;
	hour += min / 60;
	second = second % 60;
	min = min % 60;
	hour = hour % 24;
	return *this;
}
ostream& operator<<(ostream& os, Clock time)
{
	cout.fill('0');
	os << setw(2) << time.hour << ':' << setw(2) << time.min << ':' << setw(2) << time.second;
	return os;
}
istream& operator>>(istream& is, Clock& time)
{
	char s;
	is >> time.hour >> s >> time.min >> s >> time.second;
	return is;
	//add exception cases;;;;;;;;;;;;;;;;;;;;;;;;;;
}