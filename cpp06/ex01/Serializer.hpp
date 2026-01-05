
#ifndef SERIALIZER
#define SERIALIZER

#include "stdint.h"

#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(Serializer &src);
	Serializer &operator=(Serializer &src);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif

