
#include "iostream"

#include "RPN.hpp"

int main(int argc, char **argv)
{
	int err = 0;
	if (argc != 2) err = true;
	bool expect_space = false;
	for (size_t i = 0; !err && argv[1][i]; i++, expect_space = !expect_space)
	{
		char c = argv[1][i];
		if (expect_space) {if (c != ' ') err = true;}
		else if (c != '+' && c != '-' && c != '*' && c != '/' && (c < '0' || c > '9')) err = true;
	}
	if (err) { std::cerr << "Error" << std::endl; return 0;}

	std::queue<char> rpn_in;
	expect_space = false;
	for (size_t i = 0; argv[1][i]; i++, expect_space = !expect_space)
		if (!expect_space) rpn_in.push(argv[1][i]);

	int out = RPN(rpn_in, &err);
	if (err) { std::cerr << "Error" << std::endl; return 0;}
	std::cout << out << std::endl;
}

