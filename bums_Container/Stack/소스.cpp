#include"Stack.h"
#include<stack>
#include<iostream>
void print(Stack<int> stack)
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
	Stack<int> stack;
	stack.Push(1);
	std::cout << stack.Top() << std::endl;
	stack.Push(2);
	std::cout << stack.Top() << std::endl;
	stack.Push(3);
	std::cout << stack.Top() << std::endl;
	stack.Push(4);
	std::cout << stack.Top() << std::endl;
	stack.Push(5);
	std::cout << stack.Top() << std::endl;
	stack.Push(6);
	std::cout << stack.Top() << std::endl;
	stack.Push(7);
	std::cout << stack.Top() << std::endl;
	stack.Push(8);
	std::cout << stack.Top() << std::endl;
	std::cout << stack.Size() << std::endl;
	print(stack);
	stack.Pop();
	print(stack);
}