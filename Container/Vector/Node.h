#pragma once

class Node
{
private:
	int _value;
	bool _isEdge;

public:
	Node();
	Node(bool status);
	~Node();
	int _GetValue();
	int& _GetAddr();
	void _SetValue(int value);
	bool _GetEdge();
	void _SetEdge(bool status);

public:
	void operator=(Node node);
	Node operator+(int value);
	Node operator-(int value);
	void operator+=(int value);
	void operator-=(int value);
	bool operator==(Node node);
	bool operator!=(Node node);
};


