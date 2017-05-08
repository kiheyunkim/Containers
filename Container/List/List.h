#pragma once
#include"Iterator.h"
#include"Reverse_Iterator.h"
#include"Node.h"

class List
{
private:
	Node *_head;
	Node *_tail;

private:
	void _swap(int *x1, int *x2);

public:
	typedef int valueType;
	typedef valueType& reference;
	typedef const valueType& const_reference;
	typedef valueType* pointer;
	typedef const valueType* const_pointer;
	typedef Iterator iterator;
	typedef const Iterator const_iterator;
	typedef Reverse_Iterator reverse_iterator;
	typedef const Reverse_Iterator const_reverse_iterator;
	typedef size_t size_type;

public:
	List();
	List(List &list);
	~List();
	void operator=(List &targetList);

	//Iterator
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator cbegin();
	const_iterator cend();
	const_reverse_iterator crbegin();
	const_reverse_iterator crend();

	//Capacity
	bool empty();
	size_type size();
	size_type max_size();

	//Element access
	reference front();
	reference back();

	//Modifiers
	void assign(size_type n, valueType value);
	void emplace_front(valueType value);
	void push_front(valueType value);
	void pop_front();
	void emplace_back(valueType value);
	void push_back(valueType val);
	void pop_back();
	iterator insert(iterator pos, valueType value);
	iterator erase(Iterator pos	);
	void swap(List &list);
	void resize(size_t size);
	void clear();

	//Operations
	void splice(Iterator iter, List *list);
	void remove(const int val);
	void remove_if(bool(*compare)(const int&));
	void unique();
	void merge(List list);
	void sort();
	void reverse();
};