#include <iostream>

#include <windows.h>

#include "Fraction.h"
#include "Functions.h"
#include "FractionException.h"

int main() {


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction fr1 = createFraction(1);
	Fraction fr2 = createFraction(2);

	std::cout << getFractionString(fr1) << " + " << getFractionString(fr2) << " = " << getFractionString(fr1 + fr2) << std::endl;
	std::cout << getFractionString(fr1) << " - " << getFractionString(fr2) << " = " << getFractionString(fr1 - fr2) << std::endl;
	std::cout << getFractionString(fr1) << " * " << getFractionString(fr2) << " = " << getFractionString(fr1 * fr2) << std::endl;
	std::cout << getFractionString(fr1) << " / " << getFractionString(fr2) << " = " << getFractionString(fr1 / fr2) << std::endl;
	std::cout << "++" << getFractionString(fr1) << " * " << getFractionString(fr2) << " = " << getFractionString(++fr1 * fr2) << std::endl;
	std::cout << "значение дроби 1 : " << getFractionString(fr1) << std::endl;
	std::cout << getFractionString(fr1) << "--" << " * " << getFractionString(fr2) << " = " << getFractionString(fr1-- * fr2) << std::endl;
	std::cout << "значение дроби 1 : " << getFractionString(fr1) << std::endl;

	return 0;
}