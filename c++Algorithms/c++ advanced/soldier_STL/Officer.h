#pragma once
#include "Soldier.h"

class Officer : public Soldier
{
public:
	Officer();
	std::string soldierType();
	int getSociometric();
	bool medal();
	void print();
private:
	int sociometric;
};