#include"Stack.h"
#include<stack>
#include<iostream>
void print(Stack stack)
{
	size_t size = stack.Size();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << stack.Top() << " ";
		stack.Pop();
	}
	std::cout << std::endl;
}

void main()
{
	std::stack<int>::container_type;
	Stack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);
	stack.Push(7);
	stack.Push(8);
	std::cout << stack.Top() << std::endl;
	print(stack);
	stack.Pop();
	print(stack);
}