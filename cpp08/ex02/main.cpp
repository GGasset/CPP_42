
#include "cstdlib"
#include "iostream"
#include "algorithm"

#include "MutantStack.hpp"

#define TYPE int

void print(const TYPE &n)
{
	std::cout << n << " ";
}

void add_one(TYPE &n)
{
	n++;
}

int main()
{
	MutantStack<TYPE> stack;
	for (size_t i = 0; i < (int)1e2; i++) stack.push(std::rand());
	
	std::for_each(stack.begin(), stack.end(), print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::for_each(stack.begin(), stack.end(), add_one);

	std::for_each(stack.begin(), stack.end(), print);
	std::cout << std::endl;

	const MutantStack<TYPE> const_stack(stack);
	MutantStack<TYPE>::const_iterator citer = const_stack.begin();
	MutantStack<TYPE>::const_iterator cend = const_stack.end();

	std::for_each(citer, cend, print);
}

