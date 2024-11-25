/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:00 by bifernan          #+#    #+#             */
/*   Updated: 2024/11/21 16:10:35 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
# define INPUT_HPP
# include <iostream>
# include <string>
# include <sstream>
# include <cctype>
# include "common.hpp"
# include <limits>

typedef enum type_e
{
	NOTYPE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} type_t;


class Input
{
	private:
		std::string literal_;
		type_t type_;
		std::string charMsg_;
		std::string intMsg_;
		std::string floatMsg_;
		std::string doubleMsg_;
		int intVal_;
		float floatVal_;
		double doubleVal_;
	public:
		Input(const std::string);
		Input(const Input &);
		Input &operator=(const Input &);
		~Input();
		
		//getters
		std::string getLiteral() const;
		type_t getType() const;

		//setters
		void setLiteral(const std::string);
		void setType(type_t);
		
		//methods
		void parseLiteral();
		bool isValid() const;

		//tests
		bool charOOB() const;

		//output part
		std::string getCharMsg() const;
		std::string getIntMsg() const;
		std::string getFloatMsg() const;
		std::string getDoubleMsg() const;

		void	setCharMsg();
		void	setIntMsg();
		void	setFloatMsg();
		void	setDoubleMsg();
};

std::ostream &operator<<(std::ostream &, const Input &);

size_t	mantissaLen(const std::string &);

#endif
