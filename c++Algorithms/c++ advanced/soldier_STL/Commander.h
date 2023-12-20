#pragma once
#include "Private.h"

class Commander : public Private
{
	
public:
	Commander();
	std::string soldierType();
	bool Iscombat();
	bool medal();
	void print();
private:
	bool combat;
};