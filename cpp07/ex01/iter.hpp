
#ifndef iter_H
#define iter_H

#include "cstddef"

template<typename T>
void iter(T *arr, const size_t arr_len, void (*iter_func)(T&))
{
	if (!iter_func || !arr) throw;
	for (size_t i = 0; i < arr_len; i++) iter_func(arr[i]);
}

template<typename T>
void iter(T *arr, const size_t arr_len, void (*iter_func)(const T&))
{
	if (!iter_func || !arr) throw;
	for (size_t i = 0; i < arr_len; i++) iter_func(arr[i]);
}

#endif


