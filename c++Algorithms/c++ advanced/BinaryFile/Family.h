#pragma once
#include <iostream>

class Family {
public:
	Family();
	Family(int id, std::string last_name, int members, int phone);
	Family(int id, std::string last_name, int members, int phone, int activity);
	Family operator=(Family x);

	//activity for waiting list
	void set_act(int x);
	void set_activity(int x);
	int which_activity();
	bool activity(int x);
	void print();
	//get for id
	int get_id();
	int getPhone();
	char* get_name();
private:
	int id;
	char last_name[20];
	int members;
	int phone;
	bool activities[6];
};