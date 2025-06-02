
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static std::string get_input(std::string prompt)
{
	std::cout << prompt;
	std::string input;
	std::cin >> input;
	std::cout << std::endl;

	return input;
}

static void ADD(PhoneBook *contacts)
{
	Contact to_add = Contact(
		get_input("First Name: "),
		get_input("Last Name: "),
		get_input("Nickname: "),
		get_input("Darkest Secret: ")
	);

	contacts->add_contact(to_add);
}

void SEARCH(PhoneBook contacts)
{
	if (!contacts.get_contact_count())
		return ;

	contacts.print_contacts();

	std::string raw_index = 
		get_input("Enter contact index for more info.\nIndex: ");
	
	size_t err = 0;
	for (size_t i = 0; i < raw_index.length() || err; i++) 
		err = (raw_index[i] < '0' || raw_index[i] > '9');

	long long index = std::atoll(raw_index.data());
	if (index >= (long long)contacts.get_contact_count() 
		|| index < 0 || err)
	{
		std::cout << "Invalid Index.\n" << std::endl;
		return ;
	}

	contacts.get_contact((size_t)index).print_detailed();
}

int main()
{
	PhoneBook contacts = PhoneBook();

	while (true)
	{
		std::cout << std::endl
			<< "What to do?" << std::endl 
			<< "ADD" << std::endl
			<< "SEARCH" << std::endl
			<< "EXIT" << std::endl;

		std::string decision;
		std::cin >> decision;
		
		if		(!decision.compare("ADD"))		ADD(&contacts);
		else if	(!decision.compare("SEARCH"))	SEARCH(contacts);
		else if	(!decision.compare("EXIT"))		return 1;
		else	std::cout << "INVALID INSTRUCTION" << std::endl;
	}
}
