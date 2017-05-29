#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class ReverseIterator
{
private:
	typedef int ValueType;

private:
	Node *_target;

public:
	Node* _GetNode();

public:
	ReverseIterator();
	ReverseIterator(const Node& node);
	~ReverseIterator();

	ReverseIterator& operator++(int);
	ReverseIterator& operator--(int);
	ReverseIterator& operator=(const ReverseIterator& iter);
	bool operator==(const ReverseIterator& iter) const;
	bool operator!=(const ReverseIterator& iter) const;
	ValueType operator*() const;

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter._target->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter._target->_GetValue();
		is >> value;
		return is;
	}
};
