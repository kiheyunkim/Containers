#ifndef _DEQUE_H_
#define _DEQUE_H_

#include"Node.h"
#include"Iterator.h"
#include"ReverseIterator.h"
template<typename T>
class Deque
{
private:
	Node<T> *head;
	Node<T> *rear;

public:
	Deque() :head(nullptr), rear(nullptr)
	{
		Node<T>* headDummyNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* rearDummyNode = static_cast<Node<T>*>(new Node<T>());
		head = headDummyNode;
		rear = rearDummyNode;
		head->setNextNode(rear);
		rear->setPrevNode(head);
	}
	Deque(const Deque<T>& deque) :head(nullptr), rear(nullptr)
	{
		Node<T>* headDummyNode = static_cast<Node<T>*>(new Node<T>());
		Node<T>* rearDummyNode = static_cast<Node<T>*>(new Node<T>());
		head = headDummyNode;
		rear = rearDummyNode;
		head->setNextNode(rear);
		rear->setPrevNode(head);

		for (Iterator iter = deque.ConstBegin(); iter != deque.ConstEnd(); iter++)
			PushBack(*iter);
	}

	~Deque()
	{
		Clear();

		delete head;
		delete rear;
	}
	
	typedef T ValueType;
	//allocator
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef Iterator<T> Iterator;
	typedef const Iterator ConstIterator;
	typedef ReverseIterator<T> ReverseIterator;
	typedef const ReverseIterator ConstReverseIterator;
	//difference
	typedef size_t SizeType;
	
	
	void operator=(const Deque<T>& deque)
	{
		Clear();
		Deque::SizeType copySize = Size();
		Deque::Iterator iter = static_cast<Deque::Iterator>(deque.ConstBegin());

		for (size_t i = 0; i < copySize; i++)
			PushBack(iter[i]);
	}

	//Iterators
	Iterator Begin() { return  static_cast<Iterator>(*head->getNextNode()); }
	Iterator End() { return static_cast<Iterator>(*rear); }
	ReverseIterator ReverseBegin() { return static_cast<ReverseIterator>(*rear->getPrevNode()); }
	ReverseIterator ReverseEnd() { return static_cast<ReverseIterator>(*head); }
	ConstIterator ConstBegin() const { return static_cast<ConstIterator>(*head->getNextNode()); }
	ConstIterator ConstEnd() const { return static_cast<ConstIterator>(*rear); }
	ConstReverseIterator ConstReverseBegin() const { return static_cast<ConstReverseIterator>(*rear->getPrevNode()); }
	ConstReverseIterator ConstReverseEnd() const { return static_cast<ConstReverseIterator>(*head); }

	//Capacity
	SizeType Size() const
	{
		SizeType size = 0;
		Iterator tempIter = static_cast<Iterator>(ConstBegin());
		while (tempIter != ConstEnd())
		{
			size++;
			tempIter++;
		}
		return size;
	}

	SizeType MaxSize() { return -1; }
	
	void Resize(SizeType newSize)
	{
		SizeType originalSize = Size();
		if (newSize == originalSize) return;

		if (newSize < originalSize)
		{
			for (SizeType count = 0; count < originalSize - newSize; count++)
				PopBack();
			return;
		}

		if (newSize > originalSize)
		{
			for (SizeType count = 0; count < newSize - originalSize; count++)
				PushBack(0);
		}
	}

	bool Empty() const { return head->getNextNode() == rear; }
	void ShrinkToFit();

	//Element Access;
	ValueType operator[](SizeType count)
	{
		Node<T>* cur = head;

		for (Deque::SizeType i = 0; i < count; i++)
			cur = cur->getNextNode();

		return cur->getValue();
	}

	Reference At(SizeType n)
	{
		Node* cur = head;
		for (size_t i = 0; i < n; i++)
			cur = cur->getNextNode();

		return cur->getAddr();
	}
	
	ValueType Front() const { return head->getNextNode()->getValue(); }

	ValueType Back() const { return rear->getPrevNode()->getValue(); }



