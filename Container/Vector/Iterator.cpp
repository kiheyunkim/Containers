#include "Iterator.h"

Iterator::Iterator()
{
	target = nullptr;
}

Iterator::Iterator(Node *node)
{
	target = node;
}

Iterator Iterator::operator++(int)
{
	target = target->_GetNextNode();
	return *this;
}

Iterator Iterator::operator+(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (target != nullptr)
			target = target->_GetNextNode();
	}
	return *this;
}

Iterator Iterator::operator+=(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (target != nullptr)
			target = target->_GetNextNode(); 
	}
	return *this;
}

Iterator Iterator::operator--()
{
	target = target->_GetPrevNode();
	return *this;
}

Iterator Iterator::operator-(int count)
{
	for (int i = 0; i < count; i++)
		if (target != nullptr)
			target=target->_GetPrevNode();
	return *this;
}

Iterator Iterator::operator-=(int count)
{
	for (int i = 0; i < count; i++)
		if (target != nullptr)
			target = target->_GetPrevNode();
	return *this;
}

int Iterator::operator[](int index)
{
	for (int i = 0; i < index; i++)
		target = target->_GetNextNode();
	return target->_GetValue();
}

void Iterator::operator=(Node *node)
{
	target = node;
}

bool Iterator::operator!=(Node *iter)
{
	return target != iter;
}

bool Iterator::operator==(Node *iter)
{
	return target == iter;
}

int Iterator::operator*()
{
	return target->_GetValue();
}