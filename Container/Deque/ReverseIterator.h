#pragma once
#pragma once
#include<iostream>
#include"Node.h"
class ReverseIterator
{
private:
	Node *_target;

public:
	typedef int ValueType;

public:
	Node* _GetNode() { return _target; }
public:
	ReverseIterator();
	ReverseIterator(const Node& node);
	ReverseIterator(const ReverseIterator& iterator);
	~ReverseIterator();

	ReverseIterator& operator++();
	ReverseIterator& operator--();
	ReverseIterator& operator+=(int count);
	ReverseIterator& operator-=(int count);
	void operator=(ReverseIterator iter);
	bool operator==(ReverseIterator iter) const;
	bool operator!=(ReverseIterator iter) const;
	ValueType& operator*() const;

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter._target->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value;
		is >> value;
		iter._target->_SetValue(value);
		return is;
	}
};
