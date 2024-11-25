#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base *generate(void)
{
	std::srand(std::time(0));
	int value = std::rand() % 3;
	if (value == 0)
		return new A();
	else if (value == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	try {
		if (dynamic_cast<A *>(p))
			std::cout << "type is A class" << std::endl;
		else if (dynamic_cast<B *>(p))
			std::cout << "type is B class" << std::endl;
		else if (dynamic_cast<C *>(p))
			std::cout << "type is C class" << std::endl;
		else
			std::cout << "unknown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void identify(Base& p)
{
	try {
		if (dynamic_cast<A *>(&p))
			std::cout << "type is A class" << std::endl;
		else if (dynamic_cast<B *>(&p))
			std::cout << "type is B class" << std::endl;
		else if (dynamic_cast<C *>(&p))
			std::cout << "type is C class" << std::endl;
		else
			std::cout << "unknown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
