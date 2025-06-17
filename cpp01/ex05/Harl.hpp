
#ifndef HARL_H
# define HARL_H

#include "string"
#include "iostream"

class Harl
{
private:
	std::string levels[4];

	typedef void (Harl::* level_function)(void);
	level_function level_functions[4];
	
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl();

	void complain(std::string level);
};


#endif
