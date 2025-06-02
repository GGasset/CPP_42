#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <string>
# include <sstream>
# include <iostream>
# include "Contact.hpp"
# include "functionality.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact contacts[MAX_CONTACTS];
	size_t	contact_count;

public:
	PhoneBook();
	PhoneBook(
		Contact _contacts[MAX_CONTACTS], size_t _contact_count
	);
	PhoneBook(const PhoneBook& src);
	PhoneBook &operator=(const PhoneBook& src);
	~PhoneBook();

	Contact get_contact(size_t i);
	size_t get_contact_count();

	void print_contacts();
	void add_contact(Contact to_add);
};

#endif
