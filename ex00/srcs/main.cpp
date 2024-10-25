#include "../includes/ScalarConverter.hpp"
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Converter : Error: invalid number of arguments, expected 1 got " << argc - 1 << "!" << std::endl;
        return (1);
    }
    std::string input = argv[1];
    char c1;
    int a;
    char c2;
    int b;
    char c3;
    std::stringstream ss(input);
    std::cout << input_get_char_number(input) << ": char num" << std::endl;
    if (input_is_signed(input) && input_has_digits(input) && input_has_one_point(input) && input_ends_with_f(input) && input_get_char_number(input) == 3) //signed float w '.'
    {
        ss >> c1 >> a >> c2 >> b >> c3;
        std::cout << c1 << std::endl;
        std::cout << a << std::endl;
        std::cout << c2 << std::endl;
        std::cout << b << std::endl;
        std::cout << c3 << std::endl;
        std::cout << "signed float" << std::endl;
    }
    else if (input_is_signed(input) && input_has_digits(input) && !input_has_one_point(input) && input_ends_with_f(input) && input_get_char_number(input) == 2) //signed float w/o '.'
    {
        ss >> c1 >> a >> c3;
        std::cout << c1 << std::endl;
        std::cout << a << std::endl;
        std::cout << c3 << std::endl;
        std::cout << "signed float" << std::endl;
    }
    else if (input_starts_with_digits(input) && input_has_digits(input) && input_has_one_point(input) && input_ends_with_f(input) && input_get_char_number(input) == 2) //unsigned float w '.'
    {
        ss >> a >> c2 >> b >> c3;
        std::cout << a << std::endl;
        std::cout << c2 << std::endl;
        std::cout << b << std::endl;
        std::cout << c3 << std::endl;
        std::cout << "unsigned float" << std::endl;
    }
    else if (input_starts_with_digits(input) && input_ends_with_f(input) && input_get_char_number(input) == 1) //unsigned float w/o '.'
    {
        ss >> a >> c3;
        std::cout << a << std::endl;
        std::cout << c3 << std::endl;
        std::cout << "unsigned float" << std::endl;
    }
    else if (input_is_signed(input) && input_ends_with_digits(input) && input_has_one_point(input) && input_get_char_number(input) == 2) //signed double w '.'
    {
         ss >> c1 >> a >> c2 >> b;
         std::cout << c1 << std::endl;
         std::cout << a << std::endl;
         std::cout << c2 << std::endl;
         std::cout << b << std::endl;
         std::cout << "signed double" << std::endl;
    }
    else if (input_starts_with_digits(input) && input_ends_with_digits(input) && input_has_one_point(input) && input_get_char_number(input) == 1) //unsigned double w '.'
    {
         ss >> a >> c2 >> b;
         std::cout << a << std::endl;
         std::cout << c2 << std::endl;
         std::cout << b << std::endl;
         std::cout << "unsigned double" << std::endl;
    }
    else if (input_is_only_digit(input)) //unsigned int
    {
      ss >> a;
      std::cout << a << std::endl;
      std::cout << "unsigned int" << std::endl;
    }
    else if (input_is_signed(input) && input_ends_with_digits(input) && input_get_char_number(input) == 0) //unsigned int
    {
      ss >> a;
      std::cout << a << std::endl;
      std::cout << "signed int" << std::endl;
    }
    else if (input_get_char_number(input) == 1)
    {
        ss >> c1;
        std::cout << c1 << std::endl;
        std::cout << "char" << std::endl;
    }
    else {

        std::cout << "Error!" << std::endl;

    }

    return 0;
}
