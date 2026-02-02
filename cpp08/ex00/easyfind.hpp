
#ifndef easy_H
#define easy_H

#include <algorithm>

template<class T>
int *easyfind(T &int_container, int find_value)
{
	typename T::iterator result = std::find(int_container.begin(), int_container.end(), find_value);

	if (result != int_container.end()) return &(*result);

	return 0;
}

#endif
