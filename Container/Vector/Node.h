#pragma once

class Node
{
private:
	int _value;
	Node *_nextNode;
	Node *_prevNode;

public:
	Node();
	~Node();
	int _GetValue();
	Node *_GetNextNode();
	Node *_GetPrevNode();
	void _SetValue(int value);
	void _SetPrevNode(Node *ptr);
	void _SetNextNode(Node *ptr);

public:
	void operator=(Node node);
	Node operator+(int value);
	Node operator-(int value);
	void operator+=(int value);
	void operator-=(int value);
	bool operator==(Node node);
	bool operator!=(Node node);
};


