#include "Contact.hpp"

Contact::Contact(): 
	first_name(""), last_name(""), nickname(""), darkest_secret("")
{

}

Contact::Contact(
	std::string _first_name, std::string _last_name,
	std::string _nickname, std::string _darkest_secret
):
	first_name(_first_name), last_name(_last_name),
	nickname(_nickname), darkest_secret(_darkest_secret)
{
}

Contact::Contact(const Contact &src):
	first_name(src.first_name), last_name(src.last_name),
	nickname(src.nickname), darkest_secret(src.darkest_secret)
{
}

Contact &Contact::operator=(const Contact &src)
{
	first_name = src.first_name;
	last_name = src.last_name;
	nickname = src.nickname;
	darkest_secret = src.darkest_secret;
	return *this;
}

Contact::~Contact()
{
}

void Contact::print_contact()
{
	print_trucd_normal_spaced(first_name, COLUM_PRINT_WIDTH);
	std::cout << "|";
	print_trucd_normal_spaced(last_name, COLUM_PRINT_WIDTH);
	std::cout << "|";
	print_trucd_normal_spaced(nickname, COLUM_PRINT_WIDTH);
	std::cout << std::endl;
}

void Contact::print_detailed()
{
	std::cout 	<< "FIRST NAME: " << first_name << std::endl 
				<< "LAST NAME: " << last_name << std::endl
				<< "NICKNAME: " << nickname << std::endl
				<< "DARKEST SECRET: " << darkest_secret << std::endl;
}
