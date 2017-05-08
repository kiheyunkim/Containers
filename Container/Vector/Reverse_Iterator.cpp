#include "Reverse_Iterator.h"

Reverse_Iterator::Reverse_Iterator() :_target(nullptr) {}

Reverse_Iterator::Reverse_Iterator(Node *node) { _target = node; }

Reverse_Iterator::~Reverse_Iterator() {}

Node* Reverse_Iterator::_GetNode() { return _target; }

Reverse_Iterator Reverse_Iterator::operator++(int) 
{
	_target--;
	
	return *this;
}

Reverse_Iterator Reverse_Iterator::operator--(int) 
{
	_target++;

	return *this;
}

void Reverse_Iterator::operator=(Reverse_Iterator iter) { _target = iter._GetNode(); }

bool Reverse_Iterator::operator==(Reverse_Iterator iter) const { return _target == iter._GetNode(); }

bool Reverse_Iterator::operator!=(Reverse_Iterator iter) const { return _target != iter._GetNode(); }

Reverse_Iterator::value_type Reverse_Iterator::operator*() const { return _target->_GetValue(); }

Reverse_Iterator::value_type& Reverse_Iterator::operator&() const { return _target->_GetAddr(); }