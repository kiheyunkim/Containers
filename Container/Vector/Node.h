#pragma once

class Node
{
private:
	typedef int ValueType;

private:
	ValueType _value;
	bool _isEdge;

public:
	Node();
	Node(bool status);
	Node(const Node& node);
	~Node();
	ValueType _GetValue() const;
	ValueType& _GetAddr();
	void _SetValue(ValueType value);
	bool _GetEdge() const;
	void _SetEdge(bool status);

public:
	Node& operator=(const Node& node);
	Node& operator+(int value);
	Node& operator-(int value);
	Node& operator+=(int value);
	Node& operator-=(int value);
	bool operator==(const Node& node);
	bool operator!=(const Node& node);
};


