#include<memory>
#include "Node.h"

Node::Node() :_isEdge(false) {}
Node::Node(bool status) : _isEdge(status) {}
Node::Node(const Node& node) { memcpy(this, &node, sizeof(Node)); }
Node::~Node() {}

Node::ValueType Node::_GetValue() const { return _value; }
Node::ValueType& Node::_GetAddr() { return _value; }
void Node::_SetValue(int value) { _value = value; }
bool Node::_GetEdge() const { return _isEdge; }
void Node::_SetEdge(bool status) { _isEdge = status; }

Node& Node::operator=(const Node& node)
{
	_value = node._value; 
	return *this;
}

Node& Node::operator+(int value) 
{
	this->_value += value;
	return *this;
}

Node& Node::operator-(int value) 
{  
	this->_value += value;
	return *this;
}

Node& Node::operator+=(int value) 
{
	this->_value += value;
	return *this;
}

Node& Node::operator-=(int value) 
{
	this->_value -= value; 
	return *this;
}

bool Node::operator==(const Node& node) { return _value == node._value; }

bool Node::operator!=(const Node& node) { return !(_value == node._value); }