
#ifndef SPAN_HPP
#define SPAN_HPP

#include "cstddef"
#include "vector"
#include "iterator"
#include <algorithm>
#include <exception>

class Span
{
private:
	std::vector<int> numbers;
	size_t max_size;

public:
	Span();
	Span(unsigned int size);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();

	void addNumber(int v);

	// Invalid Range results in undefined behaviour
	template<class inIt>
	void addRange(inIt begin, inIt end);

	unsigned int shortestSpan();
	unsigned int longestSpan();
};

template<class inIt>
void Span::addRange(inIt begin, inIt end)
{
	size_t n_elements = std::distance(begin, end);
	if (numbers.size() + n_elements > max_size) throw std::exception();

	while (begin != end)
	{
		numbers.push_back(*begin);
		begin++;
	}
}

#endif
