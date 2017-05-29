#include "Queue.h"
#include<stdio.h>


Queue::Queue() :_front(nullptr), _rear(nullptr) {}

Queue::Queue(const Queue& queue) : _front(nullptr), _rear(nullptr)
{
	size_t copySize = queue.size();
	Node* cur = queue._front;

	for (size_t index = 0; index < copySize; index++)
	{
		push(cur->_GetValue());
		cur = cur->_GetNextNode();
	}
}

Queue::~Queue() {}

Queue& Queue::operator=(const Queue& queue)
{
	while (empty()) pop();

	size_t copySize = queue.size();
	Node* cur = queue._front;

	for (size_t index = 0; index < copySize; index++)
	{
		push(cur->_GetValue());
		cur = cur->_GetNextNode();
	}

	return *this;
}

bool Queue::empty() const { return _front == nullptr&&_rear == nullptr; }

Queue::size_type Queue::size() const
{
	if (empty()) return 0;
	Node* cur = _front;
	size_t size = 1;

	while (cur->_GetNextNode() != nullptr)
	{
		cur = cur->_GetNextNode();
		size += 1;
	}

	return size;
}

Queue::reference Queue::front() { return _front->_GetAddr(); }
Queue::reference Queue::back() { return _rear->_GetAddr(); }

void Queue::push(Queue::value_type val)
{
	if (empty())
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

void Queue::emplace(Queue::value_type val) 
{
	if (empty())
	{
		push(val);
		return;
	}
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetPrevNode(_rear);
	_rear->_SetNextNode(newNode);
	_rear = newNode;
}

void Queue::pop()
{
	if (empty()) return;
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

void Queue::swap(Queue& queue)
{

	Node* frontTemp = queue._front;
	Node* rearTemp = queue._rear;

	queue._front = _front;
	queue._rear = _rear;

	_front= frontTemp;
	_rear = rearTemp;
}


