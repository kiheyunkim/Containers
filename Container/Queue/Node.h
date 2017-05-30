#pragma once
#include<memory>
#include "Node.h"

template<class T>
class Queue;

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
	Node();
	Node(const Node<T>& node);
	~Node();
	ValueType _GetValue() const { return _value; }
	ValueType& _GetAddr() { return _value; }
	Node<T>* _GetNextNode() const;
	Node<T>* _GetPrevNode() const;
	void _SetValue(ValueType value) { _value = value; }
	void _SetPrevNode(const Node<T>* ptr);
	void _SetNextNode(const Node<T>* ptr);

private:
	Node<T>& operator=(const Node<T>& node);
	bool operator==(const Node<T>& node);
	bool operator!=(const Node<T>& node);

	friend class Queue<T>;
};

template<class T>
Node<T>::Node() :_value(0), _prevNode(nullptr), _nextNode(nullptr) {}

template<class T>
Node<T>::Node(const Node<T>& node) { memcpy(this, &node, sizeof(Node)); }

template<class T>
Node<T>::~Node() {}

template<class T>
Node<T>* Node<T>::_GetPrevNode() const { return _prevNode; }

template<class T>
Node<T>* Node<T>::_GetNextNode() const { return _nextNode; }

template<class T>
void Node<T>::_SetPrevNode(const Node<T> *ptr) { _prevNode = const_cast<Node<T>*>(ptr); }

template<class T>
void Node<T>::_SetNextNode(const Node<T> *ptr) { _nextNode = const_cast<Node<T>*>(ptr); }

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& node)
{
	memcpy(this, &node, sizeof(Node<T>));
	return *this;
}

template<class T>
bool Node<T>::operator==(const Node<T>& node) { return _value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode; }

template<class T>
bool Node<T>::operator!=(const Node<T>& node) { return !(_value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode); }