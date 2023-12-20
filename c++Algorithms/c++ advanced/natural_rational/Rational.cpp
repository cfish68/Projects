//File: operations for Rational.h
//Author: Chaim Fishman
//ID: 2208509349

#include "Rational.h"
#include <iostream>
using namespace std;
//constructors
//no arguments
Rational::Rational() : num(0), denom(1) {};
//both arguments
Rational::Rational(int x, int y)
{
	if (x == 0)
	{
		num = 0;
		denom = 1;
		return;
	}
	if(y==0)
	{
		cout << "ERROR\n";
		y = 1;
	}
	num = x; denom = y;
}

//copy constructor
Rational::Rational(const Rational& x)
{ 
	num = x.num;
	denom = x.denom;
}

//move constructor
//Rational::Rational(Rational&& x) 
//{
//	cout << "in move\n";
//	num = x.num;
//	denom = x.denom;
//	return; 
//}
//destructor..no dyynamically allocated memory..
Rational::~Rational() { 
	
	return;
}

//operators  *, /, +,-, =, ++, --, +=, -+

//copy assignment
Rational& Rational::operator=(const Rational& x)
{
	num = x.num;
	denom = x.denom;
	return *this;
}
//move assignment
//Rational Rational::operator=(Rational&& x)
//{
//	cout << "\nin move\n";
//	Rational(x);
//	return *this;
//}

Rational Rational::operator+(Rational x)
{
	Rational result;
	int a, b, c, d;
	a = num, b = denom, c = x.num, d = x.denom;
	result.num = (a * d) + (c * b);
	result.denom = (b * d);

	result.reduction();
	return result;
}
Rational Rational::operator-(Rational x)
{
	Rational result;
	int a, b, c, d;
	a = num, b = denom, c = x.num, d = x.denom;
	result.num = (a * d) - (c * b);
	result.denom = (b * d);

	result.reduction();
	return result;

}
Rational& Rational::operator+=(Rational x)
{
	Rational t= *this + x;
	return *this = t;
}
Rational& Rational::operator-=(Rational x)
{
	Rational y = *this - x;
	return *this= y;
}

//auto increment operators
Rational Rational::operator++()
{
	Rational one(1, 1);
	one = *this + one;
	return *this = one;
	
}
//pre decrement
Rational Rational::operator--()
{
	Rational one(1, 1);
	return *this = *this - one;
	
}
//post increment
Rational Rational::operator++(int)
{
	Rational r = *this;
	Rational one(1, 1);
	*this = *this + one;
	return r;
}
Rational Rational::operator--(int)
{
	Rational r = *this;
	Rational one(1, 1);
	*this = *this - one;
	return r;
}


Rational Rational::operator*(const Rational x)
{
	int numa = num * x.num;
	int denoma = denom * x.denom;
	Rational t(numa, denoma);
	t.reduction();
	return t;
}
Rational Rational::operator/(const Rational x)
{
	//undefined to devide by zero
	if (x.num == 0)
	{
		cout << "ERROR\n";
		return *this;
	}
	int numa = num * x.denom;
	int denoma = denom * x.num;
	Rational t(numa, denoma);
	t.reduction();
	return t;
}


bool Rational::operator<(Rational x)
{
	if (result() < x.result())
	{
		return true;
	}
	return false;
}
bool Rational::operator<=( Rational x)
{
	if (result() <= x.result())
	{
		return true;
	}
	return false;
}
bool Rational::operator>( Rational x)
{
	if (result() > x.result())
	{
		return true;
	}
	return false;
}
bool Rational::operator>=( Rational x)
{
	if (result() >= x.result())
	{
		return true;
	}
	return false;
}
bool Rational::operator==( Rational x)
{
	if (result() == x.result())
	{
		return true;
	}
	return false;
}
bool Rational::operator!=( Rational x)
{
	if (result() != x.result())
	{
		return true;
	}
	return false;
}


//print method
void Rational::print()
{
	reduction();
	//if denom = 1 print out the num
	if (denom == 1)
	{
		cout << num;
		return;
	}
	cout << num << '/' << denom;
}
void Rational::reduction()
{
	int n = num, d = denom;
	//if both numarator and denom are (-) change to (+) as it is (+)
	if ((n < 0) && (d < 0))
	{
		n *= -1;
		d *= -1;
	}
	//finds the larger between num. and denom.
	int max = (n > d) ? n : d;

	//iteratively reduces from the value of half the larger down to 2
	for (int i = max; i >= 2; i--)
	{
		if ((n % i == 0) && (d % i == 0))
		{
			n = n / i;   //reducing num and denom by the factor each time
			d = d / i;
		}
	}
	num = n;
	denom = d;
}
float Rational::result()
{
	return (float(num) / denom);
}