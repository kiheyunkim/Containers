#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class Iterator
{
private:
	Node *_target;

public:
	typedef int ValueType;

public:
	Node* _GetNode() { return _target; }

public:
	Iterator();
	Iterator(const Node& node);
	Iterator(const Iterator& iterator);
	~Iterator();

	Iterator& operator++(int);
	Iterator& operator--(int);
	Iterator& operator+(int count);
	Iterator& operator-(int count);
	Iterator& operator+=(int count);
	Iterator& operator-=(int count);
	ValueType& operator[](size_t index);

	Iterator& operator=(const Iterator& iter);
	bool operator==(const Iterator& iter) const;
	bool operator!=(const Iterator& iter) const;
	bool operator<(const Iterator& iter) const;
	bool operator<=(const Iterator& iter) const;
	bool operator>(const Iterator& iter) const;
	bool operator>=(const Iterator& iter) const;
	ValueType& operator*() const;
	
	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		Iterator::ValueType value = iter._target->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		Iterator::ValueType value;
		is >> value;
		iter._target->_SetValue(value);
		return is;
	}

};


