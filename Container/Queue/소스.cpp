#include"Queue.h"
#include<queue>
#include<iostream>
void print(Queue queue)
{
	while (!queue.empty())
	{
		std::cout << queue.back()<<" ";
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

	queue2.push(6);
	queue2.push(5);
	queue2.push(4);
	queue2.push(3);
	queue2.push(2);
	queue2.push(1);
	std::cout << queue2.size() << std::endl;


	queue1.swap(queue2);
	
	print(queue1);	
	print(queue2);
	
}