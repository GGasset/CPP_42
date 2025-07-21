
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

bool Fixed::operator>(const Fixed &other)
{
	return bytes > other.bytes;
}

bool Fixed::operator<(const Fixed &other)
{
	return bytes < other.bytes;
}

bool Fixed::operator>=(const Fixed &other)
{
	return bytes >= other.bytes;
}

bool Fixed::operator<=(const Fixed &other)
{
	return bytes <= other.bytes;
}

bool Fixed::operator==(const Fixed &other)
{
	return bytes == other.bytes;
}

bool Fixed::operator!=(const Fixed &other)
{
	return bytes != other.bytes;
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed out;

	out.setRawBits(bytes + other.bytes);
	return out;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed out;

	out.setRawBits(bytes - other.bytes);
	return out;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed out;

	out.setRawBits(bytes * other.bytes);
	return out;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed out;

	out.setRawBits(bytes / other.bytes);
	return out;
}

Fixed::Fixed(const int n) : bytes( (int)((unsigned int)n <<  fractionalBits))
{
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
	std::cout << "float constructor called" << std::endl;
	
	int out = (int)(((unsigned int)n) << fractionalBits);

	float tmp = n - (int)n;
	float bit_position_value = .5;
	for (size_t i = 0; i < fractionalBits && tmp; i++, bit_position_value /= 2)
	{
		int bit_value = tmp > bit_position_value;
		tmp -= bit_position_value * bit_value;

		out += bit_value << (fractionalBits - i - 1);
	}
	bytes = out;
}

float Fixed::toFloat(void) const
{
	float out = (float)toInt();

	float bit_position_value = .5;
	for (size_t i = 0; i < fractionalBits; i++, bit_position_value /= 2)
	{
		bool is_one = (bytes >> (fractionalBits - i - 1)) & 1;
		out += bit_position_value * is_one;
	}
	return out;
}

int Fixed::toInt(void) const
{
	return (int)((unsigned int)bytes >> fractionalBits);
}
