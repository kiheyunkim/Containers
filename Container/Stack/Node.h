#pragma once
#include<memory>
template<class T>
class Stack;

template<class T>
class Node
{
private:
	typedef T ValueType;

private:
	ValueType _value;
	Node<T>* _nextNode;
	Node<T>* _prevNode;

private:
	Node(): _prevNode(nullptr), _nextNode(nullptr) {}
	~Node() {}

	ValueType _GetValue() const { return _value; }
	ValueType& _GetAddr() { return _value; }
	Node<T>* _GetNextNode() const { return _prevNode; }
	Node<T>* _GetPrevNode() const { return _nextNode; }

	void _SetValue(ValueType value) { _value = value; }
	void _SetPrevNode(const Node<T>* ptr) { _prevNode = const_cast<Node<T>*>(ptr); }
	void _SetNextNode(const Node<T>* ptr) { _nextNode = const_cast<Node<T>*>(ptr); }

private:
	Node<T>& operator=(const Node<T>& node)
	{
		memcpy(this, &node, sizeof(Node<T>));
		return *this;
	}

	bool operator==(const Node<T>& node) { return _value == node._value() && _prevNode == node._prevNode&&_nextNode == node._nextNode }
	bool operator!=(const Node<T>& node) { return !(_value == node._value() && _prevNode == node._prevNode&&_nextNode == node._nextNode); }

	friend class Stack<T>;
};
