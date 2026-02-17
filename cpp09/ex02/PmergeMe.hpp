
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "vector"
#include "deque"
#include "sstream"
#include "iostream"
#include <algorithm>
#include <iterator>
#include <vector>

// Pair index, arr and larger of each pair

class p
{
	size_t i[2];

public:
	size_t &operator[](size_t i);
};


template<class container, typename T>
void add_one(T &value)
{
	value++;
}

template<class container, typename T>
void insert_shift(container &c, T value, size_t pos)
{
	if (pos == c.size()) {c.push_back(value); return;}
	std::for_each(c.begin() + pos, c.end(), add_one<container, T>);
	c.insert(c.begin() + pos, value);
}

template<class container, typename T>
size_t index_find(container &c, T val)
{
	return (size_t)std::distance(c.begin(), std::find(c.begin(), c.end(), val));
}


std::vector<int> ford_jonhson(std::vector<int> nums);
std::deque<int> ford_jonhson(std::deque<int> nums);


#endif
