#pragma once
#include"Node.h"
class Stack
{
private:
	Node *_top;

public:
	typedef int ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;

public:
	Stack();
	Stack(const Stack& stack);
	~Stack();
	void operator=(const Stack& stack);
	bool Empty() const;
	SizeType Size() const;
	Reference Top();
	void Push(ValueType val);
	void Emplace(ValueType val);
	void Pop();
	void Swap(Stack &stack);
};

