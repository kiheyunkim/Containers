#pragma once
#include<memory>
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
	Node(const Node& node);
	~Node();
	value_type _GetValue() const;
	value_type& _GetAddr();
	Node* _GetNextNode() const;
	Node* _GetPrevNode() const;
	void _SetValue(value_type value);
	void _SetPrevNode(const Node *ptr);
	void _SetNextNode(const Node *ptr);

public:
	Node& operator=(const Node& node);
	Node& operator+(int value);
	Node& operator-(int value);
	Node& operator+=(int value);
	Node& operator-=(int value);
	bool operator==(const Node& node)const;
	bool operator!=(const Node& node)const;
};


