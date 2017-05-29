#include "Reverse_Iterator.h"

Reverse_Iterator::Reverse_Iterator() :_target(nullptr) {}
Reverse_Iterator::Reverse_Iterator(const Node& node) : _target(const_cast<Node*>(&node)) { }
Reverse_Iterator::~Reverse_Iterator() {}

Node* Reverse_Iterator::_GetNode() { return _target; }

Reverse_Iterator& Reverse_Iterator::operator++(int) 
{
	_target = _target->_GetPrevNode();
	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator--(int) 
{
	_target = _target->_GetNextNode();
	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator=(const Reverse_Iterator& iter) 
{
	memcpy(_target, iter._target, sizeof(_target));
	return *this;
}

bool Reverse_Iterator::operator==(const Reverse_Iterator& iter) const { return _target == iter._target; }

bool Reverse_Iterator::operator!=(const Reverse_Iterator& iter) const { return _target != iter._target; }

Reverse_Iterator::valueType Reverse_Iterator::operator*() const { return _target->_GetValue(); }