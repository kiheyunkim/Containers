#include "Deque.h"



Deque::Deque() :_head(nullptr), _rear(nullptr)
{
	Node* headDummyNode = static_cast<Node*>(new Node());
	Node* rearDummyNode = static_cast<Node*>(new Node());
	_head = headDummyNode;
	_rear = rearDummyNode;
	_head->_SetNextNode(_rear);
	_rear->_SetPrevNode(_head);
}

Deque::Deque(const Deque& deque) :_head(nullptr), _rear(nullptr)
{
	Node* headDummyNode = static_cast<Node*>(new Node());
	Node* rearDummyNode = static_cast<Node*>(new Node());
	_head = headDummyNode;
	_rear = rearDummyNode;
	_head->_SetNextNode(_rear);
	_rear->_SetPrevNode(_head);

	for (Iterator iter = deque.cbegin(); iter != deque.cend(); iter++)
		push_back(*iter);
}

Deque::~Deque() 
{
	delete _head;
	delete _rear; 
}

void Deque::operator=(const Deque& deque)
{
	clear();
	size_t copySize = size();
	Iterator iter = static_cast<Iterator>(deque.cbegin());
	
	for (size_t i = 0; i < copySize; i++)
		push_back(iter[i]);
}

Deque::iterator Deque::begin() { return  static_cast<Iterator>(*_head->_GetNextNode()); }
Deque::iterator Deque::end() { return static_cast<Iterator>(*_rear); }
Deque::reverse_iterator Deque::rbegin() { return static_cast<Reverse_Iterator>(*_rear->_GetPrevNode()); }
Deque::reverse_iterator Deque::rend() { return static_cast<Reverse_Iterator>(*_head); }
Deque::const_iterator Deque::cbegin() const { return static_cast<const_iterator>(*_head->_GetNextNode()); }
Deque::const_iterator Deque::cend() const { return static_cast<const_iterator>(*_rear); }
Deque::const_reverse_iterator Deque::crbegin() const { return static_cast<const_reverse_iterator>(*_rear->_GetPrevNode()); }
Deque::const_reverse_iterator Deque::crend() const { return static_cast<const_reverse_iterator>(*_head); }

Deque::size_type Deque::size() const
{
	size_t size = 0;
	Deque::iterator tempIter = static_cast<Iterator>(cbegin());
	while (tempIter != cend())
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

bool Deque::empty() const	{ return _head->_GetNextNode() == _rear; }

//void Deque::shrink_to_fit() {}

Deque::value_type Deque::operator[](size_t count)
{
	Node* cur = _head;

	for (size_t i = 0; i < count; i++)
		cur = cur->_GetNextNode();

	return cur->_GetValue();
}

Deque::reference Deque::at(size_t n)
{
	Node* cur = _head;
	for (size_t i = 0; i < n; i++)
		cur = cur->_GetNextNode();

	return cur->_GetAddr();
}

Deque::value_type Deque::front() const { return _head->_GetNextNode()->_GetValue(); }

Deque::value_type Deque::back() const  { return _rear->_GetPrevNode()->_GetValue(); }


void Deque::assign(const Iterator& first, const Iterator& last)
{
	clear();

	Iterator temp = first;
	while (temp != last) { push_back(temp._GetNode()->_GetValue()); }
}

void Deque::push_back(Deque::value_type val)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_rear->_GetPrevNode()->_GetNextNode());
	newNode->_SetPrevNode(_rear->_GetPrevNode());
	_rear->_GetPrevNode()->_SetNextNode(newNode);
	_rear->_SetPrevNode(newNode);
}

void Deque::push_front(Deque::value_type val)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);
}

void Deque::pop_back()
{
	if (empty()) return;

	Node* cur = _rear->_GetPrevNode();
	cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
	cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
	cur->_SetPrevNode(nullptr);
	cur->_SetNextNode(nullptr);
	
	delete cur;
}

void Deque::pop_front()
{
	if (empty()) return;

	Node* cur = _head->_GetNextNode();
	cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
	cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
	cur->_SetPrevNode(nullptr);
	cur->_SetNextNode(nullptr);
	
	delete cur;
}

Deque::iterator Deque::insert(const_iterator& position, value_type val)
{
	Iterator pos = position;
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);
	newNode->_SetNextNode(pos._GetNode());
	newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_SetPrevNode(newNode);
	pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

	return *newNode;
}

Deque::iterator Deque::erase(Deque::const_iterator& position)
{
	Iterator pos = position;
	Node* tempNode = pos._GetNode();
	Iterator returnIter = static_cast<Iterator>(*pos._GetNode()->_GetNextNode());

	pos._GetNode()->_GetNextNode()->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_GetPrevNode()->_SetNextNode(pos._GetNode()->_GetNextNode());
	tempNode->_SetNextNode(nullptr);
	tempNode->_SetPrevNode(nullptr);
	delete tempNode;

	return returnIter;
}

void Deque::swap(Deque& deque)
{
	Node* tempHead = deque._head;
	Node* tempRear = deque._rear;

	deque._head = _head;
	deque._rear = _rear;

	_head = tempHead;
	_rear = tempRear;
}

void Deque::clear()
{
	size_t clearSize = size();
	for (size_t i = 0; i < clearSize; i++)
		pop_back();
}

Deque::iterator Deque::emplace(Deque::const_iterator& position, Deque::value_type val)
{
	iterator pos = position;
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);
	newNode->_SetNextNode(pos._GetNode());
	newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_SetPrevNode(newNode);
	pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

	return static_cast<iterator>(*newNode);
}

Deque::iterator Deque::emplace_back(Deque::value_type val)
{
	Node *newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);

	return static_cast<iterator>(*newNode);
}

Deque::iterator Deque::emplace_front(Deque::value_type val)
{
	Node *newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);

	return static_cast<iterator>(*newNode);
}

