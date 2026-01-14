
#ifndef RPN_H
#define RPN_H

#include "queue"

int RPN(std::queue<char> inverted_polish_math_expression, int *err);
int RPN(std::stack<char> postfix_expression, int *err);

#endif

