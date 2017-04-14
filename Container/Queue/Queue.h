#pragma once
#include"Node.h"
class Queue
{
public:
	Queue();
	Queue(Queue &queue);
	~Queue();

public:
	typedef int value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef size_t size_type;

public:
	void operator=(Queue &queue);
	bool empty();
	size_type size();
	reference front();
	reference back();
	void push(value_type val);
	void emplace(value_type val);
	void pop();
	void swap(Queue &queue);

private:
	Node *_front;
	Node *_rear;
};


