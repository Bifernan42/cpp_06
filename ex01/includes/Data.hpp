#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class Data
{
	private:
		int amount_;
		std::string ref_;
	public:
        	Data();
        	~Data();
        	Data &operator=(const Data &);
        	Data(const Data &);
		Data(int amount, const std::string &ref);
		int getAmount() const;
		const std::string &getRef() const;
};

std::ostream &operator<<(std::ostream &os, const Data &d);

#endif
