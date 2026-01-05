
#include "Data.hpp"

Data::Data() {}
Data::Data(const Data &src)
{
	*this = src;
}

Data &Data::operator=(const Data &src)
{
	for (int i = 0; i < 7; i++) fields[i] = src.fields[i];
	return *this;
}

Data::~Data()
{

}

