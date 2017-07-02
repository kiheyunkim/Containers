#pragma once

template<typename T>
class Node
{
private:
	typedef T ValueType;

private:
	ValueType _value;
	bool _isEdge;

public:
	Node() :_isEdge(false) {}
	Node(bool status) : _isEdge(status) {}
	Node(const Node<T>& node) { memcpy(this, &node, sizeof(Node)); }
	~Node() {}
	ValueType _GetValue() const { return _value; }
	ValueType& _GetAddr() { return _value; }
	void _SetValue(ValueType value) { _value = value; }
	bool _GetEdge() const { return _isEdge; }
	void _SetEdge(bool status) { _isEdge = status; }

public:
	Node<T>& operator=(const Node<T>& node)
	{
		_value = node._value;
		return *this;
	}
	Node<T>& operator+(int value)
	{
		this->_value += value;
		return *this;
	}
	Node<T>& operator-(int value)
	{
		this->_value += value;
		return *this;
	}
	Node<T>& operator+=(int value)
	{
		this->_value += value;
		return *this;
	}

	Node<T>& operator-=(int value)
	{
		this->_value -= value;
		return *this;
	}
	bool operator==(const Node<T>& node) { return _value == node._value; }

	bool operator!=(const Node<T>& node) { return !(_value == node._value); }
};


