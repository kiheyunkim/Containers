#include "ReverseIterator.h"

ReverseIterator::ReverseIterator() :_target(nullptr) {}
ReverseIterator::ReverseIterator(const ReverseIterator::NodePtr& node) { *_target = const_cast<ReverseIterator::NodePtr&>(node); }
ReverseIterator::~ReverseIterator() {}

ReverseIterator::NodePtr ReverseIterator::_GetNode() { return *_target; }
ReverseIterator::NodePtr& ReverseIterator::_GetAddr() { return *_target; }

ReverseIterator& ReverseIterator::operator++(int) 
{
	_target--;
	return *this;
}

ReverseIterator& ReverseIterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;

	return *this;
}

ReverseIterator& ReverseIterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target--;

	return *this;
}

ReverseIterator& ReverseIterator::operator--(int) 
{
	_target++;
	return *this;
}

ReverseIterator& ReverseIterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target++;

	return *this;
}

ReverseIterator& ReverseIterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		if (_target != nullptr)
			_target++;

	return *this;
}

ReverseIterator::ValueType& ReverseIterator::operator[](int index)
{
	for (int i = 0; i < index; i++)
		_target--;

	return (*_target)->_GetAddr();
}

ReverseIterator& ReverseIterator::operator=(const ReverseIterator& iter) 
{
	_target = iter._target;
	return *this;
}

bool ReverseIterator::operator<(const ReverseIterator& iter)const { return (*_target)->_GetValue() < (*_target)->_GetValue(); }
bool ReverseIterator::operator<=(const ReverseIterator& iter)const { return (*_target)->_GetValue() <= (*_target)->_GetValue(); }
bool ReverseIterator::operator>(const ReverseIterator& iter)const { return (*_target)->_GetValue() > (*_target)->_GetValue(); }
bool ReverseIterator::operator>=(const ReverseIterator& iter)const { return (*_target)->_GetValue() >= (*_target)->_GetValue(); }
bool ReverseIterator::operator!=(const ReverseIterator& iter) const { return _target != iter._target; }
bool ReverseIterator::operator==(const ReverseIterator& iter) const { return _target == iter._target; }
ReverseIterator::ValueType& ReverseIterator::operator*() const { return (*_target)->_GetAddr(); }
ReverseIterator::NodePtr ReverseIterator::operator->() { return *_target; }