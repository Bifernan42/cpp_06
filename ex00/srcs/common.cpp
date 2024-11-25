#include "../includes/common.hpp"

bool arg_has_digits(const std::string &arg)
{
	return (arg.find_first_of("0123456789") != std::string::npos);
}

bool arg_is_signed(const std::string &arg)
{
	return (arg[0] == '+' || arg[0] == '-');
}

bool arg_non_empty(const std::string &arg)
{
	return (!arg.empty());
}

bool arg_contains_dot(const std::string &arg)
{
	return (arg.find_first_of(".") != std::string::npos);
}

bool arg_contains_f(const std::string &arg)
{
	return (arg.find_first_of("f") != std::string::npos);
}

bool arg_not_too_much_symbols(const std::string &arg)
{
	int nan = 0;
	bool is_signed = arg_is_signed(arg);
	bool has_f = false;
	bool has_dot = false;
	for (size_t i = 0; i < arg.size(); ++i)
	{
		if (!std::isdigit(arg[i]))
		{
			if (arg[i] == 'f' && i == arg.size() - 1)
				has_f = true;
			if (arg[i] == '.' && i != 0 && std::isdigit(arg[i + 1]))
				has_dot = true;
			++nan;
		}
	}
	int nan_max = is_signed ? 3 : 2;
	if (nan > nan_max)
		return false;
	if (nan == nan_max)
		return has_f && has_dot;
	if (nan == nan_max - 1)
		return has_f || has_dot;
	return true;
}

bool arg_is_special(const std::string &arg)
{
	return (arg == "nan" || arg == "nanf" || arg == "inf" || arg == "+inf" || arg == "-inf" || arg == "inff" || arg == "+inff" || arg == "-inff");
}

bool arg_is_char(const std::string &arg)
{
	return (arg.size() == 1 && !std::isdigit(arg[0]));
}

bool arg_is_all_clear(const std::string &arg)
{
	return (((arg_has_digits(arg) && arg_not_too_much_symbols(arg)) || arg_is_char(arg)) && arg_non_empty(arg));
}

bool arg_is_lawful(const std::string &arg)
{
	return (arg_is_special(arg) || arg_is_all_clear(arg));
}

