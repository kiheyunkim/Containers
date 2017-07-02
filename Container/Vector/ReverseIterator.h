#pragma once
#include<iostream>
#include<tchar.h>
#include"Node.h"
template<typename T>
class ReverseIterator
{
private:
	typedef Node<T>* NodePtr;
	typedef T ValueType;

private:
	NodePtr* _target;

private:
	ReverseIterator& operator=(const NodePtr& node);

public:
	NodePtr _GetNode() { return *_target; }
	NodePtr& _GetAddr() { return *_target; }
public:
	ReverseIterator() :_target(nullptr) {}
	ReverseIterator(const NodePtr& node) { *_target = const_cast<ReverseIterator::NodePtr&>(node); }
	ReverseIterator(const ReverseIterator& iter);
	~ReverseIterator() {}

	ReverseIterator& operator++(int)
	{
		_target--;
		return *this;
	}
	
	ReverseIterator& operator+(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target--;

		return *this;
	}

	ReverseIterator& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target--;

		return *this;
	}

	ReverseIterator& operator--(int)
	{
		_target++;
		return *this;
	}

	ReverseIterator& operator-(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target++;

		return *this;
	}

	ReverseIterator& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			if (_target != nullptr)
				_target++;

		return *this;
	}

	ValueType& operator[](int index)
	{
		for (int i = 0; i < index; i++)
			_target--;

		return (*_target)->_GetAddr();
	}
	
	ReverseIterator& operator=(const ReverseIterator& iter)
	{
		_target = iter._target;
		return *this;
	}

	bool operator<(const ReverseIterator& iter)const { return (*_target)->_GetValue() < (*_target)->_GetValue(); }
	bool operator<=(const ReverseIterator& iter)const { return (*_target)->_GetValue() <= (*_target)->_GetValue(); }
	bool operator>(const ReverseIterator& iter)const { return (*_target)->_GetValue() > (*_target)->_GetValue(); }
	bool operator>=(const ReverseIterator& iter)const { return (*_target)->_GetValue() >= (*_target)->_GetValue(); }
	bool operator==(const ReverseIterator& iter) const { return _target == iter._target; }
	bool operator!=(const ReverseIterator& iter) const { return _target != iter._target; }
	ValueType& operator*() const { return (*_target)->_GetAddr(); }
	NodePtr operator->() { return *_target; }

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = (*iter._target)->_GetValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value;
		is >> value;
		(*iter._target)->_SetValue(value);
		return is;
	}
};
