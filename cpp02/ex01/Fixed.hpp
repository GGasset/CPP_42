
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

	Fixed(const int n);
	Fixed(const float n);
	float toFloat( void ) const;
	int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