	//Modifiers
	void Assign(const Iterator& first, const Iterator& last)
	{
		Clear();

		Deque::Iterator temp = first;
		while (temp != last) { PushBack(temp.getNode()->getValue()); }
	}

	void PushBack(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(value);

		newNode->setNextNode(rear->getPrevNode()->getNextNode());
		newNode->setPrevNode(rear->getPrevNode());
		rear->getPrevNode()->setNextNode(newNode);
		rear->setPrevNode(newNode);
	}

	void PushFront(ValueType value)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(value);

		newNode->setNextNode(head->getNextNode());
		newNode->setPrevNode(head->getNextNode()->getPrevNode());
		head->getNextNode()->setPrevNode(newNode);
		head->setNextNode(newNode);
	}

	void PopBack()
	{
		if (Empty()) return;

		Node<T>* cur = rear->getPrevNode();
		cur->getNextNode()->setPrevNode(cur->getPrevNode());
		cur->getPrevNode()->setNextNode(cur->getNextNode());
		cur->setPrevNode(nullptr);
		cur->setNextNode(nullptr);

		delete cur;
	}

	void PopFront()
	{
		if (Empty()) return;

		Node<T>* cur = head->getNextNode();
		cur->getNextNode()->setPrevNode(cur->getPrevNode());
		cur->getPrevNode()->setNextNode(cur->getNextNode());
		cur->setPrevNode(nullptr);
		cur->setNextNode(nullptr);

		delete cur;
	}

	Iterator Insert(ConstIterator& position, ValueType val)
	{
		Deque::Iterator pos = position;
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(val);
		newNode->setNextNode(pos.getNode());
		newNode->setPrevNode(pos.getNode()->getPrevNode());
		pos.getNode()->setPrevNode(newNode);
		pos.getNode()->getPrevNode()->setNextNode(newNode);

		return *newNode;
	}

	Iterator Erase(ConstIterator& position)
	{
		Deque::Iterator pos = position;
		Node<T>* tempNode = pos.getNode();
		Deque::Iterator returnIter = static_cast<Deque::Iterator>(*pos.getNode()->getNextNode());

		pos.getNode()->getNextNode()->setPrevNode(pos.getNode()->getPrevNode());
		pos.getNode()->getPrevNode()->setNextNode(pos.getNode()->getNextNode());
		tempNode->setNextNode(nullptr);
		tempNode->setPrevNode(nullptr);
		delete tempNode;

		return returnIter;
	}

	void Swap(Deque& deque)
	{
		Node<T>* tempHead = deque.head;
		Node<T>* tempRear = deque.rear;

		deque.head = head;
		deque.rear = rear;

		head = tempHead;
		rear = tempRear;
	}
	void Clear()
	{
		Deque::SizeType clearSize = Size();
		for (Deque::SizeType i = 0; i < clearSize; i++)
			PopBack();
	}

	Iterator Emplace(ConstIterator& position, ValueType val)
	{
		Deque::Iterator pos = position;
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(val);
		newNode->setNextNode(pos.getNode());
		newNode->setPrevNode(pos.getNode()->getPrevNode());
		pos.getNode()->setPrevNode(newNode);
		pos.getNode()->getPrevNode()->setNextNode(newNode);

		return static_cast<Deque::Iterator>(*newNode);
	}

	Iterator EmplaceBack(ValueType val)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(val);

		newNode->setNextNode(head->getNextNode());
		newNode->setPrevNode(head->getNextNode()->getPrevNode());
		head->getNextNode()->setPrevNode(newNode);
		head->setNextNode(newNode);

		return static_cast<Deque::Iterator>(*newNode);
	}

	Iterator EmplaceFront(ValueType val)
	{
		Node<T>* newNode = static_cast<Node<T>*>(new Node<T>());
		newNode->setValue(val);

		newNode->setNextNode(head->getNextNode());
		newNode->setPrevNode(head->getNextNode()->getPrevNode());
		head->_GetNextNode()->setPrevNode(newNode);
		head->_SetNextNode(newNode);

		return static_cast<Deque::Iterator>(*newNode);
	}

	//allocator
	void GetAllocator();

};

#endif // !_DEQUE_H_
