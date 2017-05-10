#include "Node.h"

Node::Node() :_value(0), _leftNode(nullptr), _rightNode(nullptr) {}

Node::Node(Node& node)
{
	_value = node._value;
	_leftNode = node._leftNode;
	_rightNode = node._rightNode;
}

Node::~Node() {}

int Node::_GetValue() { return _value; }

int* Node::_GetAddr() { return &_value; }

Node* Node::_GetLeftNode() { return _leftNode; }

Node* Node::_GetRightNode() { return _rightNode; }

void Node::_SetValue(int value) { _value = value; }

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