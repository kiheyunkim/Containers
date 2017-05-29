#pragma once
#include "Iterator.h"
#include "Reverse_Iterator.h"
#include "Node.h"

#define		ALLOC_SIZE		6

class Vector
{
private:
	typedef Node* NodePtr;

public:
	NodePtr* _dataArray;

private:
	unsigned int _headIndex;
	unsigned int _tailIndex;
	size_t _arraySize;

public:
	typedef int valueType;
	typedef valueType& reference;
	typedef const valueType& constReference;
	typedef valueType* pointer;
	typedef const valueType* constPointer;
	typedef Iterator Iterator;
	typedef const Iterator constIterator;
	typedef Reverse_Iterator reverseIterator;
	typedef const Reverse_Iterator constReverseIterator;
	typedef size_t sizeType;

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

	sizeType Size() const;
	sizeType MaxSize() const;
	void resize();
	sizeType capacity() const;
	bool Empty() const;
	void Reserve();
	void ShrinkToFit();

	reference operator[](size_t index);
	reference at(size_t index);
	reference front();
	reference back();
	void data();

	void Assign(size_t count, int value);
	void PushBack(int value);
	void PopBack();
	Iterator insert(const Iterator& position,int value);
	void erase(const Iterator& position);
	void swap(Vector& vector);
	void clear();
};

