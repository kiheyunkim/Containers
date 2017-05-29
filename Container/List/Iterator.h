#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class Iterator
{
private:
	typedef int ValueType;

private:
	Node *_target;

public:
	Node* _GetNode();

public:
	Iterator();
	Iterator(const Node& node);
	~Iterator();

	Iterator& operator++(int);
	Iterator& operator--(int);
	Iterator& operator=(const Iterator& iter);
	bool operator==(const Iterator& iter) const;
	bool operator!=(const Iterator& iter) const;
	ValueType operator*() const;
	
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


