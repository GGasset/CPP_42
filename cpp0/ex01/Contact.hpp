#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include "functionality.hpp"

# define COLUM_PRINT_WIDTH 10

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;

public:
	Contact();
	Contact(
		std::string _first_name, std::string _last_name,
		std::string _nickname, std::string _darkest_secret
	);
	Contact(const Contact& src);
	Contact &operator=(const Contact& src);
	~Contact();

	void print_contact();
	void print_detailed();
};

#endif