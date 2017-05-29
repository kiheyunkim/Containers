#pragma once
#include<iostream>
#include"Node.h"
class Iterator
{
private:
	typedef Node* NodePtr;

private:
	NodePtr* _target;

private:
	Iterator& operator=(NodePtr const& node);

public:
	NodePtr  _GetNode();
	NodePtr& _GetAddr();
public:
	Iterator();
	Iterator(NodePtr const& node);
	Iterator(const Iterator& iter);
	~Iterator();

	Iterator& operator++(int); 
	Iterator& operator+(int count);
	Iterator& operator+=(int count);
	Iterator& operator--();
	Iterator& operator-(int count);
	Iterator& operator-=(int count);
	int& operator[](int index);
	Iterator& operator=(const Iterator& iter);
	bool operator<(const Iterator& iter) const;
	bool operator<=(const Iterator& iter) const;
	bool operator>(const Iterator& iter) const;
	bool operator>=(const Iterator& iter)const;
	bool operator==(const Iterator& iter)const;
	bool operator!=(const Iterator& iter)const;
	int& operator*();
	Iterator::NodePtr operator->();

	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		int value = (*(iter._target))->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		int value;
		is >> value;
		(*(iter._target))->_SetValue(value);
		return is;
	}
};

