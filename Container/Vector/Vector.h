#pragma once
#include "Iterator.h"
#include "Reverse_Iterator.h"
#include "Node.h"

#define		ALLOC_SIZE		6

class Vector
{
private:
	Node* _head;
	Node* _tail;
	size_t _arraySize;
	Node** _dataArray;
	int _currentIndex;

private:
	void _constructArray();

public:
	typedef Iterator Iterator;
	typedef Reverse_Iterator Reverse_Iterator;

public:
	Vector();
	~Vector();

	Iterator Begin() const;
	Iterator End() const;
	Reverse_Iterator RBegin() const;
	Reverse_Iterator REnd() const;
	const Iterator CBegin() const;
	const Iterator CEnd() const;
	const Reverse_Iterator CrBegin() const;
	const Reverse_Iterator CrEnd() const;

	size_t Size() const;
	size_t MaxSize() const;
	void resize();
	size_t capacity() const;
	bool Empty() const;
	void Reverse();
	void ShrinkToFit();

	void operator[](size_t index);
	

	void Assign(size_t count, const int value);
	void Assign(Iterator first,Iterator end);
	void push_back(const int value);
};

