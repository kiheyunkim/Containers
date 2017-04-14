#include "Node.h"

Node::Node() :_value(0), _prevNode(nullptr), _nextNode(nullptr) {}
Node::~Node(){}

int Node::_GetValue() { return _value; }
Node *Node::_GetPrevNode() { return _prevNode; }
Node *Node::_GetNextNode() { return _nextNode; }

void Node::_SetValue(int value) { _value = value; }
void Node::_SetPrevNode(Node *ptr) { _prevNode = ptr; }
void Node::_SetNextNode(Node *ptr) { _nextNode = ptr; }

void Node::operator=(Node node)
{
	_value = node._value;
	_nextNode = node._nextNode;
	_nextNode = node._prevNode;
}

Node Node::operator+(int value) 
{
	this->_value += value;
	return *this;
}

Node Node::operator-(int value) 
{  
	this->_value += value;
	return *this;
}

void Node::operator+=(int value) { _value += _value; }

void Node::operator-=(int value) { _value -= _value; }

bool Node::operator==(Node node) { return _value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode; }

bool Node::operator!=(Node node) { return !(_value == node._value&&_nextNode == node._nextNode&&_prevNode == node._prevNode); }