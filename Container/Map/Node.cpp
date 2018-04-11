#include "Node.h"

Node::Node() :value(0), rightChild(nullptr), leftChild(nullptr) {}
Node::~Node(){}

Node::value_type Node::GetValue() const { return value; }
Node::value_type* Node::GetAddr() { return &value; }
Node *Node::GetLeftChildNode() const { return leftChild; }
Node *Node::GetRightChildNode() const { return rightChild; }

void Node::SetValue(Node::value_type value) { value = value; }
void Node::SetLeftChildNode(const Node* ptr) { leftChild = const_cast<Node*>(ptr); }
void Node::SetRightChildNode(const Node* ptr) { rightChild = const_cast<Node*>(ptr); }

Node& Node::operator=(const Node& node)
{
	memcpy(this, &node, sizeof(Node));
}

Node& Node::operator+(int value) 
{
	this->value += value;
	return *this;
}

Node& Node::operator-(int value) 
{  
	this->value += value;
	return *this;
}

void Node::operator+=(int value) { this->value += value; }

void Node::operator-=(int value) { this->value -= value; }

bool Node::operator==(const Node& node) { return value == node.value&&rightChild == node.rightChild&&leftChild == node.leftChild; }

bool Node::operator!=(const Node& node) { return !(value == node.value&&rightChild == node.rightChild&&leftChild == node.leftChild); }