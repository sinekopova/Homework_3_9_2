#include "Fraction.h"


Fraction::Fraction(int numerator, int denominator) {
	numerator_ = numerator;
	denominator_ = denominator;
}

long double Fraction::res() {
	if (denominator_ == 0)
		throw DivisionByZeroException();
	return numerator_ / denominator_;
}

bool Fraction::operator==(Fraction other) {
	return (res() == other.res() ? true : false);
}

bool Fraction::operator!=(Fraction other) {
	return !(*this == other);
}

bool Fraction::operator<(Fraction other) {
	return (res() < other.res()) ? true : false;
}

bool Fraction::operator>(Fraction other) {
	return(other.res() < res());
}

bool Fraction::operator>=(Fraction other) {
	return !(*this < other);
}

bool Fraction::operator<=(Fraction other) {
	return !(other < *this);
}

Fraction Fraction::operator+(Fraction other) {
	Fraction fr = Fraction(numerator_*other.denominator_+other.numerator_*denominator_, denominator_*other.denominator_);
	return fr.reduce();
}

Fraction Fraction::operator-(Fraction other) {
	Fraction fr(numerator_*other.denominator_-other.numerator_*denominator_, denominator_*other.denominator_);
	return fr.reduce();
}

Fraction Fraction::operator*(Fraction other) {
	Fraction fr(numerator_*other.numerator_, denominator_*other.denominator_);
	return fr.reduce();
}

Fraction Fraction::operator/(Fraction other) {
	Fraction fr(numerator_*other.denominator_, denominator_*other.numerator_);
	return fr.reduce();
}

Fraction& Fraction::operator-() {
	numerator_ = -numerator_;
	return reduce();
}

Fraction& Fraction::operator++() {
	numerator_ = numerator_ + denominator_; 
	return reduce();
}

Fraction Fraction::operator++(int) {
	*this = reduce();
	Fraction tmp = *this;
	++(*this);
	return tmp;
}

Fraction& Fraction::operator--() {
	numerator_ = numerator_ - denominator_; 
	return reduce();
}

Fraction Fraction::operator--(int) {
	*this = reduce();
	Fraction tmp = *this;
	--(*this);
	return tmp;
}

int Fraction::getNumerator() {
	return numerator_;
}

int Fraction::getDenominator() {
	return denominator_;
}

int Fraction::NOD() {
	int num = ((denominator_ > numerator_)? denominator_ : numerator_), 
		denom = ((denominator_ > numerator_) ? numerator_ : denominator_), 
		intgr  = 0, rem = 999, nod = 1;
	
	if (denominator_ != 1 && numerator_ != 1 && denominator_ != -1 && numerator_ != -1)	{
		while ( !( rem == 0 || rem == 1 ))	{
			intgr = num / denom;
			rem = num - denom * intgr;
			nod = denom;
			num = denom;
			denom = rem;
		}
	}
	if (rem == 0)
		return nod;
	else
		return 1;
}

Fraction& Fraction::reduce() {
	int nod = NOD();
	if (nod != 1) {
		numerator_ = numerator_ / nod;
		denominator_ = denominator_ / nod;
	}
	return *this;
}

