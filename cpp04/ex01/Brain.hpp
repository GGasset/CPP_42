
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "iostream"
#include "cstring"

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	~Brain();

	std::string get_idea(size_t idea_i);
	void set_idea(size_t idea_i, std::string idea);
};

#endif
