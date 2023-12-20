#pragma once
#include <iostream>
using namespace std;

class Account
{
public:
	//constructors
	Account();
	Account(int num, int c);
	Account(int num, int c, double b, string mail);
	
	//get and set
	int getAccountNumber();
	int getCode();
	double getBalance();
	void setNumber(int n);
	friend istream& operator>>(istream& is, Account& x);

	//mothods
	int withdraw(int nis);
	int deposit(int nis);

	
	static int getSumWithdraw();
	static int getSumDeposit();

private:
	int accountNumber;
	int code;
	double balance;
	string mail;
	static int sumWithdraw;
	static int sumDeposit;
};