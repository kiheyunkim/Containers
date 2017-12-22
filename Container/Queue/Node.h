#ifndef _NODE_H_
#define _NODE_H_

#include <memory>
#include "Node.h"

template<class T>
class Queue;

template<class T>
class Node
{
private:
	typedef T ValueType;

private:
	ValueType value;
	Node<T>* nextNode;
	Node<T>* prevNode;

private:
	Node() :value(0), prevNode(nullptr), nextNode(nullptr) {}
	Node(const Node<T>& node) { memcpy(this, &node, sizeof(Node)); }
	~Node() {}
	ValueType getValue() const { return value; }
	ValueType& getAddr() { return value; }
	Node<T>* getNextNode() const { return prevNode; }
	Node<T>* getPrevNode() const { return nextNode; }
	void setValue(ValueType value) { this->value = value; }
	void setPrevNode(const Node<T>* ptr) { prevNode = const_cast<Node<T>*>(ptr); }
	void setNextNode(const Node<T>* ptr) { nextNode = const_cast<Node<T>*>(ptr); }

private:
	Node<T>& operator=(const Node<T>& node)
	{
		memcpy(this, &node, sizeof(Node<T>));
		return *this;
	}
	bool operator==(const Node<T>& node) { return value == node.value&&nextNode == node.nextNode&&prevNode == node.prevNode; }
	bool operator!=(const Node<T>& node) { return !(value == node.value&&nextNode == node.nextNode&&prevNode == node.prevNode); }

	friend class Queue<T>;
};

#endif // !_NODE_H_