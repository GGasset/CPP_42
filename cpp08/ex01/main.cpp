
#include "Span.hpp"
#include "cstdlib"
#include "iostream"

#define SIZE (unsigned int)1e6
int main()
{
	srand(time(NULL));
	Span span(SIZE);
	for (size_t i = 0; i < SIZE; i++) span.addNumber(rand());
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	span = Span(SIZE);
	std::vector<int> tmp;
	for (size_t i = 0; i < SIZE; i++) tmp.push_back(rand());
	span.addRange(tmp.begin(), tmp.end());
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
}

