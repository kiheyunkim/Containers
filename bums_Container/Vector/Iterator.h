#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include<iostream>
#include"Node.h"

template<typename T>
class Iterator
{
private:
	typedef Node<T>* NodePtr;
	typedef T ValueType;

private:
	NodePtr* target;

private:
	Iterator& operator=(NodePtr const& node)
	{
		target = const_cast<Iterator::NodePtr*>(&node);
		return *this;
	}

private:
	NodePtr  getNode() { return *target; }
	NodePtr& getAddr() { return *target; }

public:
	Iterator() :target(nullptr) {}
	Iterator(const NodePtr& node) : target(const_cast<Iterator::NodePtr*>(&node)) {}
	Iterator(const Iterator<T>& iter) { memcpy(this, &iter, sizeof(Iterator)); }
	~Iterator() {}

	Iterator<T>& operator++(int)
	{
		++target;
		return *this;
	}

	Iterator<T>& operator+(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target++;

		return *this;
	}
	Iterator<T>& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target++;

		return *this;
	}
	Iterator<T>& operator--()
	{
		--target;

		return *this;
	}
	Iterator<T>& operator-(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target--;

		return *this;
	}
	Iterator<T>& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target--;

		return *this;
	}
	ValueType& operator[](int index)
	{
		for (int i = 0; i < index; i++)
			target++;

		return (*target)->getAddr();
	}
	Iterator<T>& operator=(const Iterator& iter)
	{
		target = iter.target;
		return *this;
	}
	bool operator<(const Iterator<T>& iter) const { return (*target)->getValue() < (*target)->getValue(); }
	bool operator<=(const Iterator<T>& iter) const { return (*target)->getValue() <= (*target)->getValue(); }
	bool operator>(const Iterator<T>& iter) const { return (*target)->getValue() > (*target)->getValue(); }
	bool operator>=(const Iterator<T>& iter)const { return (*target)->getValue() >= (*target)->getValue(); }
	bool operator==(const Iterator<T>& iter)const { return target == iter.target; }
	bool operator!=(const Iterator<T>& iter)const { return target != iter.target; }
	ValueType& operator*() { return (*target)->getAddr(); }
	NodePtr operator->() { return *target; }

	friend std::ostream& operator<<(std::ostream& os, const Iterator& iter)
	{
		Iterator::ValueType value = (*(iter.target))->getValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Iterator& iter)
	{
		int value;
		is >> value;
		(*(iter.target))->setValue(value);
		return is;
	}
};
#endif // !_ITERATOR_H_