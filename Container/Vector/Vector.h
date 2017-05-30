#pragma once
#include "Iterator.h"
#include "ReverseIterator.h"
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
	typedef int ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef Iterator Iterator;
	typedef const Iterator ConstIterator;
	typedef ReverseIterator ReverseIterator;
	typedef const ReverseIterator ConstReverseIterator;
	typedef size_t SizeType;

public:
	Vector();
	~Vector();

	Iterator Begin() const;
	Iterator End() const;
	ReverseIterator ReverseBegin() const;
	ReverseIterator ReverseEnd() const;
	const Iterator ConstBegin() const;
	const Iterator ConstEnd() const;
	const ReverseIterator ConstReverseBegin() const;
	const ReverseIterator ConstReverseEnd() const;

	SizeType Size() const;
	SizeType MaxSize() const;
	void Resize();
	SizeType Capacity() const;
	bool Empty() const;
	void Reserve();
	void ShrinkToFit();

	Reference operator[](SizeType index);
	Reference At(SizeType index);
	Reference Front();
	Reference Back();
	void Data();

	void Assign(SizeType count, ValueType value);
	void PushBack(ValueType value);
	void PopBack();
	Iterator insert(ConstIterator& position, ValueType value);
	void Erase(ConstIterator& position);
	void Swap(Vector& vector);
	void Clear();
};

