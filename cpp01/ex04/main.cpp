
#include "replace.h"

int main(int argc, char *argv[])
{
	if (argc != 4) { 
		std::cout << "Usage: ./replace filename s1 s2" << std::endl; return 0; 
	}

	if (argv[2][0] == 0) {
		std::cout << "Error: s1 must not be an empty string" << std::endl;
		return 0;
	}

	if (!std::ifstream(argv[1]).good()) {
		std::cout << "Error: file does not exist" << std::endl;
		return 0;
	}

	
}
