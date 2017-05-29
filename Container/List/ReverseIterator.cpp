#include "ReverseIterator.h"

ReverseIterator::ReverseIterator() :_target(nullptr) {}
ReverseIterator::ReverseIterator(const Node& node) : _target(const_cast<Node*>(&node)) { }
ReverseIterator::~ReverseIterator() {}

Node* ReverseIterator::_GetNode() { return _target; }

ReverseIterator& ReverseIterator::operator++(int)
{
	_target = _target->_GetPrevNode();
	return *this;
}

ReverseIterator& ReverseIterator::operator--(int)
{
	_target = _target->_GetNextNode();
	return *this;
}

ReverseIterator& ReverseIterator::operator=(const ReverseIterator& iter)
{
	memcpy(_target, iter._target, sizeof(_target));
	return *this;
}

bool ReverseIterator::operator==(const ReverseIterator& iter) const { return _target == iter._target; }

bool ReverseIterator::operator!=(const ReverseIterator& iter) const { return _target != iter._target; }

ReverseIterator::ValueType ReverseIterator::operator*() const { return _target->_GetValue(); }