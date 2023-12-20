//Author:Chaim Fishman
//this program does not have a whole lot of commenting
//the hw have been missing information or giving me the student
//wrong information making it very difficult to make this program


#include "Account.h"
#include "Clock.h"
#include <string>
//constructors
Account::Account() : accountNumber(0), code(0), balance(0), mail() {};
Account::Account(int num, int c): accountNumber(num), code(c){};
Account::Account(int num, int c, double b, string mail)
{
	
	
	if (c < 1000 || c > 9999)
		throw "ERROR: code must be of 4 digits!\n";
	if (mail.find('@') == -1)
	{
		throw "ERROR: email must contain @!\n";
	}
	if (mail.find(".com") == -1 && mail.find(".co.il") == -1)
	{
		throw "ERROR: email must end at .com or .co.il!\n";
	}
	accountNumber = num;
	code = c;
	balance = b;
	this->mail = mail;
}
int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

//get and set
double Account::getBalance()
{
	return balance;
}
int Account::getAccountNumber()
{
	return accountNumber;
}
int Account::getCode()
{
	return code;
}
void Account::setNumber(int n)
{
	accountNumber = n;//the main checks for uniquness
}
istream& operator>>(istream& in, Account& x)
{
	string t;
	in >> x.accountNumber >> x.code;
	cin >> t;
	if (x.code < 1000 || x.code > 9999)
		throw "ERROR: code must be of 4 digits!\n";
	if (t.find('@') == -1)
	{
		throw "ERROR: email must contain @!\n";
	}
	if (t.find(".com") == -1 && t.find(".co.il") == -1)
	{
		throw "ERROR: email must end at .com or .co.il!\n";
	}
	x.mail = t;
	return in;
}

//mothods
int Account::withdraw(int nis)
{

	if (balance - nis < 600)
			throw "ERROR: cannot have less than - 6000 NIS!\n";
			
		if (nis < 1)
			throw "ERROR: cannot withdraw less than 1 NIS!\n";
			
		if (nis > 2500)
			throw "ERROR: cannot withdraw more than 2500 NIS!\n";
	
		balance -= nis;
		sumWithdraw += nis;
		return balance;
	
	
}
int Account::deposit(int nis)
{


		if (nis < 1)
			throw "ERROR: Cannot deposit less than 1 NIS!\n";
		if (nis > 10000)
			throw "ERROR: cannot deposit more than 10000 NIS!\n";
		balance += nis;
		sumDeposit += nis;
		return balance;
	
}

//static members (members kept globally for this class)
int Account::getSumWithdraw()
{
	return sumWithdraw;
}
int Account::getSumDeposit()
{
	return sumDeposit;
}