#pragma once
#include "Employee.h"

class FullTime : public Employee
{
public:
	//constructors
	FullTime(std::string name, int id, int seniority, float a_salary);
	//default constructor, defined here. in .h file
	FullTime():Employee("", 0, 0, 0), annualSalary(0) {};

	//getters and setters as necessary not implementing till it might be necessary
	
	//Tishrai salary is already made in parent class

	//overload iostream operators << >> for input and output
	friend std::istream& operator>>(std::istream& in, FullTime& a);
	friend std::ostream& operator<<(std::ostream& out, FullTime a);
private:
	float annualSalary;
};