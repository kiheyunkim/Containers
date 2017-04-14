#include "Stack.h"

Stack::Stack() :_top(nullptr) {}

Stack::Stack(const Stack &stack) : _top(nullptr)
{
	Node *cur = stack._top;

	size_t copySize = stack.size();
	Stack::value_type *copyArray = new Stack::value_type[copySize];

	for (Stack::size_type i = copySize - 1; i >= 0; i--)
	{
		copyArray[i] = cur->_GetValue();
		if (!i) break;
		cur = cur->_GetNextNode();
	}

	for (Stack::size_type i = 0; i < copySize; i++)
		this->push(copyArray[i]);

	delete copyArray;
}

Stack::~Stack() {}

void Stack::operator=(Stack &stack)
{
	while (!empty()) { pop(); }
	Node *cur = stack._top;

	Stack::size_type copySize = stack.size();
	Stack::value_type *newArray = new Stack::value_type(copySize);

	for (Stack::size_type i = copySize - 1; i >= 0; i--)
	{
		newArray[i] = cur->_GetValue();
		if (!i) break;
		cur = cur->_GetNextNode();
	}

	for (Stack::size_type i = 0; i < copySize; i++)
		this->push(newArray[i]);

	delete newArray;
}

bool Stack::empty() const { return _top == nullptr; }

Stack::size_type Stack::size() const
{
	if (empty()) return 0;
	Node* cur = _top;
	Stack::size_type count = 0;

	while (cur != nullptr)
	{
		count++;
		cur = cur->_GetNextNode();
	}
	return count;
}

Stack::reference Stack::top() { return *_top->_GetAddr(); }

void Stack::push(Stack::value_type val)
{
	if (empty())
	{
		Node *newNode = new Node();
		newNode->_SetValue(val);
		_top = newNode;
		return;
	}
	Node *newNode = new Node();
	newNode->_SetValue(val);
	newNode->_SetNextNode(_top);
	_top->_SetPrevNode(newNode);
	_top = newNode;
}

void Stack::emplace(Stack::value_type val)
{
	if (empty())
	{
		Node *newNode = new Node();
		newNode->_SetValue(val);
		_top = newNode;
		return;
	}
	Node *newNode = new Node();
	newNode->_SetValue(val);
	newNode->_SetNextNode(_top);
	_top->_SetPrevNode(newNode);
	_top = newNode;
}

void Stack::pop()
{
	if (empty()) return;
	if (_top->_GetNextNode() == nullptr)
	{
		delete(_top);
		_top = nullptr;
		return;
	}
	Node *temp = _top;
	_top = _top->_GetNextNode();
	temp->_SetPrevNode(nullptr);
	delete temp;
}

void Stack::swap(Stack &stack)
{
	Node *temp = _top;
	_top = stack._top;
	stack._top = temp;
}