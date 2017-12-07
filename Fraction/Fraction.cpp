#include"Fraction.h"


Fraction::Fraction(int nom, int denom)
{
	if (denom != 0)
	{
		this->nom = nom;
		this->denom = denom;
	}
	else
	{
		exit(0);
	}
}

Fraction::~Fraction()
{
}



std::string Fraction::printFract()
{
	if (denom != 1)
	{
		std::string temp = std::to_string(nom) + "/" + std::to_string(denom);
		return temp;
	}
	else
	{
		std::string temp = std::to_string(nom);
	}
}

const Fraction & Fraction::operator+(Fraction & right)
{
	Fraction temp(nom*right.denom + right.nom*denom, denom*right.denom);
	return reduction(temp);
}
const Fraction & Fraction::operator-(Fraction & right)
{
	Fraction temp(nom*right.denom - right.nom*denom, denom*right.denom);
	return reduction(temp);
}
const Fraction & Fraction::operator*(Fraction & right)
{
	Fraction temp(nom*right.nom, denom*right.denom);
	return reduction(temp);
}
const Fraction & Fraction::operator/(Fraction & right)
{
	Fraction temp(nom*right.denom, denom*right.nom);
	return reduction(temp);
}

const bool Fraction::operator<(Fraction& right)
{
	if (nom*right.denom < right.nom * denom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool Fraction::operator>(Fraction& right)
{
	if (nom*right.denom > right.nom * denom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Fraction & Fraction::reduction(Fraction& fract)
{
	int nod = NOD(fract.nom, fract.denom);
	fract.nom /= nod;
	fract.denom /= nod;
	return fract;
}

int NOD(int nom, int denom)
{
	int min;
	if (nom < denom)
	{
		min = nom;
	}
	else
	{
		min = denom;
	}

	while (min > 1)
	{
		if (nom%min == 0 && denom%min == 0)
		{
			return min;
		}
		min--;
	}

	return 1;
}