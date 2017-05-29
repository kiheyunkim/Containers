#pragma once
#include"Node.h"
class Queue
{
private:
	Node* _front;
	Node* _rear;

public:
	Queue();
	Queue(const Queue& queue);
	~Queue();

public:
	typedef int value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef size_t size_type;

public:
	Queue& operator=(const Queue& queue);
	bool empty() const;
	size_type size() const;
	reference front();
	reference back();
	void push(value_type val);
	void emplace(value_type val);
	void pop();
	void swap(Queue& queue);
};


