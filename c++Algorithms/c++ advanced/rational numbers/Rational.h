#pragma once

using namespace std;
class Rational {
public:
	//constructors
	//If no paramators were chosen set value of rational to 0
	Rational() : s_num(0), s_denom(1) {};
	Rational(int x, int y);

	//getters and setters
	void setNumerator(int numerator);
	void setDenominator(int denominator);
	int getNumerator();
	int getDenominator();
	void print();

	Rational add(Rational& x);
	bool equal(Rational& x);
private:
	int s_num;
	int s_denom;
	int r_num;
	int r_denom;
	void reduction();
};
