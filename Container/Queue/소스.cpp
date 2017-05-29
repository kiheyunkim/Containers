#include"Queue.h"
#include<queue>
#include<iostream>
void print(Queue queue)
{
	size_t size = queue.size();
	for (size_t index = 0; index < size; index++)
	{
		std::cout << queue.front() << " ";
		queue.pop();
	}
	std::cout << std::endl;
}

void main()
{
	Queue queue1;
	Queue queue2;
	queue1.push(1);
	queue1.push(2);
	queue1.push(3);
	queue1.push(4);
	queue1.push(5);
	queue1.push(6);
	queue1.pop();
	std::cout << queue1.size()<<std::endl;
	print(queue1);


	queue2.push(6);
	print(queue2);
	queue2.push(5);
	print(queue2);
	queue2.push(4);
	print(queue2);
	queue2.push(3);
	print(queue2);
	queue2.push(2);
	print(queue2);
	queue2.push(1);
	print(queue2);


	std::cout << queue2.size() << std::endl;

	print(queue1);	
	print(queue2);

	queue1.swap(queue2);
	
	print(queue1);
	print(queue2);
	
}