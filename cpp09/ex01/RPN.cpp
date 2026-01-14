
#include "RPN.hpp"

#define ERR() {*err = true; return 0;}
#define EXPECT_NBR(nbr) if (nbr < '0' || nbr > '9') ERR();
#define EXPECT_OP(op) if (op != '+' && op != '-' && op != '*' && op != '/') ERR();
#define DIG(c) c - '0'; EXPECT_NBR(c);

#define DEQUEUE(queue, var) var = queue.front(); queue.pop();
#define UNSTACK(queue, var)

int RPN(std::queue<char> in, int *err)
{
	if (!err) throw;
	*err = 0;
	if (in.size() < 3) ERR();

	char tmp;
	DEQUEUE(in, tmp);
	int out = DIG(tmp);

	while (in.size())
	{
		DEQUEUE(in, tmp);
		int operand = DIG(tmp);

		if (!in.size()) ERR();

		DEQUEUE(in, tmp);
		EXPECT_OP(tmp);
		char op = tmp;

		switch (op)
		{
		case '+':
			out += operand;
			break;
		case '-':
			out -= operand;
			break;
		case '*':
			out *= operand;
			break;
		case '/':
			if (!operand) ERR();
			out /= operand;
			break;
		default: throw;
		};
	}
	return out;
}

