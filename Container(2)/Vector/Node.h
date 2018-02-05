#ifndef _NODE_H_
#define _NODE_H_

template<class T>
class Iterator;

template<class T>
class ReverseIterator;

template<class T>
class Vector;

template<typename T>
class Node
{
private:
	typedef T ValueType;

private:
	ValueType value;
	bool isEdge;

private:
	Node() :isEdge(false) {}
	Node(bool status) : isEdge(status) {}
	Node(const Node<T>& node) { memcpy(this, &node, sizeof(Node)); }
	~Node() {}

private:
	ValueType getValue() const { return value; }
	ValueType& getAddr() { return value; }
	void setValue(ValueType value) { this->value = value; }
	bool getEdge() const { return isEdge; }
	void setEdge(bool status) { isEdge = status; }

public:
	Node<T>& operator=(const Node<T>& node)
	{
		this->value = node._value;
		return *this;
	}
	Node<T>& operator+(int value)
	{
		this->value += value;
		return *this;
	}
	Node<T>& operator-(int value)
	{
		this->value += value;
		return *this;
	}
	Node<T>& operator+=(int value)
	{
		this->value += value;
		return *this;
	}
	Node<T>& operator-=(int value)
	{
		this->value -= value;
		return *this;
	}
	bool operator==(const Node<T>& node) { return value == node.value; }
	bool operator!=(const Node<T>& node) { return !(value == node.value); }
	
	friend class Iterator<T>;
	friend class ReverseIterator<T>;
	friend class Vector<T>;
};

#endif // !_NODE_H_