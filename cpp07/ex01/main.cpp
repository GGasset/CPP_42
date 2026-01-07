
#include "iostream"

#include "iter.hpp"

template<typename T>
void print_val(T &val)
{
	std::cout << val << " ";
}

template<typename T>
void print_const_val(const T &val)
{
	std::cout << val << " ";
}

int main()
{
	const size_t len = 20;
	short *arr = new short[len];
	for (size_t i = 0; i < len; i++) arr[i] = i * 3000;

	iter(arr, len, print_val<short>);
	std::cout << std::endl;

	iter(arr, len, print_const_val<short>);
	std::cout << std::endl;

	delete[] arr;
}

