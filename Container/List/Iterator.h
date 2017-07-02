#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"

template<class T>
class List;

template<class T>
class Iterator
{
private:
	typedef T ValueType;

private:
	Node<T>* _target;

private:
	Node<T>* _GetNode() { return _target; }

private:
	Iterator(const Node<T>& node) :_target(const_cast<Node<T>*>(&node)) {}

public:
	Iterator() :_target(nullptr) {}
	Iterator(const Iterator<T>& iter) { memcpy(this, &iter, sizeof(Iterator<T>)); }
	~Iterator() {}

	Iterator<T>& operator++(int)
	{
		_target = _target->_GetNextNode();
		return *this;
	}
	Iterator<T>& operator--(int)
	{
		_target = _target->_GetPrevNode();
		return *this;
	}
	Iterator<T>& operator=(const Iterator<T>& iter)
	{
		memcpy(_target, iter._target, sizeof(Iterator));
		return *this;
	}
	bool operator==(const Iterator<T>& iter) const { return _target == const_cast<Iterator&>(iter)._GetNode(); }
	bool operator!=(const Iterator<T>& iter) const { return _target != const_cast<Iterator&>(iter)._GetNode(); }
	ValueType operator*() const { return _target->_GetValue(); }
	
	friend std::ostream& operator<<(std::ostream& os, const Iterator<T>& iter)
	{
		Iterator<T>::ValueType value = iter._target->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator<T>& iter)
	{
		Iterator<T>::ValueType value;
		is >> value;
		iter._target->_SetValue(value);
		return is;
	}

	friend class List<T>;
};
