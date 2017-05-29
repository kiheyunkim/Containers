#pragma once

class Node
{
private:
	int _value;
	bool _isEdge;

public:
	Node();
	Node(bool status);
	Node(const Node& node);
	~Node();
	int _GetValue() const;
	int& _GetAddr();
	void _SetValue(int value);
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


