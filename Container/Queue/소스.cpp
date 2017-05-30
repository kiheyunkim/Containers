#include"Queue.h"
#include<queue>
#include<iostream>
void print(Queue queue)
{
	size_t size = queue.Size();
	for (size_t index = 0; index < size; index++)
	{
		std::cout << queue.Front() << " ";
		queue.Pop();
	}
	std::cout << std::endl;
}

void main()
{
	Queue queue1;
	Queue queue2;
	queue1.Push(1);
	queue1.Push(2);
	queue1.Push(3);
	queue1.Push(4);
	queue1.Push(5);
	queue1.Push(6);
	queue1.Pop();
	std::cout << queue1.Size()<<std::endl;
	print(queue1);


	queue2.Push(6);
	print(queue2);
	queue2.Push(5);
	print(queue2);
	queue2.Push(4);
	print(queue2);
	queue2.Push(3);
	print(queue2);
	queue2.Push(2);
	print(queue2);
	queue2.Push(1);
	print(queue2);


	std::cout << queue2.Size() << std::endl;

	print(queue1);	
	print(queue2);

	queue1.Swap(queue2);
	
	print(queue1);
	print(queue2);
	
}