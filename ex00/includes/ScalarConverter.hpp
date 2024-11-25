#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include "Input.hpp"
# include "common.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &);
		ScalarConverter(const ScalarConverter &);
	public:
		~ScalarConverter();
		static void convert(const std::string &literal);
};

#endif
