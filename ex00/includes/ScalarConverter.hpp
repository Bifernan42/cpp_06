#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter& operator=(const ScalarConverter &);
        ~ScalarConverter();
    public:
        static void convert(std::string);
};

bool input_is_only_digit(const std::string &input);
bool input_is_char(const std::string &input);
bool input_has_digits(const std::string &input);
size_t input_get_char_number(const std::string &input);
bool input_ends_with_f(const std::string &input);
bool input_is_signed(const std::string &input);
bool input_has_one_point(const std::string &input);
bool input_starts_with_digits(const std::string &input);
bool input_ends_with_digits(const std::string &input);
#endif
