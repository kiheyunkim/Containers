#include<stdio.h>
#include<iostream>
#include"List.h"
#include<list>


void print1()
{
	std::list<int,std::allocator<unsigned int>> List; //357,913,941  //357913941	//357913941
	unsigned int i = -1;
	List.push_back(-11);
	std::cout << List.max_size() << std::endl;
	std::cout << i/sizeof(int)/3 << std::endl;
}

void print(List list)
{
	for (List::iterator iter = list.begin(); iter != list.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void main()
{
	
	List list;
	List list2;
	list.push_front(3);
	list.push_front(4);
	list.push_front(2);
	list.push_front(1);
	print(list);

	List::iterator iter = list.end();
	std::cout << *iter;
	
	std::cout << list.size() << std::endl;
	std::cout << *list.begin() << std::endl;

	list2.push_back(10);
	list2.push_back(20);
	list2.push_back(30);
	list2.push_back(30);
	list2.push_back(30);
	list2.push_back(30);
	print(list2);


	Iterator iterator = list.begin();
	list.splice(list.begin(), &list2);
	print(list2);
	print(list);

	



	
}

