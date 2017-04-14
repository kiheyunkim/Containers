#pragma once
#include"Iterator.h"
#include"Reverse_Iterator.h"
#include"Node.h"

class List
{
public:
	typedef int value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
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
	void assign(size_type n, value_type val);
	void emplace_front(value_type val);
	void push_front(value_type val);
	void pop_front();
	void emplace_back(value_type val);
	void push_back(int val);
	void pop_back();
	iterator insert(iterator pos, value_type val);
	iterator erase(Iterator pos	);
	void swap(List &list);
	void resize(size_t size);
	void clear();

	//Operations
	void splice(Iterator iter, List *list);
	void remove(int val);
	void remove_if(bool(*compare)(const int&));
	void unique();
	void merge(List list);
	void sort();
	void reverse();

private:
	Node *_head;
	Node *_tail;

private:
	void _swap(int *x1, int *x2);
};

