#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class ReverseIterator
{
private:
	typedef Node* NodePtr;
	typedef int ValueType;

private:
	NodePtr* _target;

private:
	ReverseIterator& operator=(const NodePtr& node);

public:
	NodePtr _GetNode();
	NodePtr& _GetAddr();
public:
	ReverseIterator();
	ReverseIterator(const NodePtr& node);
	ReverseIterator(const ReverseIterator& iter);
	~ReverseIterator();

	ReverseIterator& operator++(int);
	ReverseIterator& operator+(int count);
	ReverseIterator& operator+=(int count);
	ReverseIterator& operator--(int);
	ReverseIterator& operator-(int count);
	ReverseIterator& operator-=(int count);
	ValueType& operator[](int index);
	ReverseIterator& operator=(const ReverseIterator& iter);
	bool operator<(const ReverseIterator& iter)const;
	bool operator<=(const ReverseIterator& iter)const;
	bool operator>(const ReverseIterator& iter)const;
	bool operator>=(const ReverseIterator& iter)const;
	bool operator==(const ReverseIterator& iter) const;
	bool operator!=(const ReverseIterator& iter) const;
	ValueType& operator*() const;
	NodePtr operator->();

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = (*iter._target)->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value;
		is >> value;
		(*iter._target)->_SetValue(value);
		return is;
	}
};
