//File: "Rational"
//Author: Chaim Fishman
//Id: 208509349
//This file should be associated with "Rational.h" as it 
//contains the mothhods for the object in that file.

#include "Rational.h"
#include <iostream>
using namespace std;
//constructor for num and denom.
Rational::Rational(int x, int y)
{
    s_num = x;
    //if denominator chosen is 0, set to 1 as specified by homework.
    (y == 0) ? s_denom = 1 : s_denom = y;
    return;
}
//getters and setters
void Rational::setNumerator(int numerator)
{
    s_num = numerator;

}
void Rational::setDenominator(int denominator)
{
    (denominator == 0) ? s_denom = 1 : s_denom = denominator;
    //this takes into assumption numerator was set first.
    //set the reduced form.
    reduction();
}
int Rational::getDenominator()
{
    return s_denom;
}
int Rational::getNumerator()
{
    return s_num;
}

//functions
bool Rational::equal(Rational& x)
{
    float a, b;
    a = ((float)s_num / s_denom);
    b = ((float)x.getNumerator() / x.getDenominator());
    if (a == b) {
        return true;
    }
    return false;
}
Rational Rational::add(Rational& x)
{
    Rational result;
    int a, b, c, d;
    a = this->r_num, b = this->r_denom, c = x.getNumerator(), d = x.getDenominator();
    result.s_num = (a * d) + (c * b);
    result.s_denom = (b * d);
     
    //the hw not wasnt't so understandable about when to print reduced and when not so had to do this next step.
    result.reduction();
    result.s_num = result.r_num;
    result.s_denom = result.r_denom;
    return result;
}
void Rational::print()
{
    cout << s_num << '/' << s_denom << ' ';
    return;
}
void Rational::reduction()
{
    int n = s_num, d = s_denom;
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
    r_num = n;
    r_denom = d;
}