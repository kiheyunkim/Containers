#include<memory>
#include "Node.h"

Node::Node() :_leftNode(nullptr), _rightNode(nullptr) {}
Node::Node(const Node& node) { memcpy(this, &node, sizeof(Node)); }
Node::~Node() {}

int Node::_GetValue() const { return _value; }
Node* Node::_GetLeftNode() const { return _leftNode; }
Node* Node::_GetRightNode() const { return _rightNode; }

void Node::_SetValue(int value) { _value = value; }
void Node::_SetLeftNode(const Node* node) { _leftNode = const_cast<Node*>(node); }
void Node::_SetRightNode(const Node* node) { _rightNode = const_cast<Node*>(node); }

void Node::operator=(const Node& node) { memcpy(this, &node, sizeof(Node)); }
bool Node::operator==(const Node& node) { return _value == node._value&&_leftNode == node._leftNode&&_rightNode == node._rightNode; }
bool Node::operator!=(const Node& node) { return _value != node._value&&_leftNode != node._leftNode&&_rightNode != node._rightNode; }