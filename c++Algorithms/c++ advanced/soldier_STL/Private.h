#pragma once
#include "Soldier.h"

class Private : public Soldier
{
public:
	Private();
	virtual ~Private();
	virtual std::string soldierType();
	virtual bool medal();
	virtual void print();
	//data member
	int* score;
};