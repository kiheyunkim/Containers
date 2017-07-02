#include "Reverse_Iterator.h"

Reverse_Iterator::Reverse_Iterator() :_target(nullptr) {}
Reverse_Iterator::Reverse_Iterator(Node *node) { _target = node; }
Reverse_Iterator::~Reverse_Iterator() {}

Reverse_Iterator Reverse_Iterator::operator++(int) 
{
	_target = _target->_GetPrevNode(); 
	return *this;
}

Reverse_Iterator Reverse_Iterator::operator--(int) 
{
	_target = _target->_GetNextNode(); 
	return *this;
}

Reverse_Iterator Reverse_Iterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			_target = _target->_GetPrevNode();
	}
	return *this;
}

Reverse_Iterator Reverse_Iterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			_target = _target->_GetNextNode();
	}
	return *this;
}

void Reverse_Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			_target = _target->_GetPrevNode();
	}
}

void Reverse_Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			_target = _target->_GetNextNode();
	}
}

int Reverse_Iterator::operator[](size_t index) const
{
	Node *cur = _target;
	for (size_t i = 0; i < index; i++)
	{
		if (cur != nullptr) {}
		cur = cur->_GetPrevNode();
	}
	return cur->_GetValue();
}

void Reverse_Iterator::operator=(Reverse_Iterator iter) { _target = iter._GetNode(); }

bool Reverse_Iterator::operator==(Reverse_Iterator iter) const { return _target == iter._GetNode(); }

bool Reverse_Iterator::operator!=(Reverse_Iterator iter) const { return _target != iter._GetNode(); }

bool Reverse_Iterator::operator<(Reverse_Iterator iter) const { return _target->_GetValue() < iter._GetNode()->_GetValue(); }

bool Reverse_Iterator::operator<=(Reverse_Iterator iter) const { return _target->_GetValue() <= iter._GetNode()->_GetValue(); }

bool Reverse_Iterator::operator>(Reverse_Iterator iter) const { return _target->_GetValue() > iter._GetNode()->_GetValue(); }

bool Reverse_Iterator::operator>=(Reverse_Iterator iter) const { return _target->_GetValue() >= iter._GetNode()->_GetValue(); }

Reverse_Iterator::value_type Reverse_Iterator::operator*() const { return _target->_GetValue(); }

Reverse_Iterator::value_type* Reverse_Iterator::operator&() const { return _target->_GetAddr(); }

