
#include "functionality.hpp"

// Last printed char will be a '.' if its truncated
static void print_trucd(std::string s, size_t max_len)
{
	std::string::iterator iter = s.begin();
	for (size_t i = 0; i < max_len; i++, iter++)
	{
		if (i == max_len - 1 && iter != s.end())
			std::cout << ".";
		else
			std::cout << *iter;
		if (iter == s.end())
			break;
	}
}

void print_trucd_normal_spaced(std::string s, size_t max_len)
{
	size_t len = s.length();

	size_t left_spaces = 0;
	if (len < max_len)
	{
		size_t len_diff = max_len - len;
		left_spaces = len_diff;
	}
	for (size_t i = 0; i < left_spaces; i++)
		std::cout << " ";
	print_trucd(s, max_len);
}
