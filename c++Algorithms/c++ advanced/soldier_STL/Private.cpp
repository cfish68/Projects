#include "Private.h"

//consructor
Private::Private() :Soldier()
{
    if(n_op>0)
    {
	std::cout << "enter " << n_op << " grades\n";
	score = new int[n_op];
	for (int i = 0; i < n_op; i++)
	{
		std::cin >> score[i];
	}
        
    }
}
std::string Private::soldierType()
{
	return "private";
}
Private::~Private()
{
	delete[] score;
}

void Private::print()  
{
	Soldier::print();
	if (n_op >= 0) {
		std::cout << "grades: ";
		for (int i = 0; i < n_op; i++)
			std::cout << score[i] << ' ';
	}
	std::cout << std::endl;
}
bool Private::medal()//at least 10 missions and has a 95> avarage
{
	if (n_op < 10)
		return false;
	int avarage=0;
	for (int i = 0; i < n_op; i++)
		avarage += score[i];
	avarage = avarage / n_op;
	if (avarage < 95)
		return false;
	return true;
}