#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
class Iterator
{
private:
	Node *_target;

public:
	typedef int valueType;
	typedef valueType& reference;
	
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
	valueType operator*() const;
	
	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		Iterator::valueType value = iter._target->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		Iterator::valueType value = iter._target->_GetValue();
		is >> value;
		return is;
	}

};


