#include "ReverseIterator.h"

ReverseIterator::ReverseIterator() :_target(nullptr) {}
ReverseIterator::ReverseIterator(const Node& node) { _target = const_cast<Node*>(&node); }
ReverseIterator::ReverseIterator(const ReverseIterator& reverseIterator) : _target(reverseIterator._target) {}

ReverseIterator::~ReverseIterator() {}

ReverseIterator& ReverseIterator::operator++()
{
	_target = _target->_GetPrevNode();
	return *this;
}

ReverseIterator& ReverseIterator::operator--()
{
	_target = _target->_GetNextNode();
	return *this;
}

ReverseIterator& ReverseIterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetPrevNode();
	return *this;
}

ReverseIterator& ReverseIterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		_target = _target->_GetNextNode();
	return *this;
}

void ReverseIterator::operator=(ReverseIterator iter) { _target = iter._GetNode(); }

bool ReverseIterator::operator==(ReverseIterator iter) const { return _target == iter._GetNode(); }

bool ReverseIterator::operator!=(ReverseIterator iter) const { return _target != iter._GetNode(); }

ReverseIterator::ValueType& ReverseIterator::operator*() const { return _target->_GetAddr(); }

