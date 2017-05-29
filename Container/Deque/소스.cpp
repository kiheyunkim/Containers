#include<iostream>
#include<deque>
#include"Deque.h"
#include<list>
void print(Deque deque)
{
	for (Deque::iterator iter = deque.begin(); iter != deque.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}
void main()
{
	int i = 0;
	int *a = &i;

	int b2 = &i;

	int **b = &a;

	int &&aa = b;

	std::deque<int> deque;
	std::deque<int>::iterator riter;
	deque.push_back(1);
	deque.push_back(2);
	deque.at(1)=6;
	std::cout << deque.size() << std::endl;
	Deque deque2;
	deque2.push_back(1);
	deque2.push_front(3);
	deque2.push_front(2);
	deque2.push_front(5);
	deque2.push_front(4);
	print(deque2);

	std::list<int> list;
	list.push_back(1);
	list.push_back(2);

	std::list<int>::iterator iter = list.begin();
	std::cout << &iter << std::endl;

	std::cout << *iter << std::endl;

}