#pragma once
#include <iostream>
#include <string>

class Employee {
public:
	//constructor
	Employee(std::string, int id, int seniority, float m_pay);

	//compute Tishray salary
	float salaryAfterBonus();
	//overloads for input output operators
	friend std::istream& operator>>(std::istream& input, Employee& em);
	friend std::ostream& operator<<(std::ostream& out, Employee& em);

	//settes and getters
	void set_name();
	void set_id();
	void set_seniority();
	void set_pay(int month);//asks for monthly salary and returns annual salary. for partTime it will take in hour wage, and return it times 12 wich will be just garbage.
	
	std::string get_name();
	int get_id();
	int get_seniority();
	float get_pay();
protected:
	std::string name;
	int id;
	int seniority;
	float pay;//monthly 
};