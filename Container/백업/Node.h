#pragma once

class Node
{
private:
	int _value;
	Node *_nextNode;
	Node *_prevNode;

public:
	typedef int value_type;

public:
	Node();
	~Node();
	value_type _GetValue();
	value_type* _GetAddr();
	Node *_GetNextNode() const;
	Node *_GetPrevNode() const;
	void _SetValue(value_type value);
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


