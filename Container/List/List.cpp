#include "Iterator.h"
#include "Node.h"
#include "List.h"

List::List() :_head(nullptr), _tail(nullptr)
{
	Node *dummyHeadNode = new Node();
	Node *dummyTailNode = new Node();
	_head = dummyHeadNode;
	_tail = dummyTailNode;
	_head->_SetNextNode(_tail);
	_tail->_SetPrevNode(_head);
}

List::List(List &list) :_head(nullptr), _tail(nullptr)
{
	Node *dummyHeadNode = new Node();
	Node *dummyTailNode = new Node();
	_head = dummyHeadNode;
	_tail = dummyTailNode;
	_head->_SetNextNode(_tail);
	_tail->_SetPrevNode(_head);

	Iterator iter = list.begin();
	while (iter != list.end())
	{
		push_back(*iter);
		iter++;
	}
}

List::~List() 
{
	delete _head;
	delete _tail; 
}

//opreator
void List::operator=(List &targetList) 
{
	Node *cur = _head->_GetNextNode();
	size_t copySize = size();
	
	for (size_t i = 0; i < copySize; i++)
	{
		push_back(cur->_GetValue());
		cur = cur->_GetNextNode();
	}
}

//Iterators
List::iterator List::begin() { return _head->_GetNextNode(); }
List::iterator List::end() { return _tail; }
List::reverse_iterator List::rbegin() { return _tail->_GetPrevNode(); }
List::reverse_iterator List::rend() { return _head; }
List::const_iterator List::cbegin() { return _head->_GetNextNode(); }
List::const_iterator List::cend() { return _tail; }
List::const_reverse_iterator List::crbegin() { return _tail->_GetPrevNode(); }
List::const_reverse_iterator List::crend() { return _head; }
	
//capacity
bool List::empty() { return _head->_GetNextNode() == _tail; }

List::size_type List::size()
{
	int size = 0;
	Node *cur = _head->_GetNextNode();
	while (cur != end()._GetNode())
	{
		size++;
		cur = cur->_GetNextNode();
	}
	return size;
}

List::size_type List::max_size() { return -1; }

//Element access
List::reference List::front() { return _head->_GetAddr(); }

List::reference List::back() { return _tail->_GetPrevNode()->_GetAddr(); }

//Modifiers
void List::assign(size_type n, List::valueType value) 
{
	for (size_t i = 0; i < n; i++)  
		push_back(value); 
}

void List::emplace_front(List::valueType value)
{
	Node *newNode = new Node();
	newNode->_SetValue(value);

	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head);
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);
}

void List::push_front(List::valueType value)
{
	Node *newNode = new Node();
	newNode->_SetValue(value);
	
	newNode->_SetNextNode(_head->_GetNextNode());
	newNode->_SetPrevNode(_head);
	_head->_GetNextNode()->_SetPrevNode(newNode);
	_head->_SetNextNode(newNode);
}

void List::pop_front()
{
	if (empty()) return;

	Node *tempNode = _head->_GetNextNode();
	tempNode->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
	tempNode->_GetNextNode()->_SetPrevNode(tempNode->_GetPrevNode());
	tempNode->_SetPrevNode(nullptr);
	tempNode->_SetNextNode(nullptr);

	delete tempNode;
}

void List::emplace_back(List::valueType value)
{
	Node *newNode = new Node();
	newNode->_SetValue(value);

	newNode->_SetNextNode(_tail->_GetPrevNode()->_GetNextNode());
	newNode->_SetPrevNode(_tail->_GetPrevNode());
	_tail->_GetPrevNode()->_SetNextNode(newNode);
	_tail->_SetPrevNode(newNode);
}

void List::push_back(List::valueType value)
{
	Node *newNode = new Node();
	newNode->_SetValue(value);

	newNode->_SetNextNode(_tail->_GetPrevNode()->_GetNextNode());
	newNode->_SetPrevNode(_tail->_GetPrevNode());
	_tail->_GetPrevNode()->_SetNextNode(newNode);
	_tail->_SetPrevNode(newNode);
}

void List::pop_back() 
{
	Node *tempNode = _tail->_GetPrevNode();
	_tail->_SetPrevNode(tempNode->_GetPrevNode());
	_tail->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
	tempNode->_SetPrevNode(nullptr);
	tempNode->_SetNextNode(nullptr);

	delete tempNode;
}

