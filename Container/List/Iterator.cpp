#include "Iterator.h"

Iterator::Iterator() :_target(nullptr) {}
Iterator::Iterator(const Node& node) : _target(const_cast<Node*>(&node)) { }
Iterator::~Iterator() {}

Node* Iterator::_GetNode() { return _target; }

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

Iterator& Iterator::operator=(const Iterator& iter) 
{
	memcpy(_target,iter._target , sizeof(Iterator));
	return *this;
}

bool Iterator::operator==(const Iterator& iter) const { return _target == const_cast<Iterator&>(iter)._GetNode(); }

bool Iterator::operator!=(const Iterator& iter) const { return _target != const_cast<Iterator&>(iter)._GetNode(); }

Iterator::valueType Iterator::operator*() const { return _target->_GetValue(); }

