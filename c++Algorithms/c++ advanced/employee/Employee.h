//File: this file contains the class Emplyee
//Author: Chaim Fishman
//ID: 208509349
//c++ homework 1.2
#pragma once
using namespace std;
class Employee
{
public:
	//constructors
	Employee(): id(0), name{ '\0' }, wage_p_h(0), hours_worked(0), collected_income(0), f_salary(0){};
	Employee(int snumber, char* name, float wage, int hours, float collected);
	//setter
	float salary();
	//getters
	float get_salary();
	float get_collected();
	char* ptrname();
	int get_id();

private:
	int id;
	char name[21];
	float wage_p_h;
	int hours_worked;
	float collected_income;
	float f_salary;
};