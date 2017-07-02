#pragma once
#pragma once
#include<iostream>
#include"Node.h"
template<typename T>
class ReverseIterator
{
private:
	Node<T> *_target;

public:
	typedef T ValueType;

public:
	Node<T>* _GetNode() { return _target; }
public:
	ReverseIterator() :_target(nullptr) {}
	ReverseIterator(const Node<T>& node) { _target = const_cast<Node<T>*>(&node); }
	ReverseIterator(const ReverseIterator<T>&  reverseIterator) : _target(reverseIterator._target) {}
	~ReverseIterator() {}

	ReverseIterator<T>& operator++()
	{
		_target = _target->_GetPrevNode();
		return *this;
	}

	ReverseIterator<T>& operator--()
	{
		_target = _target->_GetNextNode();
		return *this;
	}

	ReverseIterator<T>& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			_target = _target->_GetPrevNode();
		return *this;
	}

	ReverseIterator<T>& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			_target = _target->_GetNextNode();
		return *this;
	}

	void operator=(ReverseIterator<T> iter) { _target = iter._GetNode(); }
	bool operator==(ReverseIterator<T> iter) const { return _target == iter._GetNode(); }
	bool operator!=(ReverseIterator<T> iter) const { return _target != iter._GetNode(); }
	ValueType& operator*() const { return _target->_GetAddr(); }

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter._target->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value;
		is >> value;
		iter._target->_SetValue(value);
		return is;
	}
};