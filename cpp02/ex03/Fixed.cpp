
#include "Fixed.hpp"

Fixed::Fixed() : bytes(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	bytes = src.bytes;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	float value = fixed.toFloat();

	os << value;
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return bytes;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	bytes = raw;
}

Fixed::Fixed(const int n) : bytes( n << (sizeof(int) * 8 - fractionalBits) )
{
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
	std::cout << "float constructor called" << std::endl;

	int fractional_bit_count = sizeof(int) * 8 - fractionalBits;

	bytes = ((int)n) << fractional_bit_count;

	float tmp = n - (int)n;
	float bit_position_value = .5;
	for (size_t i = 0; i < fractional_bit_count; i++, bit_position_value /= 2)
	{
		int bit_value = tmp > bit_position_value;
		tmp -= bit_position_value * bit_value;

		bytes += bit_value << fractional_bit_count - i - 1;
	}
	
}

float Fixed::toFloat(void) const
{
	int fractional_bit_count = sizeof(int) * 8 - fractionalBits;

	int integer_value = toInt();
	float out = (float)integer_value;

	float bit_position_value = .5;
	for (size_t i = 0; i < fractional_bit_count; i++, bit_position_value /= 2)
	{
		out += bit_position_value * (bytes & (1 << fractional_bit_count - i - 1));
	}
	return out;
}

int Fixed::toInt(void) const
{
	return bytes >> sizeof(int) * 8 - fractionalBits;
}
