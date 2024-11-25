#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	Input i(literal);
	i.setFloatMsg();
	i.setDoubleMsg();
	i.setIntMsg();
	i.setCharMsg();
	std::cout << i;
}
