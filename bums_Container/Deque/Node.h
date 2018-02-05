#ifndef _NODE_H_
#define _NODE_H_
#include<memory>

template<typename T>
class Iterator;

template<typename T>
class ReverseIterator;

template<typename T>
class Deque;

template<typename T>
class Node
{
private:
	typedef T ValueType;

private:
	ValueType value;
	Node<T>* nextNode;
	Node<T>* prevNode;


private:
	Node() :prevNode(nullptr), nextNode(nullptr) {}
	Node(const Node<T>& node) { memcpy(this, &node, sizeof(Node)); }
	~Node() {}

private:
	ValueType getValue() const { return value; }
	ValueType& getAddr() { return value; }
	Node<T>* getPrevNode() { return prevNode; }
	Node<T>* getNextNode() { return nextNode; }

private:
	void setValue(ValueType value) { this->value = value; }
	void setPrevNode(const Node<T>* ptr) { prevNode = const_cast<Node<T>*>(ptr); }
	void setNextNode(const Node<T>* ptr) { nextNode = const_cast<Node<T>*>(ptr); }

private:
	Node<T>& operator=(const Node<T>& node)
	{
		memcpy(this, &node, sizeof(Node<T>));
		return *this;
	}
	bool operator==(const Node<T>& node) const { return value == node.value && nextNode == node.nextNode && prevNode == node.prevNode; }
	bool operator!=(const Node<T>& node) const { return !(value == node.value && nextNode == node.nextNode && prevNode == node.prevNode); }

private:
	friend class Iterator<T>;
	friend class ReverseIterator<T>;
	friend class Deque<T>;
};

#endif // !_NODE_H_