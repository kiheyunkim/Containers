#pragma once
#include "Iterator.h"
#include "ReverseIterator.h"
#include "Node.h"

#define		ALLOC_SIZE		6
template<typename T>
class Vector
{
private:
	typedef Node<T>* NodePtr;

private:
	NodePtr* dataArray;

private:
	unsigned int headIndex;
	unsigned int tailIndex;
	size_t arraySize;

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

public:
	Vector() :headIndex(1), tailIndex(1), arraySize(0), dataArray(nullptr) {}
	~Vector()
	{
		for (size_t i = 0; i < tailIndex; i++)
			delete dataArray[i];
		delete[] dataArray;
	}

	Iterator Begin() const { return static_cast<Vector::Iterator>(dataArray[headIndex]); }
	Iterator End() const { return  static_cast<Vector::Iterator>(dataArray[tailIndex]); }
	ReverseIterator ReverseBegin() const { return static_cast<Vector::ReverseIterator>(dataArray[tailIndex]); }
	ReverseIterator ReverseEnd() const { return static_cast<Vector::ReverseIterator>(dataArray[headIndex]); }
	const Iterator ConstBegin() const { return static_cast<Vector::ConstIterator>(dataArray[headIndex]); }
	const Iterator ConstEnd() const { return static_cast<Vector::ConstIterator>(dataArray[tailIndex]); }
	const ReverseIterator ConstReverseBegin() const { return static_cast<ConstReverseIterator>(dataArray[tailIndex]); }
	const ReverseIterator ConstReverseEnd() const { return static_cast<ConstReverseIterator>(dataArray[headIndex]); }

	SizeType Size() const { return tailIndex - headIndex - 1; }
	SizeType MaxSize() const { return arraySize - 2; }
	void Resize();
	SizeType Capacity() const { return arraySize; }
	bool Empty() const { return headIndex == tailIndex; }
	void Reserve()
	{
		Vector::NodePtr* tempArray = static_cast<Vector::NodePtr*>(new Vector::NodePtr[arraySize]);
		memcpy(tempArray, dataArray, arraySize * sizeof(Vector::NodePtr));

		for (Vector::SizeType index = headIndex; index <= tailIndex; index++)
			dataArray[index] = tempArray[tailIndex - index];

		delete[] tempArray;
	}
	void ShrinkToFit();

	Reference operator[](SizeType index) { return dataArray[index + 1]->getAddr(); }
	Reference At(SizeType index) { return dataArray[index + 1]->getAddr(); }
	Reference Front() { return dataArray[headIndex]->getAddr(); }
	Reference Back() { return dataArray[tailIndex - 1]->getAddr(); }
	void Data();

	void Assign(SizeType count, ValueType value)
	{
		Vector::SizeType i = 0;

		while (count != i)
		{
			PushBack(value);
			i++;
		}
	}
	void PushBack(ValueType value)
	{
		if (tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || dataArray == nullptr)
		{
			NodePtr* tempArray = static_cast<Vector::NodePtr*>(new NodePtr[arraySize + ALLOC_SIZE]);
			arraySize += ALLOC_SIZE;
			memset(tempArray, 0, arraySize * sizeof(Vector::NodePtr));

			if (dataArray == nullptr)
			{
				dataArray = tempArray;
				NodePtr leftNode = static_cast<NodePtr>(new Node<T>(true));
				NodePtr rightNode = static_cast<NodePtr>(new Node<T>(true));

				dataArray[0] = leftNode;
				dataArray[1] = rightNode;
			}
			else
			{
				memcpy(tempArray, dataArray, (arraySize - ALLOC_SIZE) * sizeof(NodePtr));
				delete[] dataArray;
				dataArray = tempArray;
			}
		}

		dataArray[tailIndex + 1] = dataArray[tailIndex];			//secure space

		NodePtr newNode = static_cast<NodePtr>(new Node<T>());										//Create new Node
		newNode->setValue(value);
		dataArray[tailIndex] = newNode;

		tailIndex += 1;
	}
	void PopBack()
	{
		if (Empty()) return;

		NodePtr deleteNode = dataArray[tailIndex - 1];
		dataArray[tailIndex - 1] = dataArray[tailIndex];
		memset(&dataArray[tailIndex], 0, sizeof(NodePtr));
		tailIndex -= 1;

		delete deleteNode;

		if (!((tailIndex + 1) % ALLOC_SIZE))
		{
			if (Empty()) return;

			NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[arraySize - ALLOC_SIZE]);
			arraySize -= ALLOC_SIZE;
			memset(tempArray, 0, arraySize * sizeof(NodePtr));
			memcpy(tempArray, dataArray, arraySize * sizeof(NodePtr));
		}
	}
	Iterator insert(ConstIterator& position, ValueType value)
	{
		if (tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || dataArray == nullptr)
		{
			NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[arraySize + ALLOC_SIZE]);
			arraySize += ALLOC_SIZE;
			memset(tempArray, 0, arraySize * sizeof(NodePtr));

			if (dataArray == nullptr)
			{
				dataArray = tempArray;
				NodePtr leftNode = static_cast<NodePtr>(new Node<T>(true));
				NodePtr rightNode = static_cast<NodePtr>(new Node<T>(true));

				dataArray[0] = leftNode;
				dataArray[1] = rightNode;
			}
			else
			{
				memcpy(tempArray, dataArray, (arraySize - ALLOC_SIZE) * sizeof(NodePtr));
				delete[] dataArray;
				dataArray = tempArray;
			}
		}

		int insertIndex = 1;

		while (true)
		{
			insertIndex++;
			if (dataArray[insertIndex]->getEdge())	exit(1);					// invalid iterator
			if (const_cast<Iterator&>(position).getNode() == dataArray[insertIndex]) break;
		}

		SizeType moveCount = tailIndex - insertIndex + 1;

		for (SizeType i = 0; i <moveCount; i++)											//secure space
			dataArray[tailIndex + 1 - i] = dataArray[tailIndex - i];


		NodePtr newNode = static_cast<NodePtr>(new Node<T>());													//Create new Node
		newNode->setValue(value);
		dataArray[insertIndex] = newNode;

		tailIndex += 1;
		return dataArray[insertIndex];
	}
	void Erase(ConstIterator& position)
	{
		if (Empty()) return;

		int deleteIndex = 0;

		while (true)
		{
			deleteIndex++;
			if (dataArray[deleteIndex]->getEdge())	exit(1);					// invalid iterator
			if (const_cast<Iterator&>(position).getNode() == dataArray[deleteIndex]) break;
		}

		NodePtr deleteNode = dataArray[deleteIndex];
		SizeType moveCount = tailIndex - deleteIndex + 1;

		for (SizeType i = deleteIndex; i < tailIndex; i++)
			dataArray[i] = dataArray[i + 1];
		memset(&dataArray[tailIndex], 0, sizeof(NodePtr));
		delete deleteNode;

		tailIndex -= 1;

		if (!((tailIndex + 1) % ALLOC_SIZE))
		{
			if (Empty()) return;

			NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[arraySize - ALLOC_SIZE]);
			arraySize -= ALLOC_SIZE;
			memset(tempArray, 0, arraySize * sizeof(NodePtr));
			memcpy(tempArray, dataArray, _arraySize * sizeof(NodePtr));
		}
	}
	void Swap(Vector& vector)
	{
		Vector tempVector;

		memcpy(&tempVector, this, sizeof(Vector));
		memcpy(this, &vector, sizeof(Vector));
		memcpy(&vector, &tempVector, sizeof(Vector));
	}
	void Clear()
	{
		for (Vector::SizeType i = 0; i < tailIndex; i++)
			delete dataArray[i];
		delete[] dataArray;

		dataArray = nullptr;
		headIndex = 1;
		tailIndex = 1;
		arraySize = 0;
	}
};