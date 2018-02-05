#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include<iostream>
#include<tchar.h>
#include"Node.h"

template<class T>
class List;

template<class T>
class Iterator
{
private:
	typedef T ValueType;

private:
	Node<T>* target;

private:
	Node<T>* getNode() { return target; }

private:
	Iterator(const Node<T>& node) :target(const_cast<Node<T>*>(&node)) {}

public:
	Iterator() :target(nullptr) {}
	Iterator(const Iterator<T>& iter) { memcpy(this, &iter, sizeof(Iterator<T>)); }
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
	Iterator<T>& operator=(const Iterator<T>& iter)
	{
		memcpy(target, iter.target, sizeof(Iterator));
		return *this;
	}
	bool operator==(const Iterator<T>& iter) const { return target == const_cast<Iterator&>(iter).getNode(); }
	bool operator!=(const Iterator<T>& iter) const { return target != const_cast<Iterator&>(iter).getNode(); }
	ValueType operator*() const { return target->getValue(); }
	
	friend std::ostream& operator<<(std::ostream& os, const Iterator<T>& iter)
	{
		Iterator<T>::ValueType value = iter.target->getValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator<T>& iter)
	{
		Iterator<T>::ValueType value;
		is >> value;
		iter.target->setValue(value);
		return is;
	}

	friend class List<T>;
};

#endif // !_ITERATOR_H_