#pragma once
#include"Node.h"
template<typename T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;

public:
	Queue() :front(nullptr), rear(nullptr) {}

	Queue(const Queue<T>& queue) : front(nullptr), rear(nullptr)
	{
		Queue<T>::SizeType copySize = queue.Size();
		Node<T>* cur = queue.front;

		for (Queue<T>::SizeType index = 0; index < copySize; index++)
		{
			Push(cur->getValue());
			cur = cur->getNextNode();
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
		Node<T>* cur = queue.front;

		for (Queue::SizeType index = 0; index < copySize; index++)
		{
			Push(cur->getValue());
			cur = cur->getNextNode();
		}

		return *this;
	}

	bool Empty() const { return front == nullptr && rear == nullptr; }
	
	SizeType Size() const
	{
		if (Empty()) return 0;
		Node<T>* cur = front;
		size_t size = 1;

		while (cur->getNextNode() != nullptr)
		{
			cur = cur->getNextNode();
			size += 1;
		}

		return size;
	}

	Reference Front() { return front->getAddr(); }
	
	Reference Back() { return rear->getAddr(); }
	
	void Push(ValueType val)
	{
		if (Empty())
		{
			Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
			newNode->setValue(val);
			front = newNode;
			rear = newNode;
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(val);
		newNode->setPrevNode(rear);
		rear->setNextNode(newNode);
		rear = newNode;
	}
	
	void Emplace(ValueType val)
	{
		if (Empty())
		{
			Push(val);
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setPrevNode(rear);
		rear->_SetNextNode(newNode);
		rear = newNode;
	}
	
	void Pop()
	{
		if (Empty()) return;
		if (front == rear)
		{
			delete(front);
			front = nullptr;
			rear = nullptr;
			return;
		}
		Node<T>* temp = front;
		front = front->getNextNode();
		front->setPrevNode(nullptr);

		delete(temp);
	}
	
	void Swap(Queue<T>& queue)
	{
		Node<T>* frontTemp = queue.front;
		Node<T>* rearTemp = queue.rear;

		queue.front = front;
		queue.rear = rear;

		front = frontTemp;
		rear = rearTemp;
	}
};
