#include "Reverse_Iterator.h"

Reverse_Iterator::Reverse_Iterator() :_target(nullptr) {}
Reverse_Iterator::Reverse_Iterator(const Reverse_Iterator::NodePtr& node) { *_target = const_cast<Reverse_Iterator::NodePtr&>(node); }
Reverse_Iterator::~Reverse_Iterator() {}

Reverse_Iterator::NodePtr Reverse_Iterator::_GetNode() { return *_target; }
Reverse_Iterator::NodePtr& Reverse_Iterator::_GetAddr() { return *_target; }


Reverse_Iterator& Reverse_Iterator::operator++(int) 
{
	_target--;
	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;

	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;

	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator--(int) 
{
	_target++;
	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target++;

	return *this;
}

Reverse_Iterator& Reverse_Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target++;

	return *this;
}

int& Reverse_Iterator::operator[](int index)
{
	for (int i = 0; i < index; i++)
		_target--;

	return (*_target)->_GetAddr();
}

Reverse_Iterator& Reverse_Iterator::operator=(const Reverse_Iterator& iter) 
{
	_target = iter._target;
	return *this;
}

bool Reverse_Iterator::operator<(const Reverse_Iterator& iter)const { return (*_target)->_GetValue() < (*_target)->_GetValue(); }
bool Reverse_Iterator::operator<=(const Reverse_Iterator& iter)const { return (*_target)->_GetValue() <= (*_target)->_GetValue(); }
bool Reverse_Iterator::operator>(const Reverse_Iterator& iter)const { return (*_target)->_GetValue() > (*_target)->_GetValue(); }
bool Reverse_Iterator::operator>=(const Reverse_Iterator& iter)const { return (*_target)->_GetValue() >= (*_target)->_GetValue(); }
bool Reverse_Iterator::operator!=(const Reverse_Iterator& iter) const { return _target != iter._target; }
bool Reverse_Iterator::operator==(const Reverse_Iterator& iter) const { return _target == iter._target; }
int& Reverse_Iterator::operator*() const { return (*_target)->_GetAddr(); }
Reverse_Iterator::NodePtr Reverse_Iterator::operator->() { return *_target; }