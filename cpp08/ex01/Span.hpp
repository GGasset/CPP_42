
#ifndef SPAN_HPP
#define SPAN_HPP

#include "cstddef"
#include "vector"
#include "iterator"

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
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

#endif

