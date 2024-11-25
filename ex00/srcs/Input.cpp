/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:53:54 by bifernan          #+#    #+#             */
/*   Updated: 2024/11/21 17:07:00 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Input.hpp"

bool input_fits_in_int(const std::string &input)
{
	float value = 0;
	std::istringstream is(input);
	if (is >> value && value <= static_cast<float> (std::numeric_limits<int>::max()) && value >= static_cast<float> (std::numeric_limits<int>::min()))
		return true;
	return false;
}

size_t	mantissaLen(const std::string &num)
{
	size_t len(0);
	for (std::string::const_iterator it = num.begin(); it != num.end(); ++it)
	{
		if (std::isdigit(*it))
			++len;
	}
	return len;
}
Input::Input(const std::string literal): literal_(literal), type_(NOTYPE) {}

Input::Input(const Input &other)
{
	this->setLiteral(other.getLiteral());
	this->setType(other.getType());
}

Input &Input::operator=(const Input &other)
{
	if (this != &other)
		*this = Input(other);
	return *this;
}

Input::~Input() {}

//getters
std::string Input::getLiteral() const
{
	return literal_;
}

type_t Input::getType() const
{
	return type_;
}

//setters
void Input::setLiteral(const std::string literal)
{
	literal_ = literal;
}

void Input::setType(type_t type)
{
	type_ = type;	
}

//method
void Input::parseLiteral() {}
bool Input::isValid() const {
	return true;
}

std::ostream &operator<<(std::ostream &os, const Input &input)
{
	std::cout << "char: " << input.getCharMsg() << std::endl;	
	std::cout << "int: " << input.getIntMsg() << std::endl;	
	std::cout << "float: " << input.getFloatMsg() << std::endl;	
	std::cout << "double: " << input.getDoubleMsg() << std::endl;	
	return os;
}

std::string Input::getCharMsg() const
{
	return charMsg_;
}

std::string Input::getIntMsg() const
{
	return intMsg_;
}

std::string Input::getFloatMsg() const
{
	return floatMsg_;
}

std::string Input::getDoubleMsg() const
{
	return doubleMsg_;
}

void	Input::setCharMsg()
{
	if (intMsg_ == "impossible" || intVal_ < -128 || intVal_ > 127)
		charMsg_ = "impossible";
	else if (intVal_ > 31 && intVal_ < 127)
		charMsg_ = static_cast<char> (intVal_);
	else if (intVal_ < 32 || intVal_ > 126)
		charMsg_ = "Non displayable";
	else
		charMsg_ = "Impossible";
		
}

void	Input::setIntMsg()
{
	std::istringstream is(this->getLiteral());
	if (arg_is_char(literal_))
	{
		intVal_ = static_cast<int> (literal_[0]);
		std::ostringstream os1;
		os1 << this->intVal_;
		std::string s(os1.str());
		this->intMsg_ = s;
	}
	else if (input_fits_in_int(this->getLiteral()) && is >> this->intVal_)
	{
		this->intMsg_ = this->getLiteral(); 
		std::ostringstream os;
		os << this->intVal_;
		std::string s(os.str());
		this->intMsg_ = s;
	}
	else
	{
		this->intMsg_ = "impossible";
	}
}

void	Input::setFloatMsg()
{
	std::istringstream is(this->getLiteral());
	if (arg_is_char(literal_))
	{
		floatVal_ = static_cast<float> (literal_[0]);
		std::ostringstream os1;
		os1 << this->floatVal_;
		std::string s(os1.str());
		this->floatMsg_ = s;
	}
	else if (is >> this->floatVal_)
	{
		std::ostringstream os;
		os << this->floatVal_;
		std::string s(os.str());
		if (s.find(".") == std::string::npos)
			s += ".0";
		s += 'f';
		this->floatMsg_ = s;
	}
	else
	{
		if (arg_is_special(this->getLiteral()))
		{
			if (literal_ == "nan")
				floatMsg_ = "nanf";
			else if (literal_ == "inf")
				floatMsg_ = "inff";
			else if (literal_ == "+inf")
				floatMsg_ = "+inff";
			else if (literal_ == "-inf")
				floatMsg_ = "-inff";
			else
				floatMsg_ = literal_;
		}
		else if (this->literal_[0] == '-')
			this->floatMsg_ = "-inff";
		else
			this->floatMsg_ = "+inff";
	}
}

void	Input::setDoubleMsg()
{
	std::istringstream is(this->getLiteral());
	if (arg_is_char(literal_))
	{
		doubleVal_ = static_cast<double> (literal_[0]);
		std::ostringstream os1;
		os1 << this->doubleVal_;
		std::string s(os1.str());
		this->doubleMsg_ = s;
	}
	else if (is >> this->doubleVal_)
	{
		std::ostringstream os;
		os << this->doubleVal_;
		std::string s(os.str());
		if (s.find(".") == std::string::npos)
			s += ".0";
		this->doubleMsg_ = s;
	}
	else
	{
		if (arg_is_special(literal_))
		{
			if (literal_ == "nanf")
				this->doubleMsg_ = "nan";
			else if (literal_ == "inff")
				this->doubleMsg_ = "inf";
			else if (literal_ == "+inff")
				this->doubleMsg_ = "+inf";
			else if (literal_ == "-inff")
				this->doubleMsg_ = "-inf";
			else
				this->doubleMsg_ = literal_;
		}
		else if (this->literal_[0] == '-')
			this->doubleMsg_ = "-inf";
		else
			this->doubleMsg_ = "+inf";
	}
}
