#ifndef FRACTION_H
#define FRACTION_H
#include<string>
#include<iostream>


class Fraction
{
private:
	int nom;
	int denom;
public:
	Fraction(int nom, int denom);
	~Fraction();

	std::string printFract();

	const Fraction& operator+(Fraction& right);
	const Fraction& operator-(Fraction& right);
	const Fraction& operator*(Fraction& right);
	const Fraction& operator/(Fraction& right);
	const bool operator<(Fraction& right);
	const bool operator>(Fraction& right);
	Fraction& reduction(Fraction& fract);
};

int NOD(int nom, int denom);


#endif