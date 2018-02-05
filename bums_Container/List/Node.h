#ifndef _NODE_H_
#define _NODE_H_
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
	ValueType value;
	Node<T>* nextNode;
	Node<T>* prevNode;

private:
	Node() :prevNode(nullptr), nextNode(nullptr) {}
	Node(const Node<T>& node) :prevNode(nullptr), nextNode(nullptr) { memcpy(this, &node, sizeof(Node<T>)); }
	~Node() {}

	ValueType getValue() const { return value; }
	ValueType& getAddr() { return value; }
	Node<T>* getNextNode() { return nextNode; }
	Node<T>* getPrevNode() { return prevNode; }
	void setValue(ValueType value) { this->value = value; }
	void setPrevNode(const Node<T>* ptr) { prevNode = const_cast<Node<T>*>(ptr); }
	void setNextNode(const Node<T>* ptr) { nextNode = const_cast<Node<T>*>(ptr); }

private:
	Node& operator=(const Node<T>& node)
	{
		memcpy(this, &node, sizeof(Node<T>));
		return *this;
	}
	bool operator==(const Node<T>& node) const { return this->value == node.value && nextNode == node.nextNode && prevNode == node.prevNode; }
	bool operator!=(const Node<T>& node) const { return !(this->value == node.value && nextNode == node.nextNode && prevNode == node.prevNode); }

	friend class Iterator<T>;
	friend class ReverseIterator<T>;
	friend class List<T>;
};

#endif //_NODE_H_