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
	Deque(const Deque& deque);
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
	
	
	void operator=(const Deque& deque);

	//Iterators
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator cbegin() const;
	const_iterator cend() const;
	const_reverse_iterator crbegin() const ;
	const_reverse_iterator crend() const;

	//Capacity
	size_type size() const;
	size_type max_size();
	void resize(size_t newSize);
	bool empty() const;
	void shrink_to_fit();

	//Element Access;
	value_type operator[](size_t count);
	reference at(size_t n);	
	value_type front() const;
	value_type back() const;


	//Modifiers
	void assign(const Iterator& first, const Iterator& last);
	void push_back(value_type value);
	void push_front(value_type value);
	void pop_back();
	void pop_front();
	iterator insert(const_iterator& position, value_type val);
	iterator erase(const_iterator& position);
	void swap(Deque& deque);
	void clear();
	iterator emplace(Deque::const_iterator& position, Deque::value_type val);
	iterator emplace_back(Deque::value_type val);
	iterator emplace_front(Deque::value_type val);

	//allocator
	void get_allocator();

};


