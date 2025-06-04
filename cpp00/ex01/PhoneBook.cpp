#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contact_count(0)
{
}

PhoneBook::PhoneBook(
	Contact _contacts[MAX_CONTACTS], size_t _contact_count
): contact_count(_contact_count)
{
	for (size_t i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = _contacts[i];
}

PhoneBook::PhoneBook(const PhoneBook &src):
	contact_count(src.contact_count)
{
	for (size_t i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = src.contacts[i];	
}

PhoneBook &PhoneBook::operator=(const PhoneBook &src)
{
	contact_count = src.contact_count;

	for (size_t i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = src.contacts[i];	

	return *this;
}

PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::get_contact(size_t i)
{
	if (i >= contact_count)
		throw ;

	return contacts[i];
}

size_t PhoneBook::get_contact_count()
{
	return contact_count;
}

void PhoneBook::print_contacts()
{
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	std::stringstream ss;
	for (size_t i = 0; i < contact_count; i++)
	{
		ss << i;
		std::string str_i = ss.str();
		ss.str("");
		ss.clear();

		print_trucd_normal_spaced(str_i, COLUM_PRINT_WIDTH);
		std::cout << "|";
		contacts[i].print_contact();
	}
}

void PhoneBook::add_contact(Contact to_add)
{
	Contact tmp = contacts[0];
	for (size_t i = 1; i < MAX_CONTACTS; i++)
	{
		Contact current = contacts[i];
		contacts[i] = tmp;
		tmp = current;
	}
	contacts[0] = to_add;
	contact_count += contact_count < MAX_CONTACTS;
}
