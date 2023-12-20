#pragma once
#include "Employee.h"


class PartTime : public Employee {
public:
	//constructor
	PartTime(std::string name, int id, int s, int hours, int pay);
	//defualt constructor
	PartTime();
	int get_hours();
	friend std::istream& operator>>(std::istream& in, PartTime& t);
	friend std::ostream& operator<<(std::ostream& out, PartTime& t);
	//
private:
	int hours;
	float per_h;
};
