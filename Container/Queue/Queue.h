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
	typedef int ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;

public:
	Queue& operator=(const Queue& queue);
	bool Empty() const;
	SizeType Size() const;
	Reference Front();
	Reference Back();
	void Push(ValueType val);
	void Emplace(ValueType val);
	void Pop();
	void Swap(Queue& queue);
};


