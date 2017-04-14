#include "Iterator.h"

Iterator::Iterator() :_target(nullptr) {}
Iterator::Iterator(Node *node) : _target(node) {}

Iterator Iterator::operator++(int) 
{
	_target = _target->_GetNextNode();
	if(_target==nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 9);
	
	return *this;
}

void Iterator::operator++()
{
	_target = _target->_GetNextNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 18);
}

Iterator Iterator::operator--(int) 
{
	_target = _target->_GetPrevNode();
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 25);

	return *this;
}

Iterator Iterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
	{	
		if (_target != nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 35);
		_target = _target->_GetNextNode();
	}

	return _target;
}

Iterator Iterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 47);
		_target = _target->_GetPrevNode();
	}

	return *this;
}

void Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 59);
		_target = _target->_GetNextNode();
	}
}

void Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 69);
		_target = _target->_GetPrevNode();
	}
}

int Iterator::operator[](size_t index) const
{
	Node *cur = _target;
	for (size_t i = 0; i < index; i++)
	{
		if (cur == nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 80);
		cur = cur->_GetNextNode();
	}

	return cur->_GetValue();
}

void Iterator::operator=(Iterator iter) { _target = iter._GetNode(); }

bool Iterator::operator==(Iterator iter) const { return _target == iter._GetNode(); }

bool Iterator::operator!=(Iterator iter) const { return _target != iter._GetNode(); }

bool Iterator::operator<(Iterator iter) const { return _target->_GetValue() < iter._GetNode()->_GetValue(); }

bool Iterator::operator<=(Iterator iter) const { return _target->_GetValue() <= iter._GetNode()->_GetValue(); }

bool Iterator::operator>(Iterator iter) const { return _target->_GetValue() > iter._GetNode()->_GetValue(); }

bool Iterator::operator>=(Iterator iter) const { return _target->_GetValue() >= iter._GetNode()->_GetValue(); }

Iterator::value_type Iterator::operator*() const
{
	if (_target->_GetNextNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 104);

	return _target->_GetValue();
}

Iterator::value_type* Iterator::operator&() const
{
	if (_target->_GetNextNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 112);

	return _target->_GetAddr();
}

Node* Iterator::operator->() const
{
	if(_target==nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 120);

	return _target;
}