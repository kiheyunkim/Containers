#pragma once
#include "Iterator.h"
#include "Reverse_Iterator.h"
#include "Node.h"

#define		ALLOC_SIZE		6

class Vector
{
private:
	Node** _dataArray;

private:
	unsigned int _headIndex;
	unsigned int _tailIndex;
	size_t _arraySize;

public:
	typedef Iterator Iterator;
	typedef Reverse_Iterator Reverse_Iterator;
	typedef int& reference;

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
	void Reserve();
	void ShrinkToFit();

	reference operator[](size_t index);
	reference at(size_t index);
	reference front();
	reference back();
	void data();

	void Assign(const size_t count, const int value);
	void PushBack(const int value);
	void PopBack();
	Iterator insert(const Iterator position, const int value);
	void erase(const Iterator position);
	void swap(Vector &vector);
	void clear();
};

