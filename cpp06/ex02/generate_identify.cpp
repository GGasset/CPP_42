
#include "generate_identify.h"

int abs(int x) {return x * (1 - 2 * (x < 0));}

int xorshift()
{
	static int x = 13;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x;
}

float get_random_float()
{
	return abs(xorshift() % (int)1e6) / 1e6;
}

Base *generate(void)
{
	const size_t n_choices = 3;
	int choice = -1;
	double compound_prob = 0;
	for (int i = 0; choice < 0; i++)
	{
		if (compound_prob + (1. / n_choices) > get_random_float())
			choice = i;
		compound_prob += 1. / n_choices;
	}

	switch (choice)
	{
		case 0:
			std::cout << "generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "generated C" << std::endl;
			return new C();
		default: throw;
	}
}

void identify(Base *p)
{
	if (!p) {std::cerr << "Null base pointer function parameter" << std::endl; return;}

	Base *casted[4]; 
	casted[0] = dynamic_cast<A*>(p);
	casted[1] = dynamic_cast<B*>(p);
	casted[2] = dynamic_cast<C*>(p);
	casted[3] = (Base *)1;
	int non_null_i = -1;
	for (size_t i = 0; (size_t)casted[i] != 1; i++) if ((size_t)casted[i] > 1) non_null_i = i;

	switch (non_null_i)
	{
	case 0:
		std::cout << "A" << std::endl;
		break;
	case 1:
		std::cout << "B" << std::endl;
		break;
	case 2:
		std::cout << "C" << std::endl;
		break;
	default: throw;
	}
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}

