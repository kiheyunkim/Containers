#include "Queue.h"
#include<stdio.h>


Queue::Queue() :_front(nullptr), _rear(nullptr) {}

Queue::Queue(Queue &queue) : _front(nullptr), _rear(nullptr)
{
	Node *cur = queue._front;
	while (cur != queue._rear)
	{
		push(cur->_GetValue());
		if (cur == _rear) break;
		cur = cur->_GetNextNode();
	}
}

Queue::~Queue() {}

void Queue::operator=(Queue &queue)
{
	while (empty()) pop();

	Node *cur = queue._front;
	while (cur != queue._rear)
	{
		push(cur->_GetValue());
		if (cur == _rear) break;
		cur = cur->_GetNextNode();
	}
}

bool Queue::empty() { return _front == nullptr&&_rear == nullptr; }

Queue::size_type Queue::size()
{
	if (empty()) return 0;
	Node *cur = _front;
	size_t size = 1;

	while (cur->_GetNextNode() != nullptr)
	{
		cur = cur->_GetNextNode();
		size += 1;
	}

	return size;
}

Queue::reference Queue::front() { return *_front->_GetAddr(); }
Queue::reference Queue::back() { return *_rear->_GetAddr(); }

void Queue::push(int val)
{
	if (empty())
	{
		Node *newNode = new Node();
		newNode->_SetValue(val);
		_rear = newNode;
		_front = newNode;
		return;
	}
	Node *newNode = new Node();
	newNode->_SetValue(val);
	newNode->_SetNextNode(_front);
	_front->_SetPrevNode(newNode);
	_front = newNode;
}

void Queue::emplace(int val) 
{
	if (empty())
	{
		push(val);
		return;
	}
	Node *newNode = new Node();
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
	Node *temp = _rear;
	_rear = _rear->_GetPrevNode();
	_rear->_SetNextNode(nullptr);
	temp->_SetPrevNode(nullptr);

	delete(temp);
}

void Queue::swap(Queue &queue)
{

	Node *frontTemp = queue._front;
	Node *rearTemp = queue._rear;

	queue._front = _front;
	queue._rear = _rear;

	_rear = frontTemp;
	_rear = rearTemp;
}


