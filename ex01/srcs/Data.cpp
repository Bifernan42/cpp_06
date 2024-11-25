#include "Data.hpp"

Data::Data() : amount_(10), ref_("Bananas") {}

Data::Data(int amount, const std::string &ref) : amount_(amount), ref_(ref) {}

Data::~Data() {}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->amount_ = other.amount_;
		this->ref_ = other.ref_;
	}
	return *this;
}

Data::Data(const Data &other) : amount_(other.amount_), ref_(other.ref_) {}


int Data::getAmount() const
{
	return amount_;
}

const std::string &Data::getRef() const
{
	return ref_;
}

std::ostream &operator<<(std::ostream &os, const Data &d)
{
	os << "PRODUCT :" << d.getRef() << std::endl << " QTT : " << d.getAmount() << " pcs" << std::endl;
	return os;
}

