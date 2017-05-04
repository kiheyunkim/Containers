#include "Reverse_Iterator.h"

Reverse_Iterator::Reverse_Iterator() :_target(nullptr) {}
Reverse_Iterator::Reverse_Iterator(Node *node) { _target = node; }
Reverse_Iterator::~Reverse_Iterator() {}

Node* Reverse_Iterator::_GetNode() { return _target; }

Reverse_Iterator Reverse_Iterator::operator++(int) 
{
	_target = _target->_GetPrevNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Reverse_Iterator.cpp"), 12);

	return *this;
}

void Reverse_Iterator::operator++()
{
	_target = _target->_GetPrevNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Reverse_Iterator.cpp"), 21);
}

Reverse_Iterator Reverse_Iterator::operator--(int) 
{
	_target = _target->_GetNextNode(); 
	if (_target->_GetNextNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Reverse_Iterator.cpp"), 28);

	return *this;
}

void Reverse_Iterator::operator--()
{
	_target = _target->_GetNextNode();
	if (_target->_GetNextNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Reverse_Iterator.cpp"), 37);
}

void Reverse_Iterator::operator=(Reverse_Iterator iter) { _target = iter._GetNode(); }

bool Reverse_Iterator::operator==(Reverse_Iterator iter) const { return _target == iter._GetNode(); }

bool Reverse_Iterator::operator!=(Reverse_Iterator iter) const { return _target != iter._GetNode(); }

Reverse_Iterator::value_type Reverse_Iterator::operator*() const 
{
	if(_target->_GetPrevNode()==nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Reverse_Iterator.cpp"), 49);
	return _target->_GetValue(); 
}

Reverse_Iterator::value_type* Reverse_Iterator::operator&() const 
{
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Pit pf Range"), _T("Reverse_Iterator.cpp"), 57);
	return _target->_GetAddr(); 
}

Node* Reverse_Iterator::operator->() const { return _target; }