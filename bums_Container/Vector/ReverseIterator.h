#ifndef _REVERSEITERATOR_H_
#define _REVERSEITERATOR_H_
#include<iostream>
#include<tchar.h>
#include"Node.h"
template<typename T>
class ReverseIterator
{
private:
	typedef Node<T>* NodePtr;
	typedef T ValueType;

private:
	NodePtr* target;

private:
	ReverseIterator& operator=(const NodePtr& node)
	{
		target = const_cast<ReverseIterator::NodePtr*>(&node);
		return *this;
	}

public:
	NodePtr getNode() { return *target; }
	NodePtr& getAddr() { return *target; }
public:
	ReverseIterator() :target(nullptr) {}
	ReverseIterator(const NodePtr& node) { *target = const_cast<ReverseIterator::NodePtr&>(node); }
	ReverseIterator(const ReverseIterator& iter);
	~ReverseIterator() {}

	ReverseIterator& operator++(int)
	{
		target--;
		return *this;
	}
	
	ReverseIterator& operator+(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target--;

		return *this;
	}

	ReverseIterator& operator+=(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target--;

		return *this;
	}

	ReverseIterator& operator--(int)
	{
		target++;
		return *this;
	}

	ReverseIterator& operator-(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target++;

		return *this;
	}

	ReverseIterator& operator-=(int count)
	{
		for (int i = 0; i < count; i++)
			if (target != nullptr)
				target++;

		return *this;
	}

	ValueType& operator[](int index)
	{
		for (int i = 0; i < index; i++)
			target--;

		return (*target)->getAddr();
	}
	
	ReverseIterator& operator=(const ReverseIterator& iter)
	{
		target = iter.target;
		return *this;
	}

	bool operator<(const ReverseIterator& iter)const { return (*target)->getValue() < (*target)->getValue(); }
	bool operator<=(const ReverseIterator& iter)const { return (*target)->getValue() <= (*target)->getValue(); }
	bool operator>(const ReverseIterator& iter)const { return (*target)->getValue() > (*target)->getValue(); }
	bool operator>=(const ReverseIterator& iter)const { return (*target)->getValue() >= (*target)->getValue(); }
	bool operator==(const ReverseIterator& iter) const { return target == iter.target; }
	bool operator!=(const ReverseIterator& iter) const { return target != iter.target; }
	ValueType& operator*() const { return (*target)->getAddr(); }
	NodePtr operator->() { return *target; }

	friend std::ostream& operator<<(std::ostream& os, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value = (*iter.target)->getValue();
		os << value;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const ReverseIterator& iter)
	{
		ReverseIterator::ValueType value;
		is >> value;
		(*iter.target)->setValue(value);
		return is;
	}
};

#endif // !_REVERSEITERATOR_H_
