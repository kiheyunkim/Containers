#include "Deque.h"



Deque::Deque() :_head(nullptr), _rear(nullptr)
{
	Node *headDummyNode = new Node();
	Node *rearDummyNode = new Node();
	_head = headDummyNode;
	_rear = rearDummyNode;
	_head->_SetNextNode(_rear);
	_rear->_SetPrevNode(_head);
}

Deque::Deque(Deque &deque) :_head(nullptr), _rear(nullptr)
{
	Node *headDummyNode = new Node();
	Node *rearDummyNode = new Node();
	_head = headDummyNode;
	_rear = rearDummyNode;
	_head->_SetNextNode(_rear);
	_rear->_SetPrevNode(_head);

	for (Iterator iter = deque.begin(); iter != deque.end(); iter++)
		push_back(*iter);
}

Deque::~Deque() 
{
	delete _head;
	delete _rear; 
}

void Deque::operator=(Deque &deque)
{
	clear();
	size_t copySize = size();
	for (size_t i = 0; i < copySize; i++)
	{
		push_back(deque.front());
		deque.pop_front();
	}
}

Deque::iterator Deque::begin()
{
	if (empty()) return nullptr;
	return  _head->_GetNextNode();
}

Deque::iterator Deque::end() { return _rear; }

Deque::reverse_iterator Deque::rbegin()
{
	if (empty()) return nullptr;
	return _rear->_GetPrevNode();
}

Deque::reverse_iterator Deque::rend() { return _head; }

Deque::const_iterator Deque::cbegin()
{
	if (empty()) return nullptr;
	return _head->_GetNextNode();
}

Deque::const_iterator Deque::cend() { return _rear; }

Deque::const_reverse_iterator Deque::crbegin()
{
	if (empty()) return nullptr;
	return _rear->_GetPrevNode();
}

Deque::const_reverse_iterator Deque::crend() { return _head; }

Deque::size_type Deque::size()
{
	size_t size = 0;
	Deque::iterator tempIter = begin();
	while (tempIter != end())
	{
		size++;
		tempIter++;
	}
	return size;
}

//Deque::size_type Deque::max_size() { return 1; }

void Deque::resize(size_t newSize)
{
	size_t originalSize = size();
	if (newSize == originalSize) return;

	if (newSize < originalSize)
	{
		for (size_t count = 0; count < originalSize - newSize; count++)
			pop_back();
		return;
	}

	if (newSize > originalSize)
	{
		for (size_t count = 0; count < newSize - originalSize; count++)
			push_back(0);
	}
}

bool Deque::empty() { return _head->_GetNextNode() == _rear; }

//void Deque::shrink_to_fit() {}

Deque::value_type Deque::operator[](size_t count)
{
	Node *cur = _head;

	for (size_t i = 0; i < count; i++)
		cur = cur->_GetNextNode();
	return cur->_GetValue();
}

Deque::reference Deque::at(size_t n)
{
	Node *cur = _head;
	for (size_t i = 0; i < n; i++)
	{
		cur = cur->_GetNextNode();
	}
	return *cur->_GetAddr();
}

Deque::value_type Deque::front() { return _head->_GetNextNode()->_GetValue(); }

Deque::value_type Deque::back() { return _rear->_GetPrevNode()->_GetValue(); }


void Deque::assign(Iterator first, Iterator last)
{
	clear();

	Iterator temp = first;
	while (temp != last) { push_back(temp._GetNode()->_GetValue()); }
}

void Deque::push_back(Deque::value_type val)
{
	Node *newNode = new Node();
	newNode->_SetValue(val);

	newNode->_SetNextNode(_rear->_GetPrevNode()->_GetNextNode());
	newNode->_SetPrevNode(_rear->_GetPrevNode());
	_rear->_GetPrevNode()->_SetNextNode(newNode);
	_rear->_SetPrevNode(newNode);
}

void Deque::push_front(Deque::value_type val)
{
	Node *newNode = new Node();
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);
}

void Deque::pop_back()
{
	if (empty()) return;

	Node *cur = _rear->_GetPrevNode();
	cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
	cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
	cur->_SetPrevNode(nullptr);
	cur->_SetNextNode(nullptr);
	delete cur;
}

void Deque::pop_front()
{
	if (empty()) return;
	Node *cur = _head->_GetNextNode();
	cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
	cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
	cur->_SetPrevNode(nullptr);
	cur->_SetNextNode(nullptr);
	delete cur;
}

Deque::iterator Deque::insert(const_iterator position, const value_type& val)
{
	Iterator pos = position;
	Node *newNode = new Node();
	newNode->_SetValue(val);
	newNode->_SetNextNode(pos._GetNode());
	newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_SetPrevNode(newNode);
	pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

	return newNode;
}

Deque::iterator Deque::erase(Deque::const_iterator position)
{
	Iterator pos = position;
	Node *tempNode = pos._GetNode();
	iterator returnIter = pos._GetNode()->_GetNextNode();
	pos._GetNode()->_GetNextNode()->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_GetPrevNode()->_SetNextNode(pos._GetNode()->_GetNextNode());
	tempNode->_SetNextNode(nullptr);
	tempNode->_SetPrevNode(nullptr);
	delete tempNode;

	return returnIter;
}

void Deque::swap(Deque &deque)
{
	Deque tempDeque;
	size_t copySize = size();
	Node *cur = _head;
	for (size_t i = 0; i < copySize; i++)
	{
		tempDeque.push_back(cur->_GetValue());
		cur++;
	}
	clear();

	copySize = deque.size();
	cur = deque._head;
	for (size_t i = 0; i < copySize; i++)
	{
		push_back(cur->_GetValue());
		cur++;
	}
	deque.clear();

	copySize = tempDeque.size();
	cur = tempDeque._head;
	for (size_t i = 0; i < copySize; i++)
	{
		deque.push_back(cur->_GetValue());
		cur++;
	}
}

void Deque::clear()
{
	size_t clearSize = size();
	for (size_t i = 0; i < clearSize; i++)
		pop_back();
}

Deque::iterator Deque::emplace(Deque::const_iterator position, Deque::value_type val)
{
	iterator pos = position;
	Node *newNode = new Node();
	newNode->_SetValue(val);
	newNode->_SetNextNode(pos._GetNode());
	newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_SetPrevNode(newNode);
	pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

	return newNode;
}

Deque::iterator Deque::emplace_back(Deque::value_type val)
{
	Node *newNode = new Node();
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);

	return newNode;
}

Deque::iterator Deque::emplace_front(Deque::value_type val)
{
	Node *newNode = new Node();
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);

	return newNode;
}

