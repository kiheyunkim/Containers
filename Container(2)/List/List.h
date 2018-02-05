#ifndef _LIST_H_
#define _LIST_H_
#include"Iterator.h"
#include"ReverseIterator.h"
#include"Node.h"

template<class T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;


public:
	typedef T ValueType;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef Iterator<T> Iterator;
	typedef const Iterator ConstIterator;
	typedef ReverseIterator<T> ReverseIterator;
	typedef const ReverseIterator ConstReverseIterator;
	typedef size_t SizeType;

private:
	void swap(ValueType &x1, ValueType &x2)
	{
		List<T>::ValueType temp = x1;
		x1 = x2;
		x2 = temp;
	}

public:
	List():head(nullptr),tail(nullptr)
	{
		Node<T>* dummyHeadNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* dummyTailNode = static_cast<Node<T>*>(new Node<T>());

		head = dummyHeadNode;
		tail = dummyTailNode;
		
		head->setNextNode(tail);
		tail->setPrevNode(head);
	}
	
	List(const List<T>& list):head(nullptr),tail(nullptr)
	{
		Node<T>* dummyHeadNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* dummyTailNode = static_cast<Node<T>*>(new Node<T>());

		head = dummyHeadNode;
		tail = dummyTailNode;

		head->setNextNode(tail);
		tail->setPrevNode(head);

		List<T>::Iterator iter = list.ConstBegin();

		while (iter != list.ConstEnd())
		{
			PushBack(*iter);
			iter++;
		}
	}

	~List()
	{
		if (!Empty())
			while (!Empty()) PopBack();

		delete head;
		delete tail;
	}

	List& operator=(const List<T>& targetList)
	{
		Node<T>* cur = head->getNextNode();
		List<T>::SizeType copySize = Size();

		for (List<T>::SizeType i = 0; i < copySize; i++)
		{
			PushBack(cur->getValue());
			cur = cur->getNextNode();
		}

		return *this;
	}

	//Iterator
	Iterator Begin() { return static_cast<List<T>::Iterator>(*head->getNextNode()); }
	Iterator End() { return static_cast<List<T>::Iterator>(*tail); }
	ReverseIterator ReverseBegin() { return static_cast<List<T>::ReverseIterator>(*tail->getPrevNode()); }
	ReverseIterator ReverseEnd() { return static_cast<List<T>::ReverseIterator>(*head); }
	ConstIterator ConstBegin() const { return static_cast<List<T>::ConstIterator>(*head->getNextNode()); }
	ConstIterator ConstEnd() const { return static_cast<List<T>::ConstIterator>(*tail); }
	ConstReverseIterator ConstReverseBegin() const { return static_cast<List<T>::ConstReverseIterator>(*tail->getPrevNode()); }
	ConstReverseIterator ConstReverseEnd() const { return static_cast<List<T>::ConstReverseIterator>(*head); }

	//Capacity
	bool Empty() const { return head->getNextNode() == tail; }
	SizeType Size() const
	{
		List<T>::SizeType size = 0;
		List<T>::Iterator tempIter = static_cast<List<T>::Iterator>(*head->getNextNode());

		while (tempIter != ConstEnd())
		{
			size++;
			tempIter++;
		}

		return size;
	}

	SizeType MaxSize() { return -1; }

	//Element access
	Reference Front() { return head->getAddr(); }
	Reference Back() { return tail->getPrevNode()->getAddr(); }

	//Modifiers
	void Assign(SizeType n, ValueType value)
	{
		for (List<T>::SizeType i = 0; i < n; i++)	PushBack(value);
	}
	void EmplaceFront(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(value);

		newNode->setNextNode(head->getNextNode());
		newNode->setPrevNode(head);
		head->getNextNode()->setPrevNode(newNode);
		head->setNextNode(newNode);
	}
	void PushFront(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(value);

		newNode->setNextNode(head->getNextNode());
		newNode->setPrevNode(head);
		head->getNextNode()->setPrevNode(newNode);
		head->setNextNode(newNode);
	}
	void PopFront()
	{
		if (Empty()) return;

		Node<T>* tempNode = head->getNextNode();
		tempNode->getPrevNode()->setNextNode(tempNode->getNextNode());
		tempNode->getNextNode()->setPrevNode(tempNode->getPrevNode());
		tempNode->setPrevNode(nullptr);
		tempNode->setNextNode(nullptr);

		delete tempNode;
	}
	void EmplaceBack(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(value);

		newNode->setNextNode(tail->getPrevNode()->getNextNode());
		newNode->setPrevNode(tail->getPrevNode());
		tail->getPrevNode()->setNextNode(newNode);
		tail->setPrevNode(newNode);
	}
	void PushBack(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(value);

		newNode->setNextNode(tail->getPrevNode()->getNextNode());
		newNode->setPrevNode(tail->getPrevNode());
		tail->getPrevNode()->setNextNode(newNode);
		tail->setPrevNode(newNode);
	}
	void PopBack()
	{
		Node<T>* tempNode = tail->getPrevNode();

		tail->setPrevNode(tempNode->getPrevNode());
		tail->getPrevNode()->setNextNode(tempNode->getNextNode());
		tempNode->setPrevNode(nullptr);
		tempNode->setNextNode(nullptr);

		delete tempNode;
	}
	Iterator Insert(ConstIterator& pos, ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());

		newNode->setValue(val);
		newNode->setNextNode(const_cast<List<T>::Iterator&>(pos).getNode());
		newNode->setPrevNode(const_cast<List<T>::Iterator&>(pos).getNode()->getPrevNode());
		const_cast<List<T>::Iterator&>(pos).getNode()->getPrevNode()->setNextNode(newNode);
		const_cast<List<T>::Iterator&>(pos).getNode()->setPrevNode(newNode);

		return static_cast<List::Iterator>(*newNode);
	}
	Iterator Erase(ConstIterator& pos)
	{
		Node<T>* tempNode = const_cast<List<T>::Iterator&>(pos).getNode();
		List<T>::Iterator iter = static_cast<List<T>::Iterator>(*tempNode);

		tempNode->getPrevNode()->setNextNode(tempNode->getNextNode());
		tempNode->getNextNode()->setPrevNode(tempNode->getPrevNode());
		tempNode->setPrevNode(nullptr);
		tempNode->setNextNode(nullptr);

		delete tempNode;

		return static_cast<List<T>::Iterator>(iter);
	}
	void Swap(List<T> &list)
	{
		Node<T>* headTemp = head;
		Node<T>* tailTemp = tail;

		head = list.head;
		tail = list.tail;

		list.head = headTemp;
		list.tail = tailTemp;

	}
	void Resize(SizeType size)
	{
		List<T>::SizeType originalSize = this->Size();

		if (this->Size() > size)
		{
			for (List<T>::SizeType i = 0; i < originalSize - size; i++)
				this->PopBack();
			return;
		}

		for (List::SizeType i = 0; i < size - originalSize + 1; i++)
			this->PushBack(0);
	}
	void Clear()
	{
		List<T>::SizeType count = Size();

		for (List<T>::SizeType i = 0; i < count; i++)
			this->PopBack();
	}

	//Operations
	void Splice(ConstIterator& iter, List& list)
	{
		List<T>::Iterator tempiter = list.Begin();
		List<T>::SizeType copySize = list.Size();

		for (List<T>::SizeType i = 0; i < copySize; i++)
		{
			Insert(iter, *tempiter);
			tempiter++;
		}

	}
	void Remove(ValueType val)
	{
		if (Empty()) return;

		List<T>::Iterator iter = static_cast<List::Iterator>(*_head);

		while (iter.getNode()->getNextNode() != End().getNode())
		{
			if (iter.getNode()->getValue() == val)
			{
				Erase(iter);
				iter++;
				continue;
			}
			iter++;
		}
	}
	void RemoveIf(bool(*compare)(int))
	{
		if (Empty()) return;

		List<T>::Iterator iter = static_cast<List<T>::Iterator>(*head);

		while (iter.getNode() != End().getNode())
		{
			if (compare(iter.getNode()->getValue()))
			{
				Erase(iter);
				iter++;
				continue;
			}
			iter++;
		}
	}
	void Unique()
	{
		if (Empty()) return;

		List<T>::Iterator iter1 = Begin();
		List<T>::Iterator iter2 = static_cast<List<T>::Iterator>(*Begin().getNode()->getNextNode());

		while (iter1 != *End().getNode() && iter2 != *End().getNode())
		{
			if (iter2.getNode() == End().getNode())
			{
				iter1++;
				iter2 = iter1++;
			}
			if (iter1.getNode()->getValue() == iter2.getNode()->getValue())
			{
				Erase(iter2);
				iter2++;
				continue;
			}
			iter2++;
		}
	}
	void Merge(List<T>& list)
	{
		while (list.Size() != 0)
		{
			PushBack(list.Front());
			list.PopFront();
		}
	}
	void Sort()//use Selection Sorting
	{
		if (Empty()) return;
		if (Size() == 1) return;

		List<T>::SizeType length = Size();
		List<T>::Iterator iter = Begin();
		List<T>::ValueType* tempArray = static_cast<List<T>::ValueType*>(new List<T>::ValueType[length]);

		for (List<T>::SizeType i = 0; i < length; i++)
		{
			tempArray[i] = iter.getNode()->getValue();
			iter = static_cast<List<T>::Iterator>(*iter.getNode()->getNextNode());
		}

		int minPos = 0;
		int insertPos = 0;

		for (List<T>::SizeType pass = 0; pass < length - 1; pass++)
		{
			minPos = insertPos;
			for (List<T>::SizeType i = insertPos + 1; i < length; i++)
			{
				if (tempArray[i] < tempArray[minPos])	minPos = i;
			}

			swap(tempArray[minPos], tempArray[insertPos]);
			insertPos++;
		}

		Clear();

		for (List<T>::SizeType i = 0; i < length; i++)
			PushBack(tempArray[i]);

		delete[] tempArray;
	}
	void Reverse()
	{
		List<T> tempList;
		tempList.Splice(tempList.Begin(), *this);

		Clear();

		while (!tempList.Empty())
		{
			PushBack(tempList.Back());
			tempList.PopBack();
		}
	}
};
#endif //_LIST_H_