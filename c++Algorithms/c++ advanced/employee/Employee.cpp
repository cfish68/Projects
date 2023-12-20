//File: this file contains the methods Employee
//Author: Chaim Fishman
//ID: 208509349
//c++ homework 1.2
#include "Employee.h"
#include <cstring>
using namespace std;
//constructors
Employee::Employee(int snumber, char* Name, float wage, int hours, float collected)
{
	id = snumber;
	strcpy(name, Name);
	wage_p_h = wage;
	hours_worked = hours;
	collected_income = collected;
	f_salary=0;
	f_salary = salary();
}


float Employee::salary()
{
	float p = 0.10;
	float x = collected_income;
	//add commission based on chart.
	if (x > 1000)
	{
		f_salary = (1000 * p);
		p += 0.05;
		x -= 1000;
	}
	if (x > 1000)
	{
		f_salary += (1000 * p);
		p += 0.05;
		x -= 1000;
	}
	if (x > 2000)
	{
		f_salary += (2000 * p);
		p += 0.10;
		x -= 2000;
	}
	if (x > 1000)
	{
		f_salary += (1000 * p);
		p += 0.10;
		x -= 1000;
	}
	f_salary += (x * p);
	//add base salary.
	f_salary += (hours_worked * wage_p_h);
	return f_salary;
}

//getter
float Employee::get_salary()
{
	return f_salary;
}

float Employee::get_collected()
{
	return collected_income;
}

char* Employee::ptrname()
{
	char* n;
	n = name;
	return n;
}
int Employee::get_id()
{
	return id;
}
