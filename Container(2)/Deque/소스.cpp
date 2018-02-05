#include<iostream>
#include<deque>
#include"Deque.h"
#include<list>
void print(Deque<int> deque)
{
	for (Deque<int>::Iterator iter = deque.Begin(); iter != deque.End(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}
void main()
{
	Deque<int> deque2;
	deque2.PushBack(1);
	deque2.PushFront(3);
	deque2.PushFront(2);
	deque2.PushFront(5);
	deque2.PushFront(4);
	print(deque2);
}