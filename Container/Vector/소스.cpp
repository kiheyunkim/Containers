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
	vec._dataArray[0];
	vec._dataArray[1];
	vec._dataArray[2];
	vec._dataArray[3];
	vec._dataArray[4];
	vec._dataArray[5];


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

	

	//for (Vector::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	//{
	//	std::cout << *iter << ' ';
	//}
	//std::cout << std::endl;
	//
	//
	//
	//for (Vector::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	//{
	//	std::cout << *iter << ' ';
	//}
	//std::cout << std::endl;
	//
	//vec.insert(vec.Begin() + 1, 123456);
	//
	//for (Vector::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	//{
	//	std::cout << *iter << ' ';
	//}
	//std::cout << std::endl;
	//
	//vec.erase(vec.Begin());
	//
	//for (Vector::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	//{
	//	std::cout << *iter << ' ';
	//}
	//std::cout << std::endl;
	//
	//vec.erase(vec.Begin());
	//
	//for (Vector::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	//{
	//	std::cout << *iter << ' ';
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < 6; i++)
	//{
	//	std::cout<<vec._dataArray[i]->_GetValue()<<" ";
	//}

}