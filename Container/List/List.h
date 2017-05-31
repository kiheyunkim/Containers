#pragma once
#include"Iterator.h"
#include"ReverseIterator.h"
#include"Node.h"

template<class T>
class List
{
private:
	Node<T>* _head;
	Node<T>* _tail;


public:
	typedef int ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef Iterator<T> Iterator;
	typedef const Iterator ConstIterator;
	typedef ReverseIterator<T> ReverseIterator;
	typedef const ReverseIterator ConstReverseIterator;
	typedef size_t SizeType;

private:
	void _swap(ValueType &x1, ValueType &x2)
	{
		List<T>::ValueType temp = x1;
		x1 = x2;
		x2 = temp;
	}

public:
	List():_head(nullptr),_tail(nullptr)
	{
		Node<T>* dummyHeadNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* dummyTailNode = static_cast<Node<T>*>(new Node<T>());

		_head = dummyHeadNode;
		_tail = dummyTailNode;
		
		_head->_SetNextNode(_tail);
		_tail->_SetPrevNode(_head);
	}
	
	List(const List<T>& list):_head(nullptr),_tail(nullptr)
	{
		Node<T>* dummyHeadNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* dummyTailNode = static_cast<Node<T>*>(new Node<T>());

		_head = dummyHeadNode;
		_tail = dummyTailNode;

		_head->_SetNextNode(_tail);
		_tail->_SetPrevNode(_head);

		List<T>::Iterator iter = list.ConstBegin();

		while (iter != list.ConstEnd())
		{
			PushBack(*iter);
			iter++;
		}
	}

	~List()
	{
		if (!Empty())
			while (!Empty()) PopBack();

		delete _head;
		delete _tail;
	}

	List& operator=(const List<T>& targetList)
	{
		Node<T>* cur = _head->_GetNextNode();
		List<T>::SizeType copySize = Size();

		for (List<T>::SizeType i = 0; i < copySize; i++)
		{
			PushBack(cur->_GetValue());
			cur = cur->_GetNextNode();
		}

		return *this;
	}

	//Iterator
	Iterator Begin() { return static_cast<List<T>::Iterator>(*_head->_GetNextNode()); }
	Iterator End() { return static_cast<List<T>::Iterator>(*_tail); }
	ReverseIterator ReverseBegin() { return static_cast<List<T>::ReverseIterator>(*_tail->_GetPrevNode()); }
	ReverseIterator ReverseEnd() { return static_cast<List<T>::ReverseIterator>(*_head); }
	ConstIterator ConstBegin() const { return static_cast<List<T>::ConstIterator>(*_head->_GetNextNode()); }
	ConstIterator ConstEnd() const { return static_cast<List<T>::ConstIterator>(*_tail); }
	ConstReverseIterator ConstReverseBegin() const { return static_cast<List<T>::ConstReverseIterator>(*_tail->_GetPrevNode()); }
	ConstReverseIterator ConstReverseEnd() const { return static_cast<List<T>::ConstReverseIterator>(*_head); }

	//Capacity
	bool Empty() const { return _head->_GetNextNode() == _tail; }
	SizeType Size() const
	{
		List<T>::SizeType size = 0;
		List<T>::Iterator tempIter = static_cast<List<T>::Iterator>(*_head->_GetNextNode());

		while (tempIter != ConstEnd())
		{
			size++;
			tempIter++;
		}

		return size;
	}

	SizeType MaxSize() { return -1; }

	//Element access
	Reference Front() { return _head->_GetAddr(); }
	Reference Back() { return _tail->_GetPrevNode()->_GetAddr(); }

	//Modifiers
	void Assign(SizeType n, ValueType value)
	{
		for (List<T>::SizeType i = 0; i < n; i++)	PushBack(value);
	}
	void EmplaceFront(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(value);

		newNode->_SetNextNode(_head->_GetNextNode());
		newNode->_SetPrevNode(_head);
		_head->_GetNextNode()->_SetPrevNode(newNode);
		_head->_SetNextNode(newNode);
	}
	void PushFront(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(value);

		newNode->_SetNextNode(_head->_GetNextNode());
		newNode->_SetPrevNode(_head);
		_head->_GetNextNode()->_SetPrevNode(newNode);
		_head->_SetNextNode(newNode);
	}
	void PopFront()
	{
		if (Empty()) return;

		Node<T>* tempNode = _head->_GetNextNode();
		tempNode->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
		tempNode->_GetNextNode()->_SetPrevNode(tempNode->_GetPrevNode());
		tempNode->_SetPrevNode(nullptr);
		tempNode->_SetNextNode(nullptr);

		delete tempNode;
	}
	void EmplaceBack(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(value);

		newNode->_SetNextNode(_tail->_GetPrevNode()->_GetNextNode());
		newNode->_SetPrevNode(_tail->_GetPrevNode());
		_tail->_GetPrevNode()->_SetNextNode(newNode);
		_tail->_SetPrevNode(newNode);
	}
	void PushBack(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(value);

		newNode->_SetNextNode(_tail->_GetPrevNode()->_GetNextNode());
		newNode->_SetPrevNode(_tail->_GetPrevNode());
		_tail->_GetPrevNode()->_SetNextNode(newNode);
		_tail->_SetPrevNode(newNode);
	}
	void PopBack()
	{
		Node<T>* tempNode = _tail->_GetPrevNode();

		_tail->_SetPrevNode(tempNode->_GetPrevNode());
		_tail->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
		tempNode->_SetPrevNode(nullptr);
		tempNode->_SetNextNode(nullptr);

		delete tempNode;
	}
	Iterator Insert(ConstIterator& pos, ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());

		newNode->_SetValue(val);
		newNode->_SetNextNode(const_cast<List<T>::Iterator&>(pos)._GetNode());
		newNode->_SetPrevNode(const_cast<List<T>::Iterator&>(pos)._GetNode()->_GetPrevNode());
		const_cast<List<T>::Iterator&>(pos)._GetNode()->_GetPrevNode()->_SetNextNode(newNode);
		const_cast<List<T>::Iterator&>(pos)._GetNode()->_SetPrevNode(newNode);

		return static_cast<List::Iterator>(*newNode);
	}
	Iterator Erase(ConstIterator& pos)
	{
		Node<T>* tempNode = const_cast<List<T>::Iterator&>(pos)._GetNode();
		List<T>::Iterator iter = static_cast<List<T>::Iterator>(*tempNode);

		tempNode->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
		tempNode->_GetNextNode()->_SetPrevNode(tempNode->_GetPrevNode());
		tempNode->_SetPrevNode(nullptr);
		tempNode->_SetNextNode(nullptr);

		delete tempNode;

		return static_cast<List<T>::Iterator>(iter);
	}
	void Swap(List<T> &list)
	{
		Node* headTemp = _head;
		Node* tailTemp = _tail;

		_head = list._head;
		_tail = list._tail;

		list._head = headTemp;
		list._tail = tailTemp;

	}
	void Resize(SizeType size)
	{
		List<T>::SizeType originalSize = this->Size();

		if (this->Size() > size)
		{
			for (List<T>::SizeType i = 0; i < originalSize - size; i++)
				this->PopBack();
			return;
		}

		for (List::SizeType i = 0; i < size - originalSize + 1; i++)
			this->PushBack(0);
	}
	void Clear()
	{
		List<T>::SizeType count = Size();

		for (List<T>::SizeType i = 0; i < count; i++)
			this->PopBack();
	}

	//Operations
	void Splice(ConstIterator& iter, List& list)
	{
		List<T>::Iterator tempiter = list.Begin();
		List<T>::SizeType copySize = list.Size();

		for (List<T>::SizeType i = 0; i < copySize; i++)
		{
			Insert(iter, *tempiter);
			tempiter++;
		}

	}
	void Remove(ValueType val)
	{
		if (Empty()) return;

		List<T>::Iterator iter = static_cast<List::Iterator>(*_head);

		while (iter._GetNode()->_GetNextNode() != End()._GetNode())
		{
			if (iter._GetNode()->_GetValue() == val)
			{
				Erase(iter);
				iter++;
				continue;
			}
			iter++;
		}
	}
	void RemoveIf(bool(*compare)(int))
	{
		if (Empty()) return;

		List<T>::Iterator iter = static_cast<List<T>::Iterator>(*_head);

		while (iter._GetNode() != End()._GetNode())
		{
			if (compare(iter._GetNode()->_GetValue()))
			{
				Erase(iter);
				iter++;
				continue;
			}
			iter++;
		}
	}
	void Unique()
	{
		if (Empty()) return;

		List<T>::Iterator iter1 = Begin();
		List<T>::Iterator iter2 = static_cast<List<T>::Iterator>(*Begin()._GetNode()->_GetNextNode());

		while (iter1 != *End()._GetNode() && iter2 != *End()._GetNode())
		{
			if (iter2._GetNode() == End()._GetNode())
			{
				iter1++;
				iter2 = iter1++;
			}
			if (iter1._GetNode()->_GetValue() == iter2._GetNode()->_GetValue())
			{
				Erase(iter2);
				iter2++;
				continue;
			}
			iter2++;
		}
	}
	void Merge(List<T>& list)
	{
		while (list.Size() != 0)
		{
			PushBack(list.Front());
			list.PopFront();
		}
	}
	void Sort()//use Selection Sorting
	{
		if (Empty()) return;
		if (Size() == 1) return;

		List<T>::SizeType length = Size();
		List<T>::Iterator iter = Begin();
		List<T>::ValueType* tempArray = static_cast<List<T>::ValueType*>(new List<T>::ValueType[length]);

		for (List<T>::SizeType i = 0; i < length; i++)
		{
			tempArray[i] = iter._GetNode()->_GetValue();
			iter = static_cast<List<T>::Iterator>(*iter._GetNode()->_GetNextNode());
		}

		int minPos = 0;
		int insertPos = 0;

		for (List<T>::SizeType pass = 0; pass < length - 1; pass++)
		{
			minPos = insertPos;
			for (List<T>::SizeType i = insertPos + 1; i < length; i++)
			{
				if (tempArray[i] < tempArray[minPos])	minPos = i;
			}

			_swap(tempArray[minPos], tempArray[insertPos]);
			insertPos++;
		}

		Clear();

		for (List<T>::SizeType i = 0; i < length; i++)
			PushBack(tempArray[i]);

		delete[] tempArray;
	}
	void Reverse()
	{
		List<T> tempList;
		tempList.Splice(tempList.Begin(), *this);

		Clear();



		while (!tempList.Empty())
		{
			PushBack(tempList.Back());
			tempList.PopBack();
		}
	}
};