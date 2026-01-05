
#include "iostream"

#include "Serializer.hpp"

int main()
{
	Data d;

	std::cout << "Original pointer: " << &d << std::endl;
	std::cout << "Serialized and deserialized: " << Serializer::deserialize(Serializer::serialize(&d)) << std::endl;
}

