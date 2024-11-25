#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
		return (NULL);
	return (reinterpret_cast<Data *> (raw));
}
