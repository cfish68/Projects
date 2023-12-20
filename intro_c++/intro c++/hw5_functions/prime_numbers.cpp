//File Name: prime_numbers.cpp
//Author: Chaim Fishman
//ID:208509349
//Email: csfwny@gmail.com
//Description: This program will take a number from user and return that number
//if its prime or the next prime above it. ig the number entered is negative
//the prime number will be random with a starting number from 10-100.
//created:11/18/2020
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
bool isPrime(int x);//check if number is prime, returns true if prime.
int findPrime(int x);//return first prime number >=x.
int main()
{
	int input;
	cout << "enter number of values:\n";
	cin >> input;
	if (input < 0)
	{
		srand((unsigned)time(NULL));
		input = rand()%90+10;
	}
	cout << "table size: " << findPrime(input) << endl;
	return 0;
}
bool isPrime(int x)
{
	int sq_x = sqrt(x) + 1;//find the sqrt so as to not waste loops
	for (int i = 2; i <= sq_x || x==0; i++)//check if devisible by i for all possibe i(2 to sq_x).
	{//(if x is 0 enter the loop and return false)
		if (x % i == 0)//if this returns true the number is not a prime.
			return false;//if its davisible this will exit the function and return not prime
	}
	return true;//if for loop was exited this will prime.
}
int findPrime(int x)
{
	while (!isPrime(x))//while x is not a prime number loop.
	{
		x++;//add 1 to x to check next possible number.
	}
	return x;
}
/*
enter number of values:
0
table size: 1
enter number of values:
-4
table size: 101
enter number of values:
-4
table size: 47
enter number of values:
49
table size: 53
enter number of values:
17
table size: 17*/