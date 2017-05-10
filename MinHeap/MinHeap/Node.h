#pragma once
class Node
{
	int		_value;
	Node*	_leftNode;
	Node*	_rightNode;

public:
	Node();
	Node(Node& node);
	~Node();
	int		_GetValue();
	int*	_GetAddr();
	Node*	_GetLeftNode();
	Node*	_GetRightNode();
	void	_SetValue(int value);
	void	_SetLeftNode(Node* node);
	void	_SetRightNode(Node* node);

public:
	void	operator=(Node node);
	bool	operator==(Node node);
	bool	operator!=(Node node);
};

