#include<stdio.h>
#include<iostream>
#include"List.h"
#include"Node.h"
void print(List<int> list)
{
	for (List<int>::Iterator iter = list.Begin(); iter != list.End(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void main()
{
	List<int> list;
	List<int> list2;
	list.PushFront(3);
	list.PushFront(4); 
	list.PushFront(2);
	list.PushFront(1);
	print(list);

	List<int>::Iterator iter = list.End();
	std::cout << *iter;
	
	std::cout << list.Size() << std::endl;
	std::cout << *list.Begin() << std::endl;

	list2.PushBack(10);
	list2.PushBack(20);
	list2.PushBack(30);
	list2.PushBack(30);
	list2.PushBack(30);
	list2.PushBack(30);
	print(list2);
}

