#include  "replace.h"


std::string	cpp_index_replace(std::string s, size_t start, size_t replace_len, std::string _new)
{
	if (start > s.length()) start = s.length();
	if (start + replace_len > s.length()) replace_len = s.length() - start;

	std::string out;
	for (size_t i = 0; i < start; i++)							out.push_back(s[i]);
	for (size_t i = 0; i < _new.length(); i++)					out.push_back(_new[i]);
	for (size_t i = start + replace_len; i < s.length(); i++)	out.push_back(s[i]);

	return (out);
}

std::string	cpp_replace(std::string s, std::string old, std::string replacer)
{
	size_t	replace_start = 0;
	while ((replace_start = s.find(old, replace_start)) != (size_t)-1)
	{
		s = cpp_index_replace(s, replace_start, old.length(), replacer);
		replace_start += replacer.length();
	}
	return (s);
}
