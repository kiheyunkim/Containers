#pragma once
#include"Node.h"
class Stack
{
private:
	Node *_top;

public:
	typedef int value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef size_t size_type;

public:
	Stack();
	Stack(const Stack& stack);
	~Stack();
	void operator=(const Stack& stack);
	bool empty() const;
	size_type size() const;
	reference top();
	void push(value_type val);
	void emplace(value_type val);
	void pop();
	void swap(Stack &stack);
};

