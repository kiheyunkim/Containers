#include "Iterator.h"

Iterator::Iterator() :_target(nullptr) {}
Iterator::Iterator(const Node& node) : _target(const_cast<Node*>(&node)) {}
Iterator::Iterator(const Iterator& iterator) : _target(iterator._target) {}
Iterator::~Iterator() {}

Iterator& Iterator::operator++(int) 
{
	_target = _target->_GetNextNode();
	return *this;
}	

Iterator& Iterator::operator--(int) 
{
	_target = _target->_GetPrevNode();
	return *this;
}

Iterator& Iterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetNextNode();
	return *this;
}

Iterator& Iterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetPrevNode();
	return *this;
}

Iterator& Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetNextNode();
	return *this;
}

Iterator& Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetPrevNode();
	return *this;
}

Iterator::value_type& Iterator::operator[](size_t index)
{
	Node *cur = _target;
	for (size_t i = 0; i < index; i++)
		cur = cur->_GetNextNode();

	return cur->_GetAddr();
}

Iterator& Iterator::operator=(const Iterator& iter) 
{
	memcpy(this, &iter, sizeof(Iterator)); 
	return *this;
}

bool Iterator::operator==(const Iterator& iter) const { return _target == const_cast<Iterator&>(iter)._GetNode(); }
bool Iterator::operator!=(const Iterator& iter) const { return _target != const_cast<Iterator&>(iter)._GetNode(); }
bool Iterator::operator<(const Iterator& iter) const { return _target->_GetValue() < const_cast<Iterator&>(iter)._target->_GetValue(); }
bool Iterator::operator<=(const Iterator& iter) const { return _target->_GetValue() <= const_cast<Iterator&>(iter)._target->_GetValue();}
bool Iterator::operator>(const Iterator& iter) const { return _target->_GetValue() > const_cast<Iterator&>(iter)._target->_GetValue();}
bool Iterator::operator>=(const Iterator& iter) const { return _target->_GetValue() >= const_cast<Iterator&>(iter)._target->_GetValue(); }

Iterator::value_type& Iterator::operator*() const { return _target->_GetAddr(); }