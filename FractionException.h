#pragma once

#include <iostream>

class DivisionByZeroException : std::exception {
public:
	const char* what() const override { return "Деление на ноль"; };
};