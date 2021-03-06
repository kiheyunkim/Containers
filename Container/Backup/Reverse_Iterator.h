#pragma once
#include<iostream>
#include"Node.h"
class Reverse_Iterator
{
private:
	Node *_target;
public:
	typedef int value_type;
public:
	Node* _GetNode() { return _target; }
public:
	Reverse_Iterator();
	Reverse_Iterator(Node *node);
	~Reverse_Iterator();
	Reverse_Iterator operator++(int);
	Reverse_Iterator operator--(int);
	Reverse_Iterator operator+(int count);
	Reverse_Iterator operator-(int count);
	void operator+=(int count);
	void operator-=(int count);
	value_type operator[](size_t index) const;
	void operator=(Reverse_Iterator iter);
	bool operator==(Reverse_Iterator iter) const;
	bool operator!=(Reverse_Iterator iter) const;
	bool operator<(Reverse_Iterator iter) const;
	bool operator<=(Reverse_Iterator iter) const;
	bool operator>(Reverse_Iterator iter) const;
	bool operator>=(Reverse_Iterator iter) const;
	value_type operator*() const;
	value_type* operator&() const;
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
