#include "Iterator.h"
#include<tchar.h>
Iterator::Iterator() :_target(nullptr) {}
Iterator::Iterator(Node *node) : _target(node) {}

Iterator Iterator::operator++(int)
{
	_target = _target->_GetNextNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 9);
	return *this;
}

void Iterator::operator++()
{
	_target = _target->_GetNextNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 17);
}

Iterator Iterator::operator--(int)
{
	_target = _target->_GetPrevNode();
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 24);
	return *this;
}

void Iterator::operator--()
{
	_target = _target->_GetPrevNode();
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 32);
}

Iterator Iterator::operator+(int count)
{
	if (count >= 0)
	{
		for (int i = 0; i < count; i++)
		{
			_target = _target->_GetNextNode();
			if (_target == nullptr)
				std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 43);
		}
		return _target;
	}
	for (int i = count; i < 0; i++)
	{
		_target = _target->_GetPrevNode();
		if (_target == nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 51);
	}
	return _target;

}

Iterator Iterator::operator-(int count)
{
	if (count >= 0)
	{
		for (int i = 0; i < count; i++)
		{
			_target = _target->_GetPrevNode();
			if (_target == nullptr)
				std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 65);
		}
		return *this;
	}
	for (int i = count; i < 0; i++)
	{
		_target = _target->_GetPrevNode();
		if (_target == nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 73);
	}
	return *this;
}

void Iterator::operator+=(int count)
{
	if (count >= 0)
	{
		for (int i = 0; i < count; i++)
		{
			_target = _target->_GetNextNode();
			if (_target == nullptr)
				std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 86);
		}
	}
	for (int i = count; i < 0; i++)
	{
		_target = _target->_GetPrevNode();
		if (_target == nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 93);
	}
}

void Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target = _target->_GetPrevNode();
}

int Iterator::operator[](size_t index) const
{
	Node *cur = _target;
	for (size_t i = 0; i < index; i++)
		cur = cur->_GetNextNode();
	return cur->_GetValue();
}

void Iterator::operator=(Iterator iter) { _target = iter._GetNode(); }

bool Iterator::operator==(Iterator iter) const { return _target == iter._GetNode(); }

bool Iterator::operator!=(Iterator iter) const { return _target != iter._GetNode(); }

bool Iterator::operator<(Iterator iter) const { return _target->_GetValue() < iter._GetNode()->_GetValue(); }

bool Iterator::operator<=(Iterator iter) const { return _target->_GetValue() <= iter._GetNode()->_GetValue(); }

bool Iterator::operator>(Iterator iter) const { return _target->_GetValue() > iter._GetNode()->_GetValue(); }

bool Iterator::operator>=(Iterator iter) const { return _target->_GetValue() >= iter._GetNode()->_GetValue(); }

Iterator::value_type Iterator::operator*() const { return _target->_GetValue(); }

Iterator::value_type* Iterator::operator&() const { return _target->_GetAddr(); }