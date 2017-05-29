#include "Node.h"

Node::Node() :_value(0), _prevNode(nullptr), _nextNode(nullptr) {}
Node::Node(const Node& node) { memcpy(this, &node, sizeof(Node)); }
Node::~Node(){}

Node::value_type Node::_GetValue() const { return _value; }
Node::value_type& Node::_GetAddr() { return this->_value; }
Node* Node::_GetPrevNode() { return _prevNode; }
Node* Node::_GetNextNode() { return _nextNode; }

void Node::_SetValue(Node::value_type value) { _value = value; }
void Node::_SetPrevNode(const Node *ptr) { _prevNode = const_cast<Node*>(ptr); }
void Node::_SetNextNode(const Node *ptr) { _nextNode = const_cast<Node*>(ptr); }

Node& Node::operator=(const Node& node) 
{
	memcpy(this, &node, sizeof(Node)); 
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
	_value += _value; 
	return *this; 
}

Node& Node::operator-=(int value)
{
	_value -= _value;
	return *this;
}

bool Node::operator==(const Node& node) const { return _value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode; }

bool Node::operator!=(const Node& node) const { return !(_value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode); }