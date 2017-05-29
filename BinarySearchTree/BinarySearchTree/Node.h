#pragma once
class Node
{
	int		_value;
	Node*	_leftNode;
	Node*	_rightNode;

public:
	Node();
	Node(const Node& node);
	~Node();
	int _GetValue() const;
	Node* _GetLeftNode() const;
	Node* _GetRightNode() const;
	void _SetValue(int value);
	void _SetLeftNode(const Node* node);
	void _SetRightNode(const Node* node);

public:
	void operator=(const Node& node);
	bool operator==(const Node& node);
	bool operator!=(const Node& node);
};

