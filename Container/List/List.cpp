#include "Iterator.h"
#include "Node.h"
#include "List.h"

List::List() :_head(nullptr), _tail(nullptr)
{
	Node* dummyHeadNode = static_cast<Node*>(new Node());
	Node* dummyTailNode = static_cast<Node*>(new Node());
	_head = dummyHeadNode;
	_tail = dummyTailNode;
	_head->_SetNextNode(_tail);
	_tail->_SetPrevNode(_head);
}

List::List(const List& list) :_head(nullptr), _tail(nullptr)
{
	Node* dummyHeadNode = static_cast<Node*>(new Node());
	Node* dummyTailNode = static_cast<Node*>(new Node());
	_head = dummyHeadNode;
	_tail = dummyTailNode;
	_head->_SetNextNode(_tail);
	_tail->_SetPrevNode(_head);

	List::Iterator iter = list.ConstBegin();
	while (iter != list.ConstEnd())
	{
		PushBack(*iter);
		iter++;
	}
}

List::~List() 
{
	delete _head;
	delete _tail; 
}

//opreator
List& List::operator=(const List& targetList) 
{
	Node* cur = _head->_GetNextNode();
	List::SizeType copySize = Size();
	
	for (List::SizeType i = 0; i < copySize; i++)
	{
		PushBack(cur->_GetValue());
		cur = cur->_GetNextNode();
	}

	return *this;
}

//Iterators
List::Iterator List::Begin() { return static_cast<List::Iterator>(*_head->_GetNextNode()); }
List::Iterator List::End() { return static_cast<List::Iterator>(*_tail); }
List::ReverseIterator List::ReverseBegin() { return static_cast<List::ReverseIterator>(*_tail->_GetPrevNode()); }
List::ReverseIterator List::ReverseEnd() { return static_cast<List::ReverseIterator>(*_head); }
List::ConstIterator List::ConstBegin() const { return static_cast<List::ConstIterator>(*_head->_GetNextNode()); }
List::ConstIterator List::ConstEnd() const { return static_cast<List::ConstIterator>(*_tail); }
List::ConstReverseIterator List::ConstReverseBegin()const { return static_cast<List::ConstReverseIterator>(*_tail->_GetPrevNode()); }
List::ConstReverseIterator List::ConstReverseEnd()const { return static_cast<List::ConstReverseIterator>(*_head); }
	
//capacity
bool List::Empty() const { return _head->_GetNextNode() == _tail; }

List::SizeType List::Size() const
{
	int size = 0;
	List::Iterator tempIter = static_cast<List::Iterator>(*_head->_GetNextNode());
	while (tempIter != ConstEnd())
	{
		size++;
		tempIter++;
	}
	return size;
}

List::SizeType List::MaxSize() { return -1; }

//Element access
List::Reference List::Front() { return _head->_GetAddr(); }
List::Reference List::Back() { return _tail->_GetPrevNode()->_GetAddr(); }

//Modifiers
void List::Assign(List::SizeType n, List::ValueType value) 
{
	for (List::SizeType i = 0; i < n; i++)  
		PushBack(value); 
}

void List::EmplaceFront(List::ValueType value)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(value);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head);
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);
}

void List::PushFront(List::ValueType value)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(value);
	
	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head);
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);
}

void List::PopFront()
{
	if (Empty()) return;

	Node* tempNode = _head->_GetNextNode();
	tempNode->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
	tempNode->_GetNextNode()->_SetPrevNode(tempNode->_GetPrevNode());
	tempNode->_SetPrevNode(nullptr);
	tempNode->_SetNextNode(nullptr);

	delete tempNode;
}

void List::EmplaceBack(List::ValueType value)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(value);

	newNode->_SetNextNode(_tail->_GetPrevNode()->_GetNextNode());
	newNode->_SetPrevNode(_tail->_GetPrevNode());
	_tail->_GetPrevNode()->_SetNextNode(newNode);
	_tail->_SetPrevNode(newNode);
}

void List::PushBack(List::ValueType value)
{
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(value);

	newNode->_SetNextNode(_tail->_GetPrevNode()->_GetNextNode());
	newNode->_SetPrevNode(_tail->_GetPrevNode());
	_tail->_GetPrevNode()->_SetNextNode(newNode);
	_tail->_SetPrevNode(newNode);
}

