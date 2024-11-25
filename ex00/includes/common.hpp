#ifndef COMMON_HPP
# define COMMON_HPP
# include <iostream>

bool arg_has_digits(const std::string &arg);

bool arg_is_signed(const std::string &arg);

bool arg_non_empty(const std::string &arg);

bool arg_contains_dot(const std::string &arg);

bool arg_contains_f(const std::string &arg);

bool arg_not_too_much_symbols(const std::string &arg);

bool arg_is_special(const std::string &arg);

bool arg_is_char(const std::string &arg);

bool arg_is_all_clear(const std::string &arg);

bool arg_is_lawful(const std::string &arg);

#endif
