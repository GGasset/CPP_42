
#ifndef easy_H
#define easy_H

template<class T>
int *easyfind(T &int_container, int find_value)
{
	for (size_t i = 0; i < int_container.size(); i++) if (int_container[i] == find_value) return &int_container[i];
	return 0;
}

#endif

