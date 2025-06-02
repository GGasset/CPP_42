#include <iostream>

char to_upper(char c)
{
	return c + ('A' - 'a') * (c >='a' && c <='z');
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << to_upper(argv[i][j]);
		std::cout << " ";
	}
	std::cout << std::endl;
}
