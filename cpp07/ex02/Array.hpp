
#ifndef array_H
#define array_H

#include "cstddef"
#include "algorithm"

template<typename T>
class Array
{
private:
	T *ptr;
	size_t len;

public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &src);
	Array &operator=(const Array<T> &src);
	~Array();

	T &operator[](size_t i);

	size_t size() const;
};

template<typename T>
Array<T>::Array()
{
	len = 0;
	ptr = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	len = (size_t)n;
	ptr = new T[len];
}

template<typename T>
Array<T>::Array(const Array<T> &src)
{
	len = 0;
	ptr = 0;
	*this = src;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	if (ptr == src.ptr) return *this;

	this->~Array();
	len = src.size();
	ptr = new T[len];
	for (size_t i = 0; i < len; i++) ptr[i] = src.ptr[i];
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] ptr;
	ptr = 0;
	len = 0;
}

template<typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= len || !ptr) throw std::exception();
	return ptr[i];
}

template<typename T>
size_t Array<T>::size() const
{
	return len;
}

#endif

