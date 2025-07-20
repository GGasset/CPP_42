
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
};


#endif