void List::PopBack() 
{
	Node* tempNode = _tail->_GetPrevNode();
	_tail->_SetPrevNode(tempNode->_GetPrevNode());
	_tail->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
	tempNode->_SetPrevNode(nullptr);
	tempNode->_SetNextNode(nullptr);

	delete tempNode;
}

Iterator List::Insert(List::ConstIterator& pos, List::ValueType val)		
{
	Node* newNode = static_cast<Node*>(new Node());

	newNode->_SetValue(val);
	newNode->_SetNextNode(const_cast<List::Iterator&>(pos)._GetNode());
	newNode->_SetPrevNode(const_cast<List::Iterator&>(pos)._GetNode()->_GetPrevNode());
	const_cast<List::Iterator&>(pos)._GetNode()->_GetPrevNode()->_SetNextNode(newNode);
	const_cast<List::Iterator&>(pos)._GetNode()->_SetPrevNode(newNode);
	
	return static_cast<List::Iterator>(*newNode);
}

Iterator List::Erase(List::ConstIterator& pos)
{
	Node* tempNode = const_cast<List::Iterator&>(pos)._GetNode();
	List::Iterator iter = static_cast<List::Iterator>(*tempNode);

	tempNode->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
	tempNode->_GetNextNode()->_SetPrevNode(tempNode->_GetPrevNode());
	tempNode->_SetPrevNode(nullptr);
	tempNode->_SetNextNode(nullptr);

	delete tempNode;
	return static_cast<List::Iterator>(iter);
}

void List::Swap(List& list)
{
	Node* headTemp = _head;
	Node* tailTemp = _tail;

	_head = list._head;
	_tail = list._tail;
	
	list._head = headTemp;
	list._tail = tailTemp;
}

void List::Resize(List::SizeType size)
{
	List::SizeType originalSize = this->Size();
	if (this->Size() > size)
	{
		for (List::SizeType i = 0; i < originalSize - size; i++)
			this->PopBack();
		return;
	}
	for (List::SizeType i = 0; i < size - originalSize + 1; i++)
		this->PushBack(0);
}

void List::Clear()
{
	List::SizeType count = Size();
	for (List::SizeType i = 0; i < count; i++)
		this->PopBack();
}

//Operations
void List::Splice(List::ConstIterator& iter, List& list)
{
	List::Iterator tempiter = list.Begin();
	List::SizeType copySize = list.Size();
	for (List::SizeType i = 0; i < copySize; i++)
	{
		Insert(iter, *tempiter);
		tempiter++;
	}
}

void List::Remove(int val)
{
	if (Empty()) return;

	List::Iterator iter = static_cast<List::Iterator>(*_head);	

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

void List::RemoveIf(bool(*compare)(int))
{
	if (Empty()) return;

	List::Iterator iter = static_cast<List::Iterator>(*_head);

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

void List::Unique()
{
	if (Empty()) return;
	List::Iterator iter1 = Begin();
	List::Iterator iter2 = static_cast<List::Iterator>(*Begin()._GetNode()->_GetNextNode());

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

void List::Merge(List& list)
{
	while (list.Size() != 0)
	{
		PushBack(list.Front());
		list.PopFront();
	}
}

void List::Sort()						//use Selection Sorting
{
	if (Empty()) return;
	if (Size() == 1) return;

	List::SizeType length = Size();
	List::Iterator iter = Begin();

	int* tempArray = static_cast<int*>(new int[length]);

	for (List::SizeType i = 0; i < length; i++)
	{
		tempArray[i] = iter._GetNode()->_GetValue();
		iter = static_cast<List::Iterator>(*iter._GetNode()->_GetNextNode());
	}

	int minPos = 0;
	int insertPos = 0;

	for (List::SizeType pass = 0; pass < length - 1; pass++)
	{
		minPos = insertPos;
		for (List::SizeType i = insertPos + 1; i < length; i++)
		{
			if (tempArray[i] < tempArray[minPos])
				minPos = i;
		}
		_swap(tempArray[minPos], tempArray[insertPos]);
		insertPos++;
	}

	Clear();
	for (List::SizeType i = 0; i < length; i++)
		PushBack(tempArray[i]);

	delete[] tempArray;
}

void List::Reverse()
{
	List tempList;
	tempList.Splice(tempList.Begin(), *this);
	Clear();

	while (!tempList.Empty())
	{
		PushBack(tempList.Back());
		tempList.PopBack();
	}
}

void List::_swap(List::ValueType &x1, List::ValueType &x2)
{
	List::ValueType temp = x1;
	x1 = x2;
	x2 = temp;
}