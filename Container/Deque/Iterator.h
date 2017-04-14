#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class Iterator
{
private:
	Node *_target;
public:
	typedef int value_type;
public:
	Node* _GetNode() { return _target; }
public:
	Iterator();
	Iterator(Node *node);
	~Iterator() {}

	Iterator operator++(int);
	void operator++();
	Iterator operator--(int);
	void operator--();
	Iterator operator+(int count);
	Iterator operator-(int count);
	void operator+=(int count);
	void operator-=(int count);
	value_type operator[](size_t index) const;
	void operator=(Iterator iter);
	bool operator==(Iterator iter) const;
	bool operator!=(Iterator iter) const;
	bool operator<(Iterator iter) const;
	bool operator<=(Iterator iter) const;
	bool operator>(Iterator iter) const;
	bool operator>=(Iterator iter) const;
	value_type operator*() const;
	value_type* operator&() const;
	Node* operator->() const;
	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		Iterator::value_type value = iter._target->_GetValue();
		os << value;
		return os;
	}
	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		Iterator::value_type value = iter._target->_GetValue();
		is >> value;
		return is;
	}

};


