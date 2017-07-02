#pragma once
#include"Node.h"
template<typename T>
class Queue
{
private:
	Node<T>* _front;
	Node<T>* _rear;

public:
	Queue() :_front(nullptr), _rear(nullptr) {}

	Queue(const Queue<T>& queue) : _front(nullptr), _rear(nullptr)
	{
		Queue<T>::SizeType copySize = queue.Size();
		Node<T>* cur = queue._front;

		for (Queue<T>::SizeType index = 0; index < copySize; index++)
		{
			Push(cur->_GetValue());
			cur = cur->_GetNextNode();
		}
	}

	~Queue() {}

public:
	typedef T ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;

public:
	Queue<T>& operator=(const Queue<T>& queue)
	{
		while (Empty()) Pop();

		Queue<T>::SizeType copySize = queue.Size();
		Node<T>* cur = queue._front;

		for (Queue::SizeType index = 0; index < copySize; index++)
		{
			Push(cur->_GetValue());
			cur = cur->_GetNextNode();
		}

		return *this;
	}

	bool Empty() const{ return _front == nullptr&&_rear == nullptr; }
	
	SizeType Size() const
	{
		if (Empty()) return 0;
		Node<T>* cur = _front;
		size_t size = 1;

		while (cur->_GetNextNode() != nullptr)
		{
			cur = cur->_GetNextNode();
			size += 1;
		}

		return size;
	}

	Reference Front() { return _front->_GetAddr(); }
	
	Reference Back() { return _rear->_GetAddr(); }
	
	void Push(ValueType val)
	{
		if (Empty())
		{
			Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
			newNode->_SetValue(val);
			_front = newNode;
			_rear = newNode;
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(val);
		newNode->_SetPrevNode(_rear);
		_rear->_SetNextNode(newNode);
		_rear = newNode;
	}
	
	void Emplace(ValueType val)
	{
		if (Empty())
		{
			Push(val);
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetPrevNode(_rear);
		_rear->_SetNextNode(newNode);
		_rear = newNode;
	}
	
	void Pop()
	{
		if (Empty()) return;
		if (_front == _rear)
		{
			delete(_front);
			_front = nullptr;
			_rear = nullptr;
			return;
		}
		Node<T>* temp = _front;
		_front = _front->_GetNextNode();
		_front->_SetPrevNode(nullptr);

		delete(temp);
	}
	
	void Swap(Queue<T>& queue)
	{
		Node<T>* frontTemp = queue._front;
		Node<T>* rearTemp = queue._rear;

		queue._front = _front;
		queue._rear = _rear;

		_front = frontTemp;
		_rear = rearTemp;
	}
};