Iterator List::insert(List::iterator pos, List::valueType val)		
{
	Node *newNode = new Node();
	newNode->_SetValue(val);

	newNode->_SetNextNode(pos._GetNode());
	newNode->_SetPrevNode(pos._GetNode()->_GetPrevNode());

	pos._GetNode()->_GetPrevNode()->_SetNextNode(newNode);
	pos._GetNode()->_SetPrevNode(newNode);
	
	return newNode;
}

Iterator List::erase(Iterator pos)
{
	Node *tempNode = pos._GetNode();
	Node returnNode = *tempNode;
	tempNode->_GetPrevNode()->_SetNextNode(tempNode->_GetNextNode());
	tempNode->_GetNextNode()->_SetPrevNode(tempNode->_GetPrevNode());
	tempNode->_SetPrevNode(nullptr);
	tempNode->_SetNextNode(nullptr);

	delete tempNode;
	return &returnNode;
}

void List::swap(List &list)
{
	Node *headTemp = _head;
	Node *tailTemp = _tail;
	_head = list._head;
	_tail = list._tail;
	list._head = headTemp;
	list._tail = tailTemp;
}

void List::resize(size_t size)
{
	size_t originalSize = this->size();
	if (this->size() > size)
	{
		for (size_t i = 0; i < originalSize - size; i++)
			this->pop_back();
		return;
	}
	for (size_t i = 0; i < size - originalSize + 1; i++)
		this->push_back(0);
}

void List::clear()
{
	size_t count = size();
	for (size_t i = 0; i < count; i++)
		this->pop_back();
}

//Operations
void List::splice(Iterator iter, List *list)
{
	Iterator tempiter = list->begin();
	size_t copySize = list->size();
	this;
	for (size_t i = 0; i < copySize; i++)
	{
		insert(iter, *tempiter);
		tempiter++;
	}
}

void List::remove(int val)
{
	if (empty()) return;

	List::iterator iter = _head;	

	while (iter._GetNode()->_GetNextNode() != end()._GetNode())
	{
		if (iter._GetNode()->_GetValue() == val)
		{
			List::iterator tempiter = iter;
			iter++;
			erase(tempiter);
			continue;
		}
		iter++;
	}
}

void List::remove_if(bool(*compare)(const int&))
{
	if (empty()) return;

	List::iterator iter = _head;

	while (iter._GetNode() != end()._GetNode())
	{
		if (compare(iter._GetNode()->_GetValue()))
		{
			List::iterator tempiter = iter;
			iter++;
			erase(tempiter);
			continue;
		}
		iter++;
	}
}

void List::unique()
{
	if (empty()) return;
	List::iterator iter1 = begin();
	List::iterator iter2 = begin()._GetNode()->_GetNextNode();

	while (iter1 != end()._GetNode() && iter2 != end()._GetNode())
	{
		if (iter2._GetNode() == end()._GetNode())
		{
			iter1++;
			iter2 = iter1++;
		}

		if (iter1._GetNode()->_GetValue() == iter2._GetNode()->_GetValue())
		{
			List::iterator tempiter = iter2;
			iter2++;
			erase(tempiter);
			continue;
		}
		iter2++;
	}
}

void List::merge(List list)
{
	while (list.size() != 0)
	{
		push_back(list.front());
		list.pop_front();
	}
}

void List::sort()						//use Selection Sorting
{
	if (empty()) return;
	if (size() == 1) return;

	size_t length = size();
	List::iterator iter = begin();

	int *tempArray = new int[length];

	for (size_t i = 0; i < length; i++)
	{
		tempArray[i] = iter._GetNode()->_GetValue();
		iter=iter._GetNode()->_GetNextNode();
	}

	int minPos = 0;
	int insertPos = 0;

	for (size_t pass = 0; pass < length - 1; pass++)
	{
		minPos = insertPos;
		for (size_t i = insertPos + 1; i < length; i++)
		{
			if (tempArray[i] < tempArray[minPos])
				minPos = i;
		}
		_swap(&tempArray[minPos], &tempArray[insertPos]);
		insertPos++;
	}

	clear();
	for (size_t i = 0; i < length; i++)
		push_back(tempArray[i]);

	delete tempArray;
}

void List::reverse()
{
	List tempList;
	tempList.splice(tempList.begin(), this);
	clear();

	while (!tempList.empty())
	{
		push_back(tempList.back());
		tempList.pop_back();
	}
}

void List::_swap(int *x1, int *x2)
{
	int temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}