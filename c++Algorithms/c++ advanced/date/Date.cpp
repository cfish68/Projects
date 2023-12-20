#include <iostream>
using namespace std;

#include "Date.h"
//Date::Date() :day(1), month(1), year(1920) {};
//constructor passed all paramaters
Date::Date(int d, int m, int y)
{
	if (d < 1 || d>30)
	{
		cout << "Error day\n";
			d = 1;
	}
	if (m < 0 || m>12)
	{
		cout << "Error month\n";
		m = 1;
	}
	
	if (y < 1920 || y>2099)
	{
		cout << "Error year\n";
		y = 1920;
	}
	day = d;
	month = m;
	year = y;
	return;
}
Date::Date(int d)
{
    Date(d, 1, 1);
    return;
}
Date::Date(int d, int m)
{
    
    Date(d, m, 1);
    return;
}

//copy
Date::Date(const Date& x)
{
	day = x.day;
	month = x.month;
	year = x.year;
}


void Date::setDate(int d, int m, int y)
{
	//if any of the inputs are illegal don't do anything
	if (d < 1 || d>30)
	{
		cout << "Error day\n";
		return;
	}
	if (m < 1 || m>12)
	{
		cout << "Error month\n";
		return;
	}
	if (y < 1920 || y>2099)
	{
		cout << "Error year\n";
		return;
	}
	//if we didn't enter the if statement above setDate
	day = d;
	month = m;
	year = y;
	return;
}

//auto ++ --
//pre
Date Date::operator++()
{
	if (day == 30)
	{
		if (month == 12)
		{
			//if day is 30 and month is 12
			//and year is 2099
			if (year == 2099)
			{
				cout << "no more days to add\n";
				return *this;
			}
			//year is not 2099
			year++;
			day = 1;
			month = 1;
			return *this;
		}
		//if day 30 and month is not 12 
		day = 1;
		month++;
		return *this;
	}
	//if none are at the limit
	day++;
	return *this;
}

Date Date::operator--()
{
	if (day == 1)
	{
		if (month == 1)
		{
			//if day is 1 and month is 1
			//and year is 1920
			if (year == 1920)
			{
				cout << "no more days to remove\n";
				return *this;
			}
			//year is not 1920
			year--;
			day = 30;
			month = 12;
			return *this;
		}
		//if day 1 and month is not 1 
		day = 30;
		month--;
		return *this;
	}
	//if none are at the limit
	day--;
	return *this;
}

//post op
Date Date::operator++(int)
{
	Date temp = *this;
	if (day == 30)
	{
		if (month == 12)
		{
			//if day is 30 and month is 12
			//and year is 2099
			if (year == 2099)
			{
				cout << "no more days to add\n";
				return *this;//nothing changed
			}
			//year is not 2099
			year++;
			day = 1;
			month = 1;
			return temp;
		}
		//if day 30 and month is not 12 
		day = 1;
		month++;
		return temp;
	}
	//if none are at the limit
	day++;
	return temp;

}

Date Date::operator--(int)
{
	Date temp = *this;
	if (day == 1)
	{
		if (month == 1)
		{
			//if day is 1 and month is 1
			//and year is 1920
			if (year == 1920)
			{
				cout << "no more days to add\n";
				return *this;//nothing changed
			}
			//year is not 1920
			year--;
			day = 30;
			month = 12;
			return temp;
		}
		//if day 1 and month is not 11 
		day = 30;
		month--;
		return temp;
	}
	//if none are at the limit
	day--;
	return temp;

}
Date Date::operator+=(int days)
{
	//not exact but close enough if too many days was entered don't do anything.
	if (days > ((2099 - year) * 360))
	{
		cout << "ERROR\n";
		return *this;
	}
	//this is certainly not efficient. but its a nice trick
	for (int i = 0; i < days; i++)
	{
		(*this)++;
	}
	return *this;
}

//comparison operators
bool Date::operator>(const Date x)const 
{
	if (year > x.year)
		return true;
	if (year == x.year && month > x.month)
		return true;
	if (year == x.year && month == x.month && day > x.day)
		return true;
	//if reached this point the bool should retrun false
	return false;
}
bool Date::operator<(const Date x)const
{
	if (year < x.year)
		return true;
	if (year == x.year && month < x.month)
		return true;
	if (year == x.year && month == x.month && day < x.day)
		return true;
	//if reached this point the bool should retrun false
	return false;
}
bool Date::operator==(const Date x)const
{
	//if they are equal
	if (day == x.day && month == x.month && year == x.year)
		return true;
	//if not equal
	return false;
}

//print method
void Date::print()
{
	//since the its highly unlikely for the date to be illegal as you can't give
	//this class illegal values just print out date
	cout << day << '/' << month << '/' << year << '\n';
	return;
}