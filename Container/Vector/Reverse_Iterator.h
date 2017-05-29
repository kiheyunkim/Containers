#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class Reverse_Iterator
{
private:
	typedef Node* NodePtr;

private:
	NodePtr* _target;

private:
	Reverse_Iterator& operator=(const NodePtr& node);

public:
	typedef int value_type;

public:
	NodePtr _GetNode();
	NodePtr& _GetAddr();
public:
	Reverse_Iterator();
	Reverse_Iterator(const NodePtr& node);
	Reverse_Iterator(const Reverse_Iterator& iter);
	~Reverse_Iterator();

	Reverse_Iterator& operator++(int);
	Reverse_Iterator& operator+(int count);
	Reverse_Iterator& operator+=(int count);
	Reverse_Iterator& operator--(int);
	Reverse_Iterator& operator-(int count);
	Reverse_Iterator& operator-=(int count);
	int& operator[](int index);
	Reverse_Iterator& operator=(const Reverse_Iterator& iter);
	bool operator<(const Reverse_Iterator& iter)const;
	bool operator<=(const Reverse_Iterator& iter)const;
	bool operator>(const Reverse_Iterator& iter)const;
	bool operator>=(const Reverse_Iterator& iter)const;
	bool operator==(const Reverse_Iterator& iter) const;
	bool operator!=(const Reverse_Iterator& iter) const;
	int& operator*() const;
	NodePtr operator->();

	friend std::ostream& operator<<(std::ostream& os, const Reverse_Iterator& iter)
	{
		Reverse_Iterator::value_type value = (*iter._target)->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Reverse_Iterator& iter)
	{
		Reverse_Iterator::value_type value = (*iter._target)->_GetValue();
		is >> value;
		return is;
	}
};
