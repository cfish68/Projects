#include "Soldier.h"
#include <iostream>
using namespace std;
Soldier::Soldier()
{
	cout << "enter id, first name, last name and number Of operations\n";
	cin >> ID >> first >> last >> n_op;
}

void Soldier::print()
{
	cout << soldierType() << endl;
	cout << "ID: " << ID << endl;
	cout << "first name: " << first << endl;
	cout << "last name: " << last << endl;
	cout << "num operations: " << n_op << endl;
}
int Soldier::getSociometric()
{
	throw "ERROR: this function is just for offer soldier\n";
}

string Soldier::getFname()
{
	return first;
}
string Soldier::getName()
{
	return last;
}
int Soldier::getOp()
{
	return n_op;
}