#pragma once

class Node
{
private:
	int _value;

public:
	Node();
	~Node();
	int _GetValue();
	int* _GetAddr();
	void _SetValue(int value);

public:
	void operator=(Node node);
	Node operator+(int value);
	Node operator-(int value);
	void operator+=(int value);
	void operator-=(int value);
	bool operator==(Node node);
	bool operator!=(Node node);
};


