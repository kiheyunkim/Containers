#pragma once
#include"Node.h"
#include"Iterator.h"
#include"Reverse_Iterator.h"
class Deque
{
private:
	Node *_head;
	Node *_rear;
public:
	Deque();
	Deque(Deque &deque);
	~Deque();
	
	typedef int value_type;
	//allocator
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef Iterator iterator;
	typedef const Iterator const_iterator;
	typedef Reverse_Iterator reverse_iterator;
	typedef const Reverse_Iterator const_reverse_iterator;
	//difference
	typedef size_t size_type;
	
	
	void operator=(Deque &deque);

	//Iterators
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator cbegin();
	const_iterator cend();
	const_reverse_iterator crbegin();
	const_reverse_iterator crend();

	//Capacity
	size_type size();
	size_type max_size();
	void resize(size_t newSize);
	bool empty();
	void shrink_to_fit();

	//Element Access;
	value_type operator[](size_t count);
	reference at(size_t n);	
	value_type front();
	value_type back();


	//Modifiers
	void assign(Iterator first, Iterator last);
	void push_back(value_type value);
	void push_front(value_type value);
	void pop_back();
	void pop_front();
	iterator insert(const_iterator position, const value_type& val);
	iterator erase(const_iterator position);
	void swap(Deque &deque);
	void clear();
	iterator emplace(Deque::const_iterator position, Deque::value_type val);
	iterator emplace_back(Deque::value_type val);
	iterator emplace_front(Deque::value_type val);

	//allocator
	void get_allocator();

};


