#include "../includes/ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <string>

ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &other)
 {
     (void)other;
 }

 ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
     (void)other;
     return *this;
 }

 ScalarConverter::~ScalarConverter() {}

 void ScalarConverter::convert(std::string num)
 {
     (void)num;
 }

 bool input_is_only_digit(const std::string &input)
 {
     if (input.find_first_not_of("0123456789") == std::string::npos)
     {
         std::cout << "input is only digits" << std::endl;
         return true;
     }
     return false;
 }

 bool input_has_one_point(const std::string &input)
 {
     size_t pos = input.find_first_of(".");
     if ((pos == input.find_last_of(".")) && pos != std::string::npos)
     {
         std::cout << "input has exactly one point" << std::endl;
         return true;
     }
     return false;
 }

 bool input_is_signed(const std::string &input)
 {
     if ((input.front() == '+') || (input.front() == '-'))
     {
         std::cout << "input is signed" << std::endl;
         return true;
     }
     return false;
 }

 bool input_ends_with_f(const std::string &input)
 {
     if (input.back() == 'f')
     {
         std::cout << "input ends with f" << std::endl;
         return true;
     }
     return false;
 }

 size_t input_get_char_number(const std::string &input)
 {
     size_t n = 0;
     for (std::string::const_iterator it = input.begin() ; it != input.end() ; ++it)
     {
            if (!std::isdigit(*it))
                ++n;
     }
     return n;
 }

bool input_has_digits(const std::string &input)
{
    if (input.find_first_of("0123456789") != std::string::npos)
    {
        std::cout << "input has digits" << std::endl;
        return true;
    }
    return false;
}

bool input_is_char(const std::string &input)
{
    if (input.length() == 1 && input_has_digits(input) == false)
    {
        std::cout << "input is char" << std::endl;
        return true;
    }
    return false;
}

bool input_starts_with_digits(const std::string &input)
{
    if (input.find_first_of("0123456789") == 0)
    {
        std::cout << "input starts with digits" << std::endl;
        return true;
    }
    return false;
}

bool input_ends_with_digits(const std::string &input)
{
    if (input.find_last_of("0123456789") == input.length() - 1)
    {
        std::cout << "input ends with digits" << std::endl;
        return true;

    }
    return false;
}
