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

	for (Deque::Iterator iter = deque.ConstBegin(); iter != deque.ConstEnd(); iter++)
		PushBack(*iter);
}

Deque::~Deque() 
{
	delete _head;
	delete _rear; 
}

void Deque::operator=(const Deque& deque)
{
	Clear();
	Deque::SizeType copySize = Size();
	Deque::Iterator iter = static_cast<Deque::Iterator>(deque.ConstBegin());
	
	for (size_t i = 0; i < copySize; i++)
		PushBack(iter[i]);
}

Deque::Iterator Deque::Begin() { return  static_cast<Deque::Iterator>(*_head->_GetNextNode()); }
Deque::Iterator Deque::End() { return static_cast<Deque::Iterator>(*_rear); }
Deque::ReverseIterator Deque::ReverseBegin() { return static_cast<Deque::ReverseIterator>(*_rear->_GetPrevNode()); }
Deque::ReverseIterator Deque::ReverseEnd() { return static_cast<Deque::ReverseIterator>(*_head); }
Deque::ConstIterator Deque::ConstBegin() const { return static_cast<Deque::ConstIterator>(*_head->_GetNextNode()); }
Deque::ConstIterator Deque::ConstEnd() const { return static_cast<Deque::ConstIterator>(*_rear); }
Deque::ConstReverseIterator Deque::ConstReverseBegin() const { return static_cast<Deque::ConstReverseIterator>(*_rear->_GetPrevNode()); }
Deque::ConstReverseIterator Deque::ConstReverseEnd() const { return static_cast<Deque::ConstReverseIterator>(*_head); }

Deque::SizeType Deque::Size() const
{
	Deque::SizeType size = 0;
	Deque::Iterator tempIter = static_cast<Deque::Iterator>(ConstBegin());
	while (tempIter != ConstEnd())
	{
		size++;
		tempIter++;
	}
	return size;
}

//Deque::size_type Deque::max_size() { return 1; }

void Deque::Resize(Deque::SizeType newSize)
{
	Deque::SizeType originalSize = Size();
	if (newSize == originalSize) return;

	if (newSize < originalSize)
	{
		for (Deque::SizeType count = 0; count < originalSize - newSize; count++)
			PopBack();
		return;
	}

	if (newSize > originalSize)
	{
		for (Deque::SizeType count = 0; count < newSize - originalSize; count++)
			PushBack(0);
	}
}

bool Deque::Empty() const	{ return _head->_GetNextNode() == _rear; }

//void Deque::shrink_to_fit() {}

Deque::ValueType Deque::operator[](Deque::SizeType count)
{
	Node* cur = _head;

	for (Deque::SizeType i = 0; i < count; i++)
		cur = cur->_GetNextNode();

	return cur->_GetValue();
}

Deque::Reference Deque::At(Deque::SizeType n)
{
	Node* cur = _head;
	for (size_t i = 0; i < n; i++)
		cur = cur->_GetNextNode();

	return cur->_GetAddr();
}

Deque::ValueType Deque::Front() const { return _head->_GetNextNode()->_GetValue(); }

Deque::ValueType Deque::Back() const  { return _rear->_GetPrevNode()->_GetValue(); }


void Deque::Assign(const Iterator& first, const Iterator& last)
{
	Clear();

	Deque::Iterator temp = first;
	while (temp != last) { PushBack(temp._GetNode()->_GetValue()); }
}

void Deque::PushBack(Deque::ValueType val)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_rear->_GetPrevNode()->_GetNextNode());
	newNode->_SetPrevNode(_rear->_GetPrevNode());
	_rear->_GetPrevNode()->_SetNextNode(newNode);
	_rear->_SetPrevNode(newNode);
}

void Deque::PushFront(Deque::ValueType val)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);
}

void Deque::PopBack()
{
	if (Empty()) return;

	Node* cur = _rear->_GetPrevNode();
	cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
	cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
	cur->_SetPrevNode(nullptr);
	cur->_SetNextNode(nullptr);
	
	delete cur;
}

void Deque::PopFront()
{
	if (Empty()) return;

	Node* cur = _head->_GetNextNode();
	cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
	cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
	cur->_SetPrevNode(nullptr);
	cur->_SetNextNode(nullptr);
	
	delete cur;
}

Deque::Iterator Deque::Insert(Deque::ConstIterator& position, Deque::ValueType val)
{
	Deque::Iterator pos = position;
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);
	newNode->_SetNextNode(pos._GetNode());
	newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_SetPrevNode(newNode);
	pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

	return *newNode;
}

Deque::Iterator Deque::Erase(Deque::ConstIterator& position)
{
	Deque::Iterator pos = position;
	Node* tempNode = pos._GetNode();
	Deque::Iterator returnIter = static_cast<Deque::Iterator>(*pos._GetNode()->_GetNextNode());

	pos._GetNode()->_GetNextNode()->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_GetPrevNode()->_SetNextNode(pos._GetNode()->_GetNextNode());
	tempNode->_SetNextNode(nullptr);
	tempNode->_SetPrevNode(nullptr);
	delete tempNode;

	return returnIter;
}

void Deque::Swap(Deque& deque)
{
	Node* tempHead = deque._head;
	Node* tempRear = deque._rear;

	deque._head = _head;
	deque._rear = _rear;

	_head = tempHead;
	_rear = tempRear;
}

void Deque::Clear()
{
	Deque::SizeType clearSize = Size();
	for (Deque::SizeType i = 0; i < clearSize; i++)
		PopBack();
}

Deque::Iterator Deque::Emplace(Deque::ConstIterator& position, Deque::ValueType val)
{
	Deque::Iterator pos = position;
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);
	newNode->_SetNextNode(pos._GetNode());
	newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());
	pos._GetNode()->_SetPrevNode(newNode);
	pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);

	return static_cast<Deque::Iterator>(*newNode);
}

Deque::Iterator Deque::EmplaceBack(Deque::ValueType val)
{
	Node *newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);

	return static_cast<Deque::Iterator>(*newNode);
}

Deque::Iterator Deque::EmplaceFront(Deque::ValueType val)
{
	Node *newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head->_GetNextNode()->_GetPrevNode());
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);

	return static_cast<Deque::Iterator>(*newNode);
}

