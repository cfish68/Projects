#include "Employee.h"
#include <iostream>
using namespace std;
Employee::Employee(std::string a, int id, int seniority, float m_pay)
{
	name = a;
	id = id;
	seniority = seniority;
	pay = m_pay;
}
//salary for the month of Tishrai
float Employee::salaryAfterBonus()
{
	if (seniority > 5)
		return pay + (0.25 * pay);
	return pay + 500;
}
istream& operator>>(std::istream& input, Employee& em)
{
	cout << "enter employee details:\n";
	input >> em.name >> em.id >> em.seniority;
	return input;
}

ostream& operator<<(std::ostream& out, Employee& em)
{
	cout << "\nEmployee: " << em.name;
	cout << endl << "Employee ID: " << em.id;
	cout << endl << "Years Seniority: " << em.seniority;
	cout << endl << "Salary per Month: " << em.pay;
	cout << endl << "After Bonus: " << em.salaryAfterBonus() << endl;
	return out;
}

//getters abd setters
void Employee::set_name() {
	cin >> name;
}
void Employee::set_id() {
	cin >> id;
}

void Employee::set_seniority() {
	cin >> seniority;
}

string Employee::get_name() {
	return name;
}
int Employee::get_id() {
	return id;
}
int Employee::get_seniority() {
	return seniority;
}
float Employee::get_pay() {
	return pay;
}
void Employee::set_pay(int month)
{
	pay = month;
}