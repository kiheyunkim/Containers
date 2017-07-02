#pragma once
#include<memory>

template<class T>
class Iterator;

template<class T>
class ReverseIterator;

template<class T>
class List;

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
	Node() :_prevNode(nullptr), _nextNode(nullptr) {}
	Node(const Node<T>& node) :_prevNode(nullptr), _nextNode(nullptr) { memcpy(this, &node, sizeof(Node<T>)); }
	~Node() {}

	ValueType _GetValue() const { return _value; }
	ValueType& _GetAddr() { return _value; }
	Node<T>* _GetNextNode() { return _nextNode; }
	Node<T>* _GetPrevNode() { return _prevNode; }
	void _SetValue(ValueType value) { _value = value; }
	void _SetPrevNode(const Node<T>* ptr) { _prevNode = const_cast<Node<T>*>(ptr); }
	void _SetNextNode(const Node<T>* ptr) { _nextNode = const_cast<Node<T>*>(ptr); }

private:
	Node& operator=(const Node<T>& node)
	{
		memcpy(this, &node, sizeof(Node<T>));
		return *this;
	}
	bool operator==(const Node<T>& node) const { return _value == node._value && _nextNode == node._nextNode && _prevNode == node._prevNode; }
	bool operator!=(const Node<T>& node) const { return !(_value == node._value && _nextNode == node._nextNode && _prevNode == node._prevNode); }

	friend class Iterator<T>;
	friend class ReverseIterator<T>;
	friend class List<T>;
};