#include<memory>
#include "Iterator.h"

Iterator::Iterator() :_target(nullptr) {}
Iterator::Iterator(Node* const& node) : _target(const_cast<Node**>(&node))  {}
Iterator::Iterator(const Iterator& iter) { memcpy(this, &iter, sizeof(Iterator)); }
Iterator::~Iterator() {}

Node* Iterator::_GetNode() { return *_target; }
Node*& Iterator::_GetAddr() { return *_target; }


Iterator& Iterator::operator++(int)
{
	++_target;
	return *this;
}	

Iterator& Iterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target++;

	return *this;
}

Iterator& Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target++;

	return *this;
}

Iterator& Iterator::operator--()
{
	--_target;

	return *this;
}

Iterator& Iterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;

	return *this;
}

Iterator& Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;

	return *this;
}

int& Iterator::operator[](int index)
{
	for (int i = 0; i < index; i++)
		_target++;

	return (*_target)->_GetAddr();
}

Iterator& Iterator::operator=(const Iterator& iter) 
{
	_target = iter._target;  
	return *this; 
}

Iterator& Iterator::operator=(Node* const& node)
{
	_target = const_cast<Node**>(&node);
	return *this;
}


bool Iterator::operator<(const Iterator& iter) const { return (*_target)->_GetValue() < (*_target)->_GetValue(); }
bool Iterator::operator<=(const Iterator& iter) const { return (*_target)->_GetValue() <= (*_target)->_GetValue(); }
bool Iterator::operator>(const Iterator& iter)  const { return (*_target)->_GetValue() > (*_target)->_GetValue(); }
bool Iterator::operator>=(const Iterator& iter) const{ return (*_target)->_GetValue() >= (*_target)->_GetValue(); }
bool Iterator::operator!=(const Iterator& iter) const { return _target != iter._target; }
bool Iterator::operator==(const Iterator& iter) const { return _target == iter._target; }

int& Iterator::operator*() { return (*_target)->_GetAddr(); }
Node* Iterator::operator->() { return *_target; }