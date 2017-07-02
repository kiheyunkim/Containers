#pragma once
#include"Node.h"
#include"Iterator.h"
#include"ReverseIterator.h"
template<typename T>
class Deque
{
private:
	Node<T> *_head;
	Node<T> *_rear;

public:
	Deque() :_head(nullptr), _rear(nullptr)
	{
		Node<T>* headDummyNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* rearDummyNode = static_cast<Node<T>*>(new Node<T>());
		_head = headDummyNode;
		_rear = rearDummyNode;
		_head->_SetNextNode(_rear);
		_rear->_SetPrevNode(_head);
	}
	Deque(const Deque<T>& deque) :_head(nullptr), _rear(nullptr)
	{
		Node<T>* headDummyNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* rearDummyNode = static_cast<Node<T>*>(new Node<T>());
		_head = headDummyNode;
		_rear = rearDummyNode;
		_head->_SetNextNode(_rear);
		_rear->_SetPrevNode(_head);

		for (Iterator iter = deque.ConstBegin(); iter != deque.ConstEnd(); iter++)
			PushBack(*iter);
	}

	~Deque()
	{
		delete _head;
		delete _rear;
	}
	
	typedef T ValueType;
	//allocator
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef Iterator<T> Iterator;
	typedef const Iterator ConstIterator;
	typedef ReverseIterator<T> ReverseIterator;
	typedef const ReverseIterator ConstReverseIterator;
	//difference
	typedef size_t SizeType;
	
	
	void operator=(const Deque<T>& deque)
	{
		Clear();
		Deque::SizeType copySize = Size();
		Deque::Iterator iter = static_cast<Deque::Iterator>(deque.ConstBegin());

		for (size_t i = 0; i < copySize; i++)
			PushBack(iter[i]);
	}

	//Iterators
	Iterator Begin() { return  static_cast<Iterator>(*_head->_GetNextNode()); }
	Iterator End() { return static_cast<Iterator>(*_rear); }
	ReverseIterator ReverseBegin() { return static_cast<ReverseIterator>(*_rear->_GetPrevNode()); }
	ReverseIterator ReverseEnd() { return static_cast<ReverseIterator>(*_head); }
	ConstIterator ConstBegin() const { return static_cast<ConstIterator>(*_head->_GetNextNode()); }
	ConstIterator ConstEnd() const { return static_cast<ConstIterator>(*_rear); }
	ConstReverseIterator ConstReverseBegin() const { return static_cast<ConstReverseIterator>(*_rear->_GetPrevNode()); }
	ConstReverseIterator ConstReverseEnd() const { return static_cast<ConstReverseIterator>(*_head); }

	//Capacity
	SizeType Size() const
	{
		SizeType size = 0;
		Iterator tempIter = static_cast<Iterator>(ConstBegin());
		while (tempIter != ConstEnd())
		{
			size++;
			tempIter++;
		}
		return size;
	}

	SizeType MaxSize() { return -1; }
	
	void Resize(SizeType newSize)
	{
		SizeType originalSize = Size();
		if (newSize == originalSize) return;

		if (newSize < originalSize)
		{
			for (SizeType count = 0; count < originalSize - newSize; count++)
				PopBack();
			return;
		}

		if (newSize > originalSize)
		{
			for (SizeType count = 0; count < newSize - originalSize; count++)
				PushBack(0);
		}
	}

	bool Empty() const { return _head->_GetNextNode() == _rear; }
	void ShrinkToFit();

	//Element Access;
	ValueType operator[](SizeType count)
	{
		Node* cur = _head;

		for (Deque::SizeType i = 0; i < count; i++)
			cur = cur->_GetNextNode();

		return cur->_GetValue();
	}

	Reference At(SizeType n)
	{
		Node* cur = _head;
		for (size_t i = 0; i < n; i++)
			cur = cur->_GetNextNode();

		return cur->_GetAddr();
	}
	
	ValueType Front() const { return _head->_GetNextNode()->_GetValue(); }

	ValueType Back() const { return _rear->_GetPrevNode()->_GetValue(); }



	//Modifiers
	void Assign(const Iterator& first, const Iterator& last)
	{
		Clear();

		Deque::Iterator temp = first;
		while (temp != last) { PushBack(temp._GetNode()->_GetValue()); }
	}

	void PushBack(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(value);

		newNode->_SetNextNode(_rear->_GetPrevNode()->_GetNextNode());
		newNode->_SetPrevNode(_rear->_GetPrevNode());
		_rear->_GetPrevNode()->_SetNextNode(newNode);
		_rear->_SetPrevNode(newNode);
	}

	void PushFront(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(value);

		newNode->_SetNextNode(_head->_GetNextNode());
		newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
		_head->_GetNextNode()->_SetPrevNode(newNode);
		_head->_SetNextNode(newNode);
	}

	void PopBack()
	{
		if (Empty()) return;

		Node<T>* cur = _rear->_GetPrevNode();
		cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
		cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
		cur->_SetPrevNode(nullptr);
		cur->_SetNextNode(nullptr);

		delete cur;
	}

	void PopFront()
	{
		if (Empty()) return;

		Node<T>* cur = _head->_GetNextNode();
		cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
		cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
		cur->_SetPrevNode(nullptr);
		cur->_SetNextNode(nullptr);

		delete cur;
	}

	Iterator Insert(ConstIterator& position, ValueType val)
	{
		Deque::Iterator pos = position;
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(val);
		newNode->_SetNextNode(pos._GetNode());
		newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
		pos._GetNode()->_SetPrevNode(newNode);
		pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

		return *newNode;
	}

	Iterator Erase(ConstIterator& position)
	{
		Deque::Iterator pos = position;
		Node<T>* tempNode = pos._GetNode();
		Deque::Iterator returnIter = static_cast<Deque::Iterator>(*pos._GetNode()->_GetNextNode());

		pos._GetNode()->_GetNextNode()->_SetPrevNode(pos._GetNode()->_GetPrevNode());
		pos._GetNode()->_GetPrevNode()->_SetNextNode(pos._GetNode()->_GetNextNode());
		tempNode->_SetNextNode(nullptr);
		tempNode->_SetPrevNode(nullptr);
		delete tempNode;

		return returnIter;
	}

	void Swap(Deque& deque)
	{
		Node* tempHead = deque._head;
		Node* tempRear = deque._rear;

		deque._head = _head;
		deque._rear = _rear;

		_head = tempHead;
		_rear = tempRear;
	}
	void Clear()
	{
		Deque::SizeType clearSize = Size();
		for (Deque::SizeType i = 0; i < clearSize; i++)
			PopBack();
	}

	Iterator Emplace(ConstIterator& position, ValueType val)
	{
		Deque::Iterator pos = position;
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(val);
		newNode->_SetNextNode(pos._GetNode());
		newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
		pos._GetNode()->_SetPrevNode(newNode);
		pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

		return static_cast<Deque::Iterator>(*newNode);
	}

	Iterator EmplaceBack(ValueType val)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(val);

		newNode->_SetNextNode(_head->_GetNextNode());
		newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
		_head->_GetNextNode()->_SetPrevNode(newNode);
		_head->_SetNextNode(newNode);

		return static_cast<Deque::Iterator>(*newNode);
	}

	Iterator EmplaceFront(ValueType val)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(val);

		newNode->_SetNextNode(_head->_GetNextNode());
		newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
		_head->_GetNextNode()->_SetPrevNode(newNode);
		_head->_SetNextNode(newNode);

		return static_cast<Deque::Iterator>(*newNode);
	}

	//allocator
	void GetAllocator();

};


