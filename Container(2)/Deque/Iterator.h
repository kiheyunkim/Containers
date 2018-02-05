#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include<iostream>
#include<tchar.h>
#include"Node.h"

template<typename T>
class Iterator
{
private:
	Node<T> *target;

public:
	typedef T ValueType;

public:
	Node<T>* getNode() { return target; }

public:
	Iterator() :target(nullptr) {}
	Iterator(const Node<T>& node) : target(const_cast<Node<T>*>(&node)) {}
	Iterator(const Iterator<T>& iterator) : target(iterator.target) {}
	~Iterator() {}

	Iterator<T>& operator++(int)
	{
		target = target->getNextNode();
		return *this;
	}

	Iterator<T>& operator--(int)
	{
		target = target->getPrevNode();
		return *this;
	}

	Iterator<T>& operator+(int count)
	{
		for (int i = 0; i < count; i++)
			target = target->getNextNode();
		return *this;
	}

	Iterator<T>& operator-(int count)
	{
		for (int i = 0; i < count; i++)
			target = target->getPrevNode();
		return *this;
	}

	Iterator<T>& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			target = target->getNextNode();
		return *this;
	}

	Iterator<T>& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			target = target->getPrevNode();
		return *this;
	}

	ValueType& operator[](size_t index)
	{
		Node<T> *cur = target;
		for (size_t i = 0; i < index; i++)
			cur = cur->getNextNode();

		return cur->getAddr();
	}

	Iterator<T>& operator=(const Iterator<T>& iter)
	{
		memcpy(this, &iter, sizeof(Iterator));
		return *this;
	}

	bool operator==(const Iterator<T>& iter) const { return target == const_cast<Iterator&>(iter).getNode(); }
	bool operator!=(const Iterator<T>& iter) const { return target != const_cast<Iterator&>(iter).getNode(); }
	bool operator<(const Iterator<T>& iter) const { return target->getValue() < const_cast<Iterator&>(iter).target->getValue(); }
	bool operator<=(const Iterator<T>& iter) const { return target->getValue() <= const_cast<Iterator&>(iter).target->getValue(); }
	bool operator>(const Iterator<T>& iter) const { return target->getValue() > const_cast<Iterator&>(iter).target->getValue(); }
	bool operator>=(const Iterator<T>& iter) const { return target->getValue() >= const_cast<Iterator&>(iter).target->getValue(); }
	ValueType& operator*() const { return target->getAddr(); }

	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		Iterator::ValueType value = iter.target->getValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		Iterator::ValueType value;
		is >> value;
		iter.target->setValue(value);
		return is;
	}

};

#endif // !_ITERATOR_H_