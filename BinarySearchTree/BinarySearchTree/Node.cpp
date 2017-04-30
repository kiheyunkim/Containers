#include "Node.h"




Node::Node() :_leftNode(nullptr), _rightNode(nullptr) {}

Node::~Node() {}

int Node::_GetValue() const { return _value; }

Node* Node::_GetLeftNode() const { return _leftNode; }

Node* Node::_GetRightNode() const { return _rightNode; }

void Node::_SetValue(const int value) { _value = value; }

void Node::_SetLeftNode(Node* node) { _leftNode = node; }

void Node::_SetRightNode(Node* node) { _rightNode = node; }

void Node::operator=(Node node)
{
	_value = node._value;
	_leftNode = node._leftNode;
	_rightNode = node._rightNode;
}

bool Node::operator==(Node node) { return _value == node._value&&_leftNode == node._leftNode&&_rightNode == node._rightNode; }

bool Node::operator!=(Node node) { return _value != node._value&&_leftNode != node._leftNode&&_rightNode != node._rightNode; }