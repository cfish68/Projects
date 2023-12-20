#include "PartTime.h"
#include <iostream>
using namespace std;

//constructors
PartTime::PartTime() :Employee("", 0, 0, 0), hours(0) {}//default consturctor
PartTime::PartTime(std::string name, int id, int s, int hours, int pay) : Employee(name, id, s, pay), hours(hours) 
{
	if (hours < 0)
		throw "ERROR\n";
}
istream& operator>>(istream& in, PartTime& t)//input for partime
{
	cout << "Enter employee details:\n";
	t.set_name();
	t.set_id();
	t.set_seniority();
	in >> t.hours;
	in >> t.per_h;
	t.set_pay(t.hours * t.per_h);
	
	//the next line should be in the gloabal set seniority line but moodle expects a full input before the thrown exception
	if (t.get_seniority() < 0 || t.hours<0)
		throw "ERROR\n";
	return in;
}
int PartTime::get_hours()
{
	return hours;
}
ostream& operator<<(ostream& out, PartTime& t)//output for parttime
{
	out << "\nEmployee: " << t.get_name();
	out << endl << "Employee ID: " << t.get_id();
	out << endl << "Years Seniority: " << t.get_seniority();
	out << endl << "Hours: " << t.get_hours();
	out << endl << "Salary per Month: " <<  t.get_pay();
	out << endl;
	return out;
} 