#include"Vector.h"
#include<vector>
void main()
{
	Vector<int> vec;
	vec.PushBack(2);
	vec.PushBack(3);
	vec.PushBack(4);
	vec.PushBack(5);
	vec.PushBack(6);
	vec.PushBack(7);

	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	vec.PopBack();
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;

	vec.PushBack(2);
	vec.PushBack(3);
	vec.PushBack(4);
	vec.PushBack(5);
	vec.PushBack(6);
	vec.PushBack(7);
	vec.PushBack(8);
	vec.PushBack(9);
	vec.PushBack(10);
	vec.PushBack(11);
	vec.PushBack(12);
	for (Vector<int>::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;

}