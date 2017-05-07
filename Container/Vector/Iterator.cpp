#include "Iterator.h"

Iterator::Iterator() :_target(nullptr) {}

Iterator::Iterator(Node **node) : _target(node) {}

Iterator Iterator::operator++(int)
{
	++_target;
	return *this;
}	

Iterator Iterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			_target++;
	}
	return *this;
}

Iterator Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (_target != nullptr)
			_target++;
	}
	return *this;
}

Iterator Iterator::operator--()
{
	_target--;
	return *this;
}

Iterator Iterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;
	return *this;
}

Iterator Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;
	return *this;
}

int Iterator::operator[](int index)
{
	for (int i = 0; i < index; i++)
		_target--;
	return (*_target)->_GetValue();
}

void Iterator::operator=(Iterator iter) { _target = iter._target; }

bool Iterator::operator!=(Iterator iter) { return _target != iter._target; }

bool Iterator::operator==(Iterator iter) { return _target == iter._target; }

int Iterator::operator*()
{
	return (*_target)->_GetValue();
}