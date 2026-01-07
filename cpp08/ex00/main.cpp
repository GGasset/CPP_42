
#include "iostream"
#include "vector"

#include "easyfind.hpp"

int main()
{
	std::vector<int> collection;
	for (size_t i = 1; i < 8; i++) collection.push_back(i);

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << i << ": ";
		int *find_result = easyfind(collection, i);
		if (find_result) std::cout << "found!";
		else std::cout << "not found.";
		std::cout << std::endl;
	}
}

