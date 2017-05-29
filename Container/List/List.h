#pragma once
#include"Iterator.h"
#include"ReverseIterator.h"
#include"Node.h"

class List
{
private:
	Node* _head;
	Node* _tail;


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

private:
	void _swap(ValueType &x1, ValueType &x2);

public:
	List();
	List(const List& list);
	~List();
	List& operator=(const List& targetList);

	//Iterator
	Iterator Begin();
	Iterator End();
	ReverseIterator ReverseBegin();
	ReverseIterator ReverseEnd();
	ConstIterator ConstBegin() const;
	ConstIterator ConstEnd() const;
	ConstReverseIterator ConstReverseBegin() const;
	ConstReverseIterator ConstReverseEnd() const;

	//Capacity
	bool Empty() const;
	SizeType Size() const;
	SizeType MaxSize();

	//Element access
	Reference Front();
	Reference Back();

	//Modifiers
	void Assign(SizeType n, ValueType value);
	void EmplaceFront(ValueType value);
	void PushFront(ValueType value);
	void PopFront();
	void EmplaceBack(ValueType value);
	void PushBack(ValueType val);
	void PopBack();
	Iterator Insert(const Iterator& pos, ValueType value);
	Iterator Erase(const Iterator& pos);
	void Swap(List &list);
	void Resize(SizeType size);
	void Clear();

	//Operations
	void Splice(const Iterator& iter, List& list);
	void Remove(ValueType val);
	void RemoveIf(bool(*compare)(int));
	void Unique();
	void Merge(List& list);
	void Sort();
	void Reverse();
};