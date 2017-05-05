#include "Node.h"

Node::Node() {}
Node::~Node() {}

int Node::_GetValue() { return _value; }

int* Node::_GetAddr() { return &_value; }

void Node::_SetValue(int value) { _value = value; }

void Node::operator=(Node node) { _value = node._value; }

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

bool Node::operator==(Node node) { return _value == node._value; }

bool Node::operator!=(Node node) { return !(_value == node._value); }