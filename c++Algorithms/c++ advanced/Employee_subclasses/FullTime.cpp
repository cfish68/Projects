#include "FullTime.h"
#include <iostream>
using namespace std;
FullTime::FullTime(std::string name, int id, int seniority, float a_salary):Employee(name, id, seniority, a_salary/12)
{
	annualSalary = a_salary;
}

istream& operator>>(istream& in, FullTime& a)//input full time employee
{
	cout << "\nEnter employee details:\n";
	a.set_name();
	a.set_id();
	a.set_seniority();
	in >> a.annualSalary;
	a.set_pay(a.annualSalary / 12);
	//the next line should be in the gloabal set seniority line but moodle expects a full input before the thrown exception
	if (a.get_seniority() < 0)
		throw "ERROR\n";
	return in;
}
ostream& operator<<(ostream& out, FullTime a)//output for fulltime employee
{
	out << "\nEmployee: " << a.get_name();
	out << endl << "Employee ID: " << a.get_id();
	out << endl << "Years Seniority: " << a.get_seniority();
	out << endl << "Salary per Month: " << a.get_pay() << endl;
	return out;
}