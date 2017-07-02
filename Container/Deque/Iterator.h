#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"

template<typename T>
class Iterator
{
private:
	Node<T> *_target;

public:
	typedef T ValueType;

public:
	Node<T>* _GetNode() { return _target; }

public:
	Iterator() :_target(nullptr) {}
	Iterator(const Node<T>& node) : _target(const_cast<Node<T>*>(&node)) {}
	Iterator(const Iterator<T>& iterator) : _target(iterator._target) {}
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

	Iterator<T>& operator+(int count)
	{
		for (int i = 0; i < count; i++)
			_target = _target->_GetNextNode();
		return *this;
	}

	Iterator<T>& operator-(int count)
	{
		for (int i = 0; i < count; i++)
			_target = _target->_GetPrevNode();
		return *this;
	}

	Iterator<T>& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			_target = _target->_GetNextNode();
		return *this;
	}

	Iterator<T>& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			_target = _target->_GetPrevNode();
		return *this;
	}

	ValueType& operator[](size_t index)
	{
		Node *cur = _target;
		for (size_t i = 0; i < index; i++)
			cur = cur->_GetNextNode();

		return cur->_GetAddr();
	}

	Iterator<T>& operator=(const Iterator<T>& iter)
	{
		memcpy(this, &iter, sizeof(Iterator));
		return *this;
	}

	bool operator==(const Iterator<T>& iter) const { return _target == const_cast<Iterator&>(iter)._GetNode(); }
	bool operator!=(const Iterator<T>& iter) const { return _target != const_cast<Iterator&>(iter)._GetNode(); }
	bool operator<(const Iterator<T>& iter) const { return _target->_GetValue() < const_cast<Iterator&>(iter)._target->_GetValue(); }
	bool operator<=(const Iterator<T>& iter) const { return _target->_GetValue() <= const_cast<Iterator&>(iter)._target->_GetValue(); }
	bool operator>(const Iterator<T>& iter) const { return _target->_GetValue() > const_cast<Iterator&>(iter)._target->_GetValue(); }
	bool operator>=(const Iterator<T>& iter) const { return _target->_GetValue() >= const_cast<Iterator&>(iter)._target->_GetValue(); }
	ValueType& operator*() const { return _target->_GetAddr(); }

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
