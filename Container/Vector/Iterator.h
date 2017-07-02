#pragma once
#include<iostream>
#include"Node.h"

template<typename T>
class Iterator
{
private:
	typedef Node<T>* NodePtr;
	typedef T ValueType;

private:
	NodePtr* _target;

private:
	Iterator& operator=(NodePtr const& node)
	{
		_target = const_cast<Iterator::NodePtr*>(&node);
		return *this;
	}

public:
	NodePtr  _GetNode() { return *_target; }
	NodePtr& _GetAddr() { return *_target; }

public:
	Iterator() :_target(nullptr) {}
	Iterator(const NodePtr& node) : _target(const_cast<Iterator::NodePtr*>(&node)) {}
	Iterator(const Iterator<T>& iter) { memcpy(this, &iter, sizeof(Iterator)); }
	~Iterator() {}

	Iterator<T>& operator++(int)
	{
		++_target;
		return *this;
	}

	Iterator<T>& operator+(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target++;

		return *this;
	}
	Iterator<T>& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target++;

		return *this;
	}
	Iterator<T>& operator--()
	{
		--_target;

		return *this;
	}
	Iterator<T>& operator-(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target--;

		return *this;
	}
	Iterator<T>& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target--;

		return *this;
	}
	ValueType& operator[](int index)
	{
		for (int i = 0; i < index; i++)
			_target++;

		return (*_target)->_GetAddr();
	}
	Iterator<T>& operator=(const Iterator& iter)
	{
		_target = iter._target;
		return *this;
	}
	bool operator<(const Iterator<T>& iter) const { return (*_target)->_GetValue() < (*_target)->_GetValue(); }
	bool operator<=(const Iterator<T>& iter) const { return (*_target)->_GetValue() <= (*_target)->_GetValue(); }
	bool operator>(const Iterator<T>& iter) const { return (*_target)->_GetValue() > (*_target)->_GetValue(); }
	bool operator>=(const Iterator<T>& iter)const { return (*_target)->_GetValue() >= (*_target)->_GetValue(); }
	bool operator==(const Iterator<T>& iter)const { return _target == iter._target; }
	bool operator!=(const Iterator<T>& iter)const { return _target != iter._target; }
	ValueType& operator*() { return (*_target)->_GetAddr(); }
	NodePtr operator->() { return *_target; }

	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		Iterator::ValueType value = (*(iter._target))->_GetValue();
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