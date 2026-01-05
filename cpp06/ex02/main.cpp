
#include "generate_identify.h"

int main()
{
	for (size_t i = 0; i < 50; i++)
	{
		Base *generated = generate();
		identify(generated);
		identify(*generated);
	}
}

