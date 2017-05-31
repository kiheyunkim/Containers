#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"

template<class T>
class List;

template<class T>
class ReverseIterator
{
private:
	typedef T ValueType;

private:
	Node<T>* _target;

private:
	Node<T>* _GetNode() { return _target; }

private:
	ReverseIterator(const Node<T>& node) :_target(const_cast<Node<T>*>(&node)) {}

public:
	ReverseIterator() :_target(nullptr) {}
	ReverseIterator(const Iterator<T>& iter) { memcpy(this, &iter, sizeof(Iterator<T>)); }
	~ReverseIterator() {}

	ReverseIterator& operator++(int)
	{
		_target = _target->_GetPrevNode();
		return *this;
	}
	ReverseIterator& operator--(int)
	{
		_target = _target->_GetNextNode();
		return *this;
	}
	ReverseIterator& operator=(const ReverseIterator& iter)
	{
		memcpy(_target, iter._target, sizeof(_target));
		return *this;
	}
	bool operator==(const ReverseIterator& iter) const { return _target == iter._target; }
	bool operator!=(const ReverseIterator& iter) const { return _target != iter._target; }
	ValueType operator*() const { return _target->_GetValue(); }

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter._target->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter._target->_GetValue();
		is >> value;
		return is;
	}
};