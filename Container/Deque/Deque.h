#pragma once
#include"Node.h"
#include"Iterator.h"
#include"ReverseIterator.h"
class Deque
{
private:
	Node *_head;
	Node *_rear;

public:
	Deque();
	Deque(const Deque& deque);
	~Deque();
	
	typedef int ValueType;
	//allocator
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef Iterator Iterator;
	typedef const Iterator ConstIterator;
	typedef ReverseIterator ReverseIterator;
	typedef const ReverseIterator ConstReverseIterator;
	//difference
	typedef size_t SizeType;
	
	
	void operator=(const Deque& deque);

	//Iterators
	Iterator Begin();
	Iterator End();
	ReverseIterator ReverseBegin();
	ReverseIterator ReverseEnd();
	ConstIterator ConstBegin() const;
	ConstIterator ConstEnd() const;
	ConstReverseIterator ConstReverseBegin() const ;
	ConstReverseIterator ConstReverseEnd() const;

	//Capacity
	SizeType Size() const;
	SizeType MaxSize();
	void Resize(SizeType newSize);
	bool Empty() const;
	void ShrinkToFit();

	//Element Access;
	ValueType operator[](SizeType count);
	Reference At(SizeType n);	
	ValueType Front() const;
	ValueType Back() const;


	//Modifiers
	void Assign(const Iterator& first, const Iterator& last);
	void PushBack(ValueType value);
	void PushFront(ValueType value);
	void PopBack();
	void PopFront();
	Iterator Insert(ConstIterator& position, ValueType val);
	Iterator Erase(ConstIterator& position);
	void Swap(Deque& deque);
	void Clear();
	Iterator Emplace(ConstIterator& position, ValueType val);
	Iterator EmplaceBack(ValueType val);
	Iterator EmplaceFront(ValueType val);

	//allocator
	void GetAllocator();

};


