#ifndef _REVERSEITERATOR_H_
#define _REVERSEITERATOR_H_

#include<iostream>
#include"Node.h"
template<typename T>
class ReverseIterator
{
private:
	Node<T> *target;

public:
	typedef T ValueType;

public:
	Node<T>* getNode() { return target; }

public:
	ReverseIterator() :target(nullptr) {}
	ReverseIterator(const Node<T>& node) { target = const_cast<Node<T>*>(&node); }
	ReverseIterator(const ReverseIterator<T>& reverseIterator) : target(reverseIterator.target) {}
	~ReverseIterator() {}

	ReverseIterator<T>& operator++()
	{
		target = target->getPrevNode();
		return *this;
	}

	ReverseIterator<T>& operator--()
	{
		target = target->getNextNode();
		return *this;
	}

	ReverseIterator<T>& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			target = target->getPrevNode();
		return *this;
	}

	ReverseIterator<T>& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			target = target->getNextNode();
		return *this;
	}

	void operator=(ReverseIterator<T> iter) { target = iter.getNode(); }
	bool operator==(ReverseIterator<T> iter) const { return target == iter.getNode(); }
	bool operator!=(ReverseIterator<T> iter) const { return target != iter.getNode(); }
	ValueType& operator*() const { return target->getAddr(); }

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = iter.target->getValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value;
		is >> value;
		iter.target->setValue(value);
		return is;
	}
};

#endif // !_REVERSEITERATOR_H_