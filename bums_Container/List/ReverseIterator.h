#ifndef _REVERSEITERATOR_H_
#define _REVERSEITERATOR_H_
#include<iostream>
#include<tchar.h>
#include"Node.h"

template<class T>
class List;

template<class T>
class ReverseIterator
{
private:
	typedef T ValueType;

private:
	Node<T>* target;

private:
	Node<T>* _GetNode() { return target; }

private:
	ReverseIterator(const Node<T>& node) :target(const_cast<Node<T>*>(&node)) {}

public:
	ReverseIterator() :target(nullptr) {}
	ReverseIterator(const Iterator<T>& iter) { memcpy(this, &iter, sizeof(Iterator<T>)); }
	~ReverseIterator() {}

	ReverseIterator& operator++(int)
	{
		target = target->getPrevNode();
		return *this;
	}
	ReverseIterator& operator--(int)
	{
		target = target->getNextNode();
		return *this;
	}
	ReverseIterator& operator=(const ReverseIterator& iter)
	{
		memcpy(target, iter.target, sizeof(target));
		return *this;
	}
	bool operator==(const ReverseIterator& iter) const { return target == iter.target; }
	bool operator!=(const ReverseIterator& iter) const { return target != iter.target; }
	ValueType operator*() const { return target->getValue(); }

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter.target->getValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter.target->getValue();
		is >> value;
		return is;
	}
};
#endif	//_REVERSEITERATOR_H_