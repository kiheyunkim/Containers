#pragma once
#include<iostream>
#include"Node.h"
class Iterator
{
private:
	Node *_target;

public:
	Node* _GetNode() { return _target; }

public:
	Iterator();
	Iterator(Node *node);
	~Iterator() {}

	Iterator operator++(int);
	Iterator operator+(int count);
	Iterator operator+=(int count);
	Iterator operator--();
	Iterator operator-(int count);
	Iterator operator-=(int count);
	int operator[](int index);
	void operator=(Iterator node);
	bool operator==(Iterator node);
	bool operator!=(Iterator node);
	int operator*();
	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		int value = iter._target->_GetValue();
		os << value;
		return os;
	}
	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		int value = iter._target->_GetValue();
		is >> value;
		return is;
	}

};

