#pragma once
#include<iostream>
#include"Node.h"
class Iterator
{
private:
	Node** _target;

private:
	Iterator& operator=(Node* const& node);

public:
	Node* _GetNode();
	Node*&	_GetAddr();
public:
	Iterator();
	Iterator(Node* const& node);
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
	Node* operator->();

	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		int value = (*(iter._target))->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		int value = (*(iter._target))->_GetValue();
		is >> value;
		return is;
	}
};

