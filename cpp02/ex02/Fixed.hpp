
#ifndef Fixed_hpp
# define Fixed_hpp

#include "iostream"

class Fixed
{
private:
	int bytes;
	static const int fractionalBits = 8;	

public:
	Fixed();

	
	Fixed(const Fixed& src);
	Fixed &operator=(const Fixed& src);	
	~Fixed();
	
	int getRawBits( void ) const;
	void setRawBits(int const raw);

	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);

	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	// Pre increment (++x) increments and returns *this
	Fixed &operator++();
	Fixed &operator--();

	// Post increment (x++) returns a copy of the object before the increment
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &max(const Fixed &a, const Fixed &b);

	Fixed(const int n);
	Fixed(const float n);
	float toFloat( void ) const;
	int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

