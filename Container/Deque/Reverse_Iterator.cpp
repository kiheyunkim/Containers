#include "Reverse_Iterator.h"

Reverse_Iterator::Reverse_Iterator() :_target(nullptr) {}
Reverse_Iterator::Reverse_Iterator(const Node& node) { _target = const_cast<Node*>(&node); }
Reverse_Iterator::Reverse_Iterator(const Reverse_Iterator& reverseIterator) : _target(reverseIterator._target) {}

Reverse_Iterator::~Reverse_Iterator() {}

Reverse_Iterator& Reverse_Iterator::operator++()
{
	_target = _target->_GetPrevNode();
	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator--() 
{
	_target = _target->_GetNextNode(); 
	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetPrevNode();
	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetNextNode();
	return *this;
}

void Reverse_Iterator::operator=(Reverse_Iterator iter) { _target = iter._GetNode(); }

bool Reverse_Iterator::operator==(Reverse_Iterator iter) const { return _target == iter._GetNode(); }

bool Reverse_Iterator::operator!=(Reverse_Iterator iter) const { return _target != iter._GetNode(); }

Reverse_Iterator::value_type& Reverse_Iterator::operator*() const { return _target->_GetAddr(); }

