#include "Reverse_Iterator.h"

Reverse_Iterator::Reverse_Iterator() :_target(nullptr) {}
Reverse_Iterator::Reverse_Iterator(Node *node) { _target = node; }
Reverse_Iterator::~Reverse_Iterator() {}

Reverse_Iterator Reverse_Iterator::operator++(int)
{
	_target = _target->_GetPrevNode();
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 10);

	return *this;
}

void Reverse_Iterator::operator++()
{
	_target = _target->_GetPrevNode();
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 19);
}

Reverse_Iterator Reverse_Iterator::operator--(int) 
{
	_target = _target->_GetNextNode(); 
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 26);

	return *this;
}

void Reverse_Iterator::operator--()
{
	_target = _target->_GetNextNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 35);
}

void Reverse_Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
	{
		_target = _target->_GetPrevNode();
		if (_target->_GetPrevNode() == nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 44);
	}
}

void Reverse_Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
	{
		_target = _target->_GetNextNode();
		if (_target != nullptr)
			std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 54);
	}
}


void Reverse_Iterator::operator=(Reverse_Iterator iter) { _target = iter._GetNode(); }

bool Reverse_Iterator::operator==(Reverse_Iterator iter) const { return _target == iter._GetNode(); }

bool Reverse_Iterator::operator!=(Reverse_Iterator iter) const { return _target != iter._GetNode(); }

Reverse_Iterator::value_type Reverse_Iterator::operator*() const
{
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 68);

	return _target->_GetValue();
}

Reverse_Iterator::value_type* Reverse_Iterator::operator&() const 
{
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 76);
	
	return _target->_GetAddr(); 
}

