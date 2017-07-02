#pragma once
#include<memory>

template<typename T>
class Node
{
private:
	typedef T ValueType;

private:
	ValueType _value;
	Node<T>* _nextNode;
	Node<T>* _prevNode;


public:
	Node() :_prevNode(nullptr), _nextNode(nullptr) {}
	Node(const Node<T>& node) { memcpy(this, &node, sizeof(Node)); }
	~Node() {}
	ValueType _GetValue() const { return _value; }
	ValueType& _GetAddr() { return _value; }
	Node<T>* _GetPrevNode() { return _prevNode; }
	Node<T>* _GetNextNode() { return _nextNode; }
	void _SetValue(ValueType value) { _value = value; }
	void _SetPrevNode(const Node<T>* ptr) { _prevNode = const_cast<Node<T>*>(ptr); }
	void _SetNextNode(const Node<T>* ptr) { _nextNode = const_cast<Node<T>*>(ptr); }

public:
	Node<T>& operator=(const Node<T>& node)
	{
		memcpy(this, &node, sizeof(Node<T>));
		return *this;
	}
	bool operator==(const Node<T>& node) const { return _value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode; }
	bool operator!=(const Node<T>& node) const { return !(_value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode); }
};