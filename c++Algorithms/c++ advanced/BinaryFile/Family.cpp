#include "Family.h"
#include <iostream>
Family::Family()
{
	id = 0;
	members = 0;
	phone = 0;
	std::string name(20, ' ');
	name.copy(last_name, 20, 0);
	for (int i = 0; i < 6; i++)
		activities[i] = false;
}

Family::Family(int id, std::string last_name1, int members, int phone)
	:id(id), members(members), phone(phone)
{
	strcpy_s(last_name, last_name1.c_str());
	for (int i = 0; i < 6; i++)
		activities[i] = false;
}

Family Family::operator=(Family x)
{
	id = x.id;
	strcpy_s(last_name, x.last_name);
	members = x.members;
	phone = x.phone;
	for (int i = 0; i < 6; i++)
		activities[i] = x.activities[i];

	return Family();
}


void Family::set_act(int x)
{
	for (int i = 0; i < 6; i++)
	{
		activities[i] = false;
	}
	activities[x - 1] = true;
}

void Family::set_activity(int x)
{
	activities[x - 1] = true;
}

int Family::which_activity()
{
	
	for (int i = 0; i < 6; i++)
		if (activities[i] == true)
			return (i + 1);
	return 0;
}

bool Family::activity(int x)
{
	return activities[x - 1];
}

void Family::print()
{
	std::cout << last_name << " NUMBER OF PERSONS: " << members << " PHONE: " << phone << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << ' ';
		(activities[i]) ? std::cout << 'Y' : std::cout << 'N';
	}
	std::cout << std::endl;
}

int Family::get_id()
{
	return id;
}

int Family::getPhone()
{
	return phone;
}

char* Family::get_name()
{
	return last_name;
}
