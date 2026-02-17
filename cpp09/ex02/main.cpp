
#include "PmergeMe.hpp"
#include "iostream"
#include <cctype>
#include <ctime>
#include <iomanip>
#include "ctime"
#include "cstdlib"

template<class T>
bool is_sorted(T nums)
{
	if (!nums.size()) return true;

	int bfr = nums[0];
	for (size_t i = 1; i < nums.size(); bfr = nums[i], i++) if (nums[i] < bfr) return false;
	return true;
}

int main(int argc, char **argv)
{
	if (argc < 3) {std::cout << "Usage: ./PmergeMe num1, num2 [, ..., numN]" << std::endl; return 0;}

	std::vector<int> vec;
	std::deque<int> dque;

	for (size_t i = 1; i < (size_t)argc; i++)
	{
		bool correct_argv = argv[i][0] != 0; // Only be correct when argv is not empty and contains only digits
		for (size_t j = 0; argv[i][j]; j++) correct_argv = correct_argv && std::isdigit(argv[i][j]);

		if (!correct_argv) {std::cout << "Invalid argv: " << argv[i] << "." << std::endl; return 0;}

		int parsed = std::atoi(argv[i]);
		for (size_t i = 0; i < vec.size() && i < dque.size(); i++) if (vec[i] == parsed) {std::cout << "Number " << argv[i] << " is duplicated." << std::endl; return 0;}

		vec.push_back(parsed);
		dque.push_back(parsed);
	}

	std::stringstream ss;
	ss << std::setprecision(3);
	ss << "Before: ";
	for (size_t i = 0; i < vec.size(); i++) ss << vec[i] << " ";
	ss << std::endl;


	std::clock_t vec_time = std::clock();
	std::vector<int> svec = ford_jonhson(vec);
	vec_time = std::clock() - vec_time;
	float vec_time_ms = vec_time / (float)CLOCKS_PER_SEC * 1000;

	std::clock_t dque_time = std::clock();
	std::deque<int> sdque = ford_jonhson(dque);
	dque_time = std::clock() - dque_time;
	float dque_time_ms = dque_time / (float)CLOCKS_PER_SEC * 1000;

	if (!is_sorted(svec)) std::cout << "vec not sorted!" << std::endl;
	if (!is_sorted(sdque)) std::cout << "deque not sorted!" << std::endl;

	ss << "After: ";
	for (size_t i = 0; i < svec.size(); i++) ss << svec[i] << " ";
	ss << std::endl;

	ss << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vec_time_ms << "ms" << std::endl;
	ss << "Time to process a range of " << argc - 1 << " elements with std::dque : " << dque_time_ms << "ms" << std::endl;

	std::cout << ss.str();
}
