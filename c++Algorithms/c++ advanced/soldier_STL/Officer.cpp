#include "Officer.h"

Officer::Officer() :Soldier()
{
	std::cout << "enter number of sociometric score\n";
	std::cin >> sociometric;
}
int Officer::getSociometric()
{
	return sociometric;
}
std::string Officer::soldierType()
{
	return "officer";
}

bool Officer::medal()
{
	if (n_op <= 2)
		return false;
	if (sociometric >= 92)
	{
	
		return true;
	}
		return false;
}
void Officer::print(){
	Soldier::print();
	std::cout << "sociometric score: " << sociometric << std::endl;
}