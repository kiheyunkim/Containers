#include "Iterator.h"

Iterator::Iterator() :_target(nullptr) {}
Iterator::Iterator(Node *node) : _target(node) {}
Iterator::~Iterator() {}

Node* Iterator::_GetNode() { return _target; }

Iterator Iterator::operator++(int)
{
	_target = _target->_GetNextNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 12);
	return *this;
}

Iterator Iterator::operator++()
{
	_target = _target->_GetNextNode();
	if (_target == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 20);

	return *this;
}

Iterator Iterator::operator--(int)
{
	_target = _target->_GetPrevNode();
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 27);
	
	return *this;
}

Iterator Iterator::operator--()
{
	_target = _target->_GetPrevNode();
	if (_target->_GetPrevNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 35);

	return *this;
}

void Iterator::operator=(Iterator iter) { _target = iter._GetNode(); }

bool Iterator::operator==(Iterator iter) const { return _target == iter._GetNode(); }

bool Iterator::operator!=(Iterator iter) const { return _target != iter._GetNode(); }

Iterator::valueType Iterator::operator*() const 
{
	if (_target->_GetNextNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 47);
	return _target->_GetValue(); 
}

Iterator::reference Iterator::operator&() const 
{
	if (_target->_GetNextNode() == nullptr)
		std::_Debug_message(_T("Out of Range"), _T("Iterator.cpp"), 54);
	return _target->_GetAddr(); 
}
