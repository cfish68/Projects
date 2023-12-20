//File: Header file Rational.h with operations
//Author: Chaim Fishman
//ID: 208509349

#pragma once
class Rational
{
public:
	//constructors
	Rational();
	Rational(int x, int y);
	Rational(const Rational& x);
//	Rational(Rational&& x);
	//destructor
	~Rational();

	//operators  *, /, +,-, =, ++, --, +=, -+
	Rational& operator=(const Rational& x);
	//Rational operator=(Rational&& x);

	Rational operator+(const Rational x);
	Rational operator-(const Rational x);
	Rational& operator+=(const Rational x);
	Rational& operator-=(const Rational x);
	Rational operator++();
	Rational operator--();
	Rational operator++(int);
	Rational operator--(int);
	Rational operator*(const Rational x);
	Rational operator/(const Rational x);


	bool operator<( Rational x);
	bool operator<=( Rational x);
	bool operator>( Rational x);
	bool operator>=( Rational x);
	bool operator==( Rational x);
	bool operator!=( Rational x);

	void print();
	float result();
	
private:
	int num;
	int denom;
	void reduction();
	
};
