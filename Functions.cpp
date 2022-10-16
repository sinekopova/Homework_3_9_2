#include "Functions.h"

Fraction createFraction(int cnt) {

	int num, denom = 0;

	std::cout << "введите числитель дроби " << cnt << " : ";
	std::cin >> num;
	while (denom == 0) {
		std::cout << "введите знаменатель дроби " << cnt << " : ";
		std::cin >> denom;	

		if (denom == 0)
			std::cout << "знаменатель не может быть равен 0!";
	}

	return Fraction(num, denom);
}

std::string getFractionString(Fraction fr) {
	return std::to_string(fr.getNumerator()) + "/" + std::to_string(fr.getDenominator());
}