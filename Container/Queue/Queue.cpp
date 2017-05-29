#include "Queue.h"
#include<stdio.h>


Queue::Queue() :_front(nullptr), _rear(nullptr) {}

Queue::Queue(const Queue& queue) : _front(nullptr), _rear(nullptr)
{
	Queue::SizeType copySize = queue.Size();
	Node* cur = queue._front;

	for (Queue::SizeType index = 0; index < copySize; index++)
	{
		Push(cur->_GetValue());
		cur = cur->_GetNextNode();
	}
}

Queue::~Queue() {}

Queue& Queue::operator=(const Queue& queue)
{
	while (Empty()) Pop();

	Queue::SizeType copySize = queue.Size();
	Node* cur = queue._front;

	for (Queue::SizeType index = 0; index < copySize; index++)
	{
		Push(cur->_GetValue());
		cur = cur->_GetNextNode();
	}

	return *this;
}

bool Queue::Empty() const { return _front == nullptr&&_rear == nullptr; }

Queue::SizeType Queue::Size() const
{
	if (Empty()) return 0;
	Node* cur = _front;
	size_t size = 1;

	while (cur->_GetNextNode() != nullptr)
	{
		cur = cur->_GetNextNode();
		size += 1;
	}

	return size;
}

Queue::Reference Queue::Front() { return _front->_GetAddr(); }

Queue::Reference Queue::Back() { return _rear->_GetAddr(); }

void Queue::Push(Queue::ValueType val)
{
	if (Empty())
	{
		Node* newNode = static_cast<Node*>(new Node());
		newNode->_SetValue(val);
		_front = newNode;
		_rear = newNode;
		return;
	}
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);
	newNode->_SetPrevNode(_rear);
	_rear->_SetNextNode(newNode);
	_rear = newNode;
}

void Queue::Emplace(Queue::ValueType val) 
{
	if (Empty())
	{
		Push(val);
		return;
	}
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetPrevNode(_rear);
	_rear->_SetNextNode(newNode);
	_rear = newNode;
}

void Queue::Pop()
{
	if (Empty()) return;
	if (_front == _rear)
	{
		delete(_front);
		_front = nullptr;
		_rear = nullptr;
		return;
	}
	Node* temp = _front;
	_front = _front->_GetNextNode();
	_front->_SetPrevNode(nullptr);

	delete(temp);
}

void Queue::Swap(Queue& queue)
{

	Node* frontTemp = queue._front;
	Node* rearTemp = queue._rear;

	queue._front = _front;
	queue._rear = _rear;

	_front= frontTemp;
	_rear = rearTemp;
}


