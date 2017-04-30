#pragma once
class Node
{
	int _value;
	Node* _leftNode;
	Node* _rightNode;

public:
	Node();
	~Node();
	int _GetValue() const;
	Node* _GetLeftNode() const;
	Node* _GetRightNode() const;
	void _SetValue(const int value);
	void _SetLeftNode(Node* node);
	void _SetRightNode(Node* node);

public:
	void operator=(const Node node);
	bool operator==(const Node node);
	bool operator!=(const Node node);
};

