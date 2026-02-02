
#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <vector>

Span::Span()
{
	max_size = 0;
}

Span::Span(unsigned int size)
{
	numbers.reserve(size);
	max_size = size;
}

Span::Span(const Span &src)
{
	*this = Span();
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	numbers = src.numbers;
	max_size = src.max_size;
	return *this;
}

Span::~Span()
{
	numbers.clear();
	max_size = 0;
}

void Span::addNumber(int v)
{
	if (numbers.size() + 1 > max_size) throw std::exception();
	numbers.push_back(v);
}

unsigned int abs(long x) { return (unsigned int)(x * (1 - 2 * (x < 0))); }

unsigned int Span::shortestSpan()
{
	if (numbers.size() <= 1) throw std::exception();

	std::vector<int> tmp = numbers;
	std::sort(tmp.begin(), tmp.end());

	int prev = tmp[0];
	unsigned int out = (unsigned int)-1;
	for (std::vector<int>::iterator it = ++tmp.begin(); it != tmp.end(); prev = *it, it++)
	{
		unsigned int span = abs((long)prev - (long)*it);
		if (span < out) out = span;
	}
	return out;
}

unsigned int Span::longestSpan()
{
	if (numbers.size() <= 1) throw  std::exception();

	unsigned int out = *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());
	return out;
}
