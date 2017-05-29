#pragma once

class Node
{
private:
	typedef int ValueType;

private:
	ValueType _value;
	Node* _nextNode;
	Node* _prevNode;

public:
	Node();
	Node(const Node& node);
	~Node();
	ValueType _GetValue() const;
	ValueType& _GetAddr();
	Node* _GetNextNode() const;
	Node* _GetPrevNode() const;
	void _SetValue(ValueType value);
	void _SetPrevNode(const Node* ptr);
	void _SetNextNode(const Node* ptr);

public:
	Node& operator=(const Node& node);
	Node& operator+(int value);
	Node& operator-(int value);
	Node& operator+=(int value);
	Node& operator-=(int value);
	bool operator==(const Node& node);
	bool operator!=(const Node& node);
};


