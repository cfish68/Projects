//File name: id_check_sum.cpp
//Author: Chaim Fishman
//ID: 208509349
//Email: csfwny@gmail.com
//Description: User will enter a id number and the program will let the 
//user know if its valit by a check sum process
#include <iostream>
using namespace std;
int sum(int id);//function to add up the wanted values of id digits a*1 b*2 c*1 d*2...
void id_check_sum(int& id);
int main()
{
	int id;
	cout << "enter your ID:\n";
	do
	{
		cin >> id;
		if (id < 0)
			cout << "ERROR:\n";
	} while (id < 0);
	id_check_sum(id);//call function to get the id with the a 9th digit being the counter.
//if the first few numbers are zero use an array to represent it better.
	cout << "your full ID is:\n" << id << endl;
	return 0;
}
int sum(int id)
{
	int sum = 0;
	for (int i = 9; i > 1; i--, id/=10)//add up all the 8 digits, evey itiration we want to look at the next digit id/=10
	{
		int x = id % 10;//get value for digit wanted
		if (i % 2)//if the digit is to be mulitplied by 2
		{
			x *= 2;
			if (x > 9)//this is only relevant if digit was multiplied
				x = (x % 10) + 1;//the only possibe second digit is 1 and we want to add the first with the second.
		}
		sum += x;//add the value to sum
	}
	return 10 - sum % 10;
}
void id_check_sum(int& id)//function that takes in id and returns id with check_sum digit
{
	int check_sum=sum(id);//call function to add up wanted digits
	id = (id * 10) + check_sum;//give id the extra digit, which is the check_sum
	return;
}
/*enter your ID:
20850934
your full ID is:
208509349
enter your ID:
32446086
your full ID is:
324460864
enter your ID:
-5
ERROR:
12345678
your full ID is:
123456782*/