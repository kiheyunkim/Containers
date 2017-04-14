#include"Stack.h"
#include<stack>
#include<iostream>
void print(Stack stack)
{
	size_t size = stack.size();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}

void main()
{
	std::stack<int>::container_type;
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	std::cout << stack.GetAddr() << std::endl;
	print(stack);
	print(stack);
}