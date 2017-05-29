#include "Stack.h"

Stack::Stack() :_top(nullptr) {}

Stack::Stack(const Stack& stack) : _top(nullptr)
{
	Node* cur = stack._top;
	Stack::SizeType copySize = stack.Size();

	Stack::ValueType* copyArray = static_cast<Stack::ValueType*>(new Stack::ValueType[copySize]);

	for (Stack::SizeType i = copySize - 1; i >= 0; i--)
	{
		copyArray[i] = cur->_GetValue();
		if (!i) break;
		cur = cur->_GetNextNode();
	}

	for (Stack::SizeType i = 0; i < copySize; i++)
		this->Push(copyArray[i]);

	delete[] copyArray;
}

Stack::~Stack() {}

void Stack::operator=(const Stack& stack)
{
	while (!Empty()) { Pop(); }
	Node* cur = stack._top;

	Stack::SizeType copySize = stack.Size();
	Stack::ValueType* newArray = static_cast<Stack::ValueType*>(new Stack::ValueType[copySize]);

	for (Stack::SizeType i = copySize - 1; i >= 0; i--)
	{
		newArray[i] = cur->_GetValue();
		if (!i) break;
		cur = cur->_GetNextNode();
	}

	for (Stack::SizeType i = 0; i < copySize; i++)
		this->Push(newArray[i]);

	delete[] newArray;
}

bool Stack::Empty() const { return _top == nullptr; }

Stack::SizeType Stack::Size() const
{
	if (Empty()) return 0;
	Node* cur = _top;
	Stack::SizeType count = 0;

	while (cur != nullptr)
	{
		count++;
		cur = cur->_GetNextNode();
	}
	return count;
}

Stack::Reference Stack::Top() { return _top->_GetAddr(); }

void Stack::Push(Stack::ValueType val)
{
	if (Empty())
	{
		Node* newNode = static_cast<Node*>(new Node());
		newNode->_SetValue(val);
		_top = newNode;
		return;
	}
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);
	newNode->_SetNextNode(_top);
	_top->_SetPrevNode(newNode);
	_top = newNode;
}

void Stack::Emplace(Stack::ValueType val)
{
	if (Empty())
	{
		Node* newNode = static_cast<Node*>(new Node());
		newNode->_SetValue(val);
		_top = newNode;
		return;
	}
	Node* newNode = static_cast<Node*>(new Node());
	newNode->_SetValue(val);
	newNode->_SetNextNode(_top);
	_top->_SetPrevNode(newNode);
	_top = newNode;
}

void Stack::Pop()
{
	if (Empty()) return;
	if (_top->_GetNextNode() == nullptr)
	{
		delete(_top);
		_top = nullptr;
		return;
	}
	Node* temp = _top;
	_top = _top->_GetNextNode();
	temp->_SetPrevNode(nullptr);
	delete temp;
}

void Stack::Swap(Stack &stack)
{
	Node *temp = _top;
	_top = stack._top;
	stack._top = temp;
}