
#ifndef whatever_HPP
#define whatever_HPP

template<typename t>
void swap(t &a, t &b)
{
	t tmp = a;
	a = b;
	b = tmp;
}

template <typename t>
t min(t a, t b)
{
	if (a < b) return a;
	else return b;
}

template<typename t>
t max(t a, t b)
{
	if (a > b) return a;
	else return b;
}

#endif

