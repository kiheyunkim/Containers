#include<iostream>
#include<deque>
#include"Deque.h"
void print(Deque deque)
{
	for (Deque::iterator iter = deque.begin(); iter != deque.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}
void main()
{
	std::deque<int> deque;
	std::deque<int>::iterator riter;
	deque.push_back(1);
	deque.push_back(2);
	deque.at(1)=6;
	std::cout << deque.at(1) << std::endl;
	std::deque<int>::d
	Deque deque2;
	deque2.push_back(1);
	deque2.push_front(3);
	deque2.push_front(2);
	deque2.push_front(5);
	deque2.push_front(4);
	print(deque2);
}