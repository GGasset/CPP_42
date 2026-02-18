
#include "RPN.hpp"
#include <cctype>

#define IS_OP(op) (op == '+' || op == '-' || op == '*' || op == '/')
#define DIG(c) c - '0'

int RPN(std::queue<char> parsed, int &err)
{
	std::stack<int> s;

	while (parsed.size())
	{
		char c = parsed.front();
		parsed.pop();

		if (std::isdigit(c)) { s.push(DIG(c)); continue; }

		if (s.size() < 2 || !IS_OP(c)) { err = true; return 0; }

		int b = s.top();
		s.pop();

		int a = s.top();
		s.pop();

		int result = 0;
		switch (c) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '/':
			result = a / b;
			break;
		case '*':
			result = a * b;
		default:
			break;
		}
		s.push(result);
	}
	if (!s.size() || s.size() > 1) {err = true; return 0;}
	return s.top();
}
