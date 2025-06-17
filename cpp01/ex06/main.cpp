
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1) return 0;

	Harl he;
	std::string level = argv[1];
	
	he.complain(level);
}
