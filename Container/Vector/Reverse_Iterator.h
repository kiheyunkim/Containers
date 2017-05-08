#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class Reverse_Iterator
{
private:
	Node *_target;

public:
	typedef int value_type;

public:
	Node* _GetNode();

public:
	Reverse_Iterator();
	Reverse_Iterator(Node *node);
	~Reverse_Iterator();

	Reverse_Iterator operator++(int);
	void operator++();
	Reverse_Iterator operator--(int);
	void operator--();
	void operator=(Reverse_Iterator iter);
	bool operator==(Reverse_Iterator iter) const;
	bool operator!=(Reverse_Iterator iter) const;
	value_type operator*() const;
	value_type& operator&() const;

	friend std::ostream& operator<<(std::ostream& os, const Reverse_Iterator& iter)
	{
		Reverse_Iterator::value_type value = iter._target->_GetValue();
		os << value;
		return os;
	}
	friend std::istream& operator >> (std::istream& is, const Reverse_Iterator& iter)
	{
		Reverse_Iterator::value_type value = iter._target->_GetValue();
		is >> value;
		return is;
	}
};
