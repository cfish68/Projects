//File: this file contains the main Employee
//Author: Chaim Fishman
//ID: 208509349
//c++ homework 1.2
#include "Employee.h"
#include <iostream>
using namespace std;
int main() {
	Employee highest_salary, minimum_sum;
	int id;
	char name[21];
	float wage_p_h;
	int hours_worked;
	float collected_income;
	float f_salary;
	//while user does not input 0 for id continue reading Empoyees

	cout << "enter details, to end enter 0:\n";
	while (true)
	{
		cin >> id >> name >> wage_p_h >> hours_worked >> collected_income;
		if (id == 0) break;
		if (id < 0 || wage_p_h < 0 || hours_worked < 0 || collected_income < 0)
		{
			cout << "ERROR\n";
				continue;
		}
		Employee temp(id, name, wage_p_h, hours_worked, collected_income);
		//chose to do this here for conviniece. I think it should really be within intialization.
		float sal = temp.get_salary();
		if (sal > highest_salary.get_salary())
			highest_salary = temp;
		if (minimum_sum.get_collected() > collected_income)
			minimum_sum = temp;
		//this assumes everyone collected. otherwise we would need to save the first entry before the loop
		if (minimum_sum.get_collected() == 0)
			minimum_sum = temp;

	}
	cout << "minimum sum: " << minimum_sum.get_collected() << ' ' << minimum_sum.ptrname() << ' ' <<  minimum_sum.get_id() << endl;
	cout << "highest salary:" << highest_salary.get_salary() << ' ' << highest_salary.ptrname() << ' ' << highest_salary.get_id();
	return 0;
}