#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = "[ Not much info here... ]";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain copy assignment called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::get_idea(size_t idea_i)
{
	if (idea_i > 100) return "Not that many things can be in here";

	return ideas[idea_i];
}

void Brain::set_idea(size_t idea_i, std::string idea)
{
	if (idea_i > 100) return;

	ideas[idea_i] = idea;
}
