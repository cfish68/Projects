#include "Commander.h"


//constructor
Commander::Commander() :Private()
{
	std::cout << "enter 1 if the soldier is combat and 0 if not\n";
	int n;
	std::cin >> n;
	if (n == 0)
		combat = false;
	else
		combat = true;
}
std::string Commander::soldierType()
{
	return "commander";
}
bool Commander::Iscombat()
{
	return combat;
}

bool Commander::medal()
{
	if (n_op < 7)
		return false;
	int avarage = 0;
	for (int i = 0; i < n_op; i++)
		avarage += score[i];
	avarage = avarage / n_op;
	if (avarage < 90)
		return false;

	return true;
}
void Commander::print()
{
	Private::print();
	std::cout << "combat: ";
	if (combat == true)
		std::cout << "yes\n";
	else
		std::cout << "no\n";
}