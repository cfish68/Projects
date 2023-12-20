#pragma once
#include <iostream>

class Soldier
{
public:
	Soldier();//intializes data memebers
	virtual ~Soldier() {};
	virtual bool medal()=0; //checks if soldier is entitled for a metal
	virtual void print();
	virtual std::string soldierType() = 0;
	//getters
	std::string getFname();
	std::string getName();
	virtual int getSociometric();
	virtual bool Iscombat() { return false; };
	int getOp();
protected:
	int ID;
	std::string first;
	std::string last;
	int n_op;
};