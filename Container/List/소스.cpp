#include<stdio.h>
#include<iostream>
#include"List.h"
#include<list>

void print(List list)
{
	for (List::Iterator iter = list.Begin(); iter != list.End(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void main()
{
	
	List list;
	List list2;
	list.PushFront(3);
	list.PushFront(4);
	list.PushFront(2);
	list.PushFront(1);
	print(list);

	List::Iterator iter = list.End();
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


	Iterator iterator = list.Begin();
	list.Splice(list.Begin(), list2);
	print(list2);
	print(list);

	



	
}

