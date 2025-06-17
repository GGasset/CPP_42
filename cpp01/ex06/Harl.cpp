#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl; 
}

//(void (*)(void))
Harl::Harl()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	level_functions[0] = &Harl::debug;
	level_functions[1] = &Harl::info;
	level_functions[2] = &Harl::warning;
	level_functions[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	size_t i = 0;
	for (; i < 4 && levels[i] != level; i++) {}

	Harl::level_function func;
	
	switch (i)
	{
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	case 0:
		std::cout << "[ " << levels[0] << " ]" << std::endl;
		func = level_functions[0];
		(this->*func)();
	case 1:
		std::cout << "[ " << levels[1] << " ]" << std::endl;
		func = level_functions[1];
		(this->*func)();
	case 2:
		std::cout << "[ " << levels[2] << " ]" << std::endl;
		func = level_functions[2];
		(this->*func)();
	case 3:
		std::cout << "[ " << levels[3] << " ]" << std::endl;
		func = level_functions[3];
		(this->*func)();		
	}

}
