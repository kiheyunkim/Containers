#pragma once
#include"Node.h"

template<class T>
class Stack
{
private:
	Node<T> *_top;

public:
	typedef T ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;

public:
	Stack() :_top(nullptr) {}
	Stack(const Stack<T>& stack):_top(nullptr)
	{
		Node<T>* cur = stack._top;
		Stack<T>::SizeType copySize = stack.Size();

		Stack<T>::ValueType* copyArray = static_cast<Stack<T>::ValueType*>(new Stack<T>::ValueType[copySize]);

		for (Stack<T>::SizeType i = copySize - 1; i >= 0; i--)
		{
			copyArray[i] = cur->_GetValue();
			if (!i) break;
			cur = cur->_GetNextNode();
		}

		for (Stack<T>::SizeType i = 0; i < copySize; i++)
			this->Push(copyArray[i]);

		delete[] copyArray;
	}

	~Stack() {}

	void operator=(const Stack<T>& stack)
	{
		while (!Empty()) { Pop(); }
		Node<T>* cur = stack._top;

		Stack<T>::SizeType copySize = stack.Size();
		Stack<T>::ValueType* newArray = static_cast<Stack<T>::ValueType*>(new Stack<T>::ValueType[copySize]);

		for (Stack<T>::SizeType i = copySize - 1; i >= 0; i--)
		{
			newArray[i] = cur->_GetValue();
			if (!i) break;
			cur = cur->_GetNextNode();
		}

		for (Stack<T>::SizeType i = 0; i < copySize; i++)
			this->Push(newArray[i]);

		delete[] newArray;
	}

	bool Empty() const { return _top == nullptr; }
	
	SizeType Size() const
	{
		if (Empty()) return 0;
		Node<T>* cur = _top;
		Stack<T>::SizeType count = 0;

		while (cur != nullptr)
		{
			count++;
			cur = cur->_GetNextNode();
		}
		return count;
	}
	
	Reference Top() { return _top->_GetAddr(); }
	
	void Push(ValueType val)
	{
		if (Empty())
		{
			Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
			newNode->_SetValue(val);
			_top = newNode;
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(val);
		_top->_SetNextNode(newNode);
		newNode->_SetPrevNode(_top);
		_top = newNode;
	}
	
	void Emplace(ValueType val)
	{
		if (Empty())
		{
			Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
			newNode->_SetValue(val);
			_top = newNode;
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->_SetValue(val);
		_top->_SetNextNode(newNode);
		newNode->_SetPrevNode(_top);
		_top = newNode;
	}
	
	void Pop()
	{
		if (Empty()) return;
		if (_top->_GetNextNode() == nullptr)
		{
			delete(_top);
			_top = nullptr;
			return;
		}
		Node<T>* temp = _top;
		_top = _top->_GetNextNode();
		temp->_SetPrevNode(nullptr);
		delete temp;
	}
	
	void Swap(Stack<T> &stack)
	{
		Node<T>* temp = _top;
		_top = stack._top;
		stack._top = temp;
	}
};
