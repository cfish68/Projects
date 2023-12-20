//Author: Chaim Fishman
//ID: 208509349

#pragma once
class Date
{
public:
//	Date();
    Date(int d);
    Date(int d, int m);
	Date(int d, int m, int y);
	//copy
	Date(const Date& x);
	//change the date
	void setDate(int d, int m, int y);

	//auto increment decrement by one day
	//pre
	Date operator++();
	Date operator--();
	//post opertor
	Date operator++(int);
	Date operator--(int);

	//+= operator
	Date operator+=(int days);

	//comparison operators
	bool operator>(const Date x)const;
	bool operator<(const Date x)const;
	bool operator==(const Date x)const;
	
	//print method
	void print();
private:
	int day;
	int month;
	int year;
};
