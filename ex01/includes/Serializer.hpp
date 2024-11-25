#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
    private:
        Serializer &operator=(const Serializer &);
        Serializer(const Serializer &);
        Serializer();
    public:
        ~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif