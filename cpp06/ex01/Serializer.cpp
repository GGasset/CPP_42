#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(Serializer &src) {*this = src;}
Serializer &Serializer::operator=(Serializer &src) { return src;}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (uintptr_t)ptr;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (Data *)raw;
}

