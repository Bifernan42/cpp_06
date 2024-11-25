#include "../includes/Input.hpp"
#include "../includes/common.hpp"
#include <cctype>
#include <cmath>
#include <string>
#include "../includes/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments : expected 1, got " << argc -1 << "!" << std::endl;
		return (1);
	}
	if (!arg_is_lawful(argv[1]))
	{
		std::cout << "Error: impossible conversion" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
