#pragma once

#include "FractionException.h"

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int NOD();

public:
	Fraction(int numerator, int denominator);
	long double res();
	bool operator==(Fraction other);
	bool operator!=(Fraction other);
	bool operator<(Fraction other);
	bool operator>(Fraction other);
	bool operator>=(Fraction other);
	bool operator<=(Fraction other);
	Fraction operator+(Fraction other);
	Fraction operator-(Fraction other);
	Fraction operator*(Fraction other);
	Fraction operator/(Fraction other);
	Fraction& operator-();
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& reduce( );

	int getNumerator();
	int getDenominator();
};
