#ifndef _STACK_H_
#define _STACK_H_
#include"Node.h"

template<class T>
class Stack
{
private:
	Node<T> *top;

public:
	typedef T ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;

public:
	Stack() :top(nullptr) {}
	Stack(const Stack<T>& stack) :top(nullptr)
	{
		Node<T>* cur = stack.top;
		Stack<T>::SizeType copySize = stack.Size();

		Stack<T>::ValueType* copyArray = static_cast<Stack<T>::ValueType*>(new Stack<T>::ValueType[copySize]);

		for (Stack<T>::SizeType i = copySize - 1; i >= 0; i--)
		{
			copyArray[i] = cur->getValue();
			if (i == 0) break;
			cur = cur->getNextNode();
		}

		for (Stack<T>::SizeType i = 0; i < copySize; i++)
			this->Push(copyArray[i]);

		delete[] copyArray;
	}

	~Stack() {}

	void operator=(const Stack<T>& stack)
	{
		while (!Empty()) { Pop(); }
		Node<T>* cur = stack.top;

		Stack<T>::SizeType copySize = stack.Size();
		Stack<T>::ValueType* newArray = static_cast<Stack<T>::ValueType*>(new Stack<T>::ValueType[copySize]);

		for (Stack<T>::SizeType i = copySize - 1; i >= 0; i--)
		{
			newArray[i] = cur->getValue();
			if (i == 0) break;
			cur = cur->getNextNode();
		}

		for (Stack<T>::SizeType i = 0; i < copySize; i++)
			this->Push(newArray[i]);

		delete[] newArray;
	}

	bool Empty() const { return top == nullptr; }

	SizeType Size() const
	{
		if (Empty()) return 0;
		Node<T>* cur = top;
		Stack<T>::SizeType count = 0;

		while (cur != nullptr)
		{
			count++;
			cur = cur->getNextNode();
		}
		return count;
	}

	Reference Top() { return top->getAddr(); }

	void Push(ValueType val)
	{
		if (Empty())
		{
			Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
			newNode->setValue(val);
			top = newNode;
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(val);
		top->setNextNode(newNode);
		newNode->setPrevNode(top);
		top = newNode;
	}

	void Emplace(ValueType val)
	{
		if (Empty())
		{
			Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
			newNode->setValue(val);
			top = newNode;
			return;
		}
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(val);
		top->setNextNode(newNode);
		newNode->setPrevNode(_top);
		top = newNode;
	}

	void Pop()
	{
		if (Empty()) return;
		if (top->getNextNode() == nullptr)
		{
			delete(top);
			top = nullptr;
			return;
		}
		Node<T>* temp = top;
		top = top->getNextNode();
		temp->setPrevNode(nullptr);
		delete temp;
	}

	void Swap(Stack<T> &stack)
	{
		Node<T>* temp = top;
		top = stack.top;
		stack.top = temp;
	}
};

#endif // !_STACK_H_