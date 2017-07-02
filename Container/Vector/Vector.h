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

public:
	NodePtr* _dataArray;

private:
	unsigned int _headIndex;
	unsigned int _tailIndex;
	size_t _arraySize;

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
	Vector() :_headIndex(1), _tailIndex(1), _arraySize(0), _dataArray(nullptr) {}
	~Vector()
	{
		for (size_t i = 0; i < _tailIndex; i++)
			delete _dataArray[i];
		delete[] _dataArray;
	}

	Iterator Begin() const { return static_cast<Vector::Iterator>(_dataArray[_headIndex]); }
	Iterator End() const { return  static_cast<Vector::Iterator>(_dataArray[_tailIndex]); }
	ReverseIterator ReverseBegin() const { return static_cast<Vector::ReverseIterator>(_dataArray[_tailIndex]); }
	ReverseIterator ReverseEnd() const { return static_cast<Vector::ReverseIterator>(_dataArray[_headIndex]); }
	const Iterator ConstBegin() const { return static_cast<Vector::ConstIterator>(_dataArray[_headIndex]); }
	const Iterator ConstEnd() const { return static_cast<Vector::ConstIterator>(_dataArray[_tailIndex]); }
	const ReverseIterator ConstReverseBegin() const { return static_cast<ConstReverseIterator>(_dataArray[_tailIndex]); }
	const ReverseIterator ConstReverseEnd() const { return static_cast<ConstReverseIterator>(_dataArray[_headIndex]); }

	SizeType Size() const { return _tailIndex - _headIndex - 1; }
	SizeType MaxSize() const { return _arraySize - 2; }
	void Resize();
	SizeType Capacity() const { return _arraySize; }
	bool Empty() const { return _headIndex == _tailIndex; }
	void Reserve()
	{
		Vector::NodePtr* tempArray = static_cast<Vector::NodePtr*>(new Vector::NodePtr[_arraySize]);
		memcpy(tempArray, _dataArray, _arraySize * sizeof(Vector::NodePtr));

		for (Vector::SizeType index = _headIndex; index <= _tailIndex; index++)
			_dataArray[index] = tempArray[_tailIndex - index];

		delete[] tempArray;
	}
	void ShrinkToFit();

	Reference operator[](SizeType index) { return _dataArray[index + 1]->_GetAddr(); }
	Reference At(SizeType index) { return _dataArray[index + 1]->_GetAddr(); }
	Reference Front() { return _dataArray[_headIndex]->_GetAddr(); }
	Reference Back() { return _dataArray[_tailIndex - 1]->_GetAddr(); }
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
		if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
		{
			NodePtr* tempArray = static_cast<Vector::NodePtr*>(new NodePtr[_arraySize + ALLOC_SIZE]);
			_arraySize += ALLOC_SIZE;
			memset(tempArray, 0, _arraySize * sizeof(Vector::NodePtr));

			if (_dataArray == nullptr)
			{
				_dataArray = tempArray;
				NodePtr leftNode = static_cast<NodePtr>(new Node<T>(true));
				NodePtr rightNode = static_cast<NodePtr>(new Node<T>(true));

				_dataArray[0] = leftNode;
				_dataArray[1] = rightNode;
			}
			else
			{
				memcpy(tempArray, _dataArray, (_arraySize - ALLOC_SIZE) * sizeof(NodePtr));
				delete[] _dataArray;
				_dataArray = tempArray;
			}
		}

		_dataArray[_tailIndex + 1] = _dataArray[_tailIndex];			//secure space

		NodePtr newNode = static_cast<NodePtr>(new Node<T>());										//Create new Node
		newNode->_SetValue(value);
		_dataArray[_tailIndex] = newNode;

		_tailIndex += 1;
	}
	void PopBack()
	{
		if (Empty()) return;

		NodePtr deleteNode = _dataArray[_tailIndex - 1];
		_dataArray[_tailIndex - 1] = _dataArray[_tailIndex];
		memset(&_dataArray[_tailIndex], 0, sizeof(NodePtr));
		_tailIndex -= 1;

		delete deleteNode;

		if (!((_tailIndex + 1) % ALLOC_SIZE))
		{
			if (Empty()) return;

			NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[_arraySize - ALLOC_SIZE]);
			_arraySize -= ALLOC_SIZE;
			memset(tempArray, 0, _arraySize * sizeof(NodePtr));
			memcpy(tempArray, _dataArray, _arraySize * sizeof(NodePtr));
		}
	}
	Iterator insert(ConstIterator& position, ValueType value)
	{
		if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
		{
			NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[_arraySize + ALLOC_SIZE]);
			_arraySize += ALLOC_SIZE;
			memset(tempArray, 0, _arraySize * sizeof(NodePtr));

			if (_dataArray == nullptr)
			{
				_dataArray = tempArray;
				NodePtr leftNode = static_cast<NodePtr>(new Node<T>(true));
				NodePtr rightNode = static_cast<NodePtr>(new Node<T>(true));

				_dataArray[0] = leftNode;
				_dataArray[1] = rightNode;
			}
			else
			{
				memcpy(tempArray, _dataArray, (_arraySize - ALLOC_SIZE) * sizeof(NodePtr));
				delete[] _dataArray;
				_dataArray = tempArray;
			}
		}

		int insertIndex = 1;

		while (true)
		{
			insertIndex++;
			if (_dataArray[insertIndex]->_GetEdge())	exit(1);					// invalid iterator
			if (const_cast<Iterator&>(position)._GetNode() == _dataArray[insertIndex]) break;
		}

		SizeType moveCount = _tailIndex - insertIndex + 1;

		for (SizeType i = 0; i <moveCount; i++)											//secure space
			_dataArray[_tailIndex + 1 - i] = _dataArray[_tailIndex - i];


		NodePtr newNode = static_cast<NodePtr>(new Node<T>());													//Create new Node
		newNode->_SetValue(value);
		_dataArray[insertIndex] = newNode;

		_tailIndex += 1;
		return _dataArray[insertIndex];
	}
	void Erase(ConstIterator& position)
	{
		if (Empty()) return;

		int deleteIndex = 0;

		while (true)
		{
			deleteIndex++;
			if (_dataArray[deleteIndex]->_GetEdge())	exit(1);					// invalid iterator
			if (const_cast<Iterator&>(position)._GetNode() == _dataArray[deleteIndex]) break;
		}

		NodePtr deleteNode = _dataArray[deleteIndex];
		SizeType moveCount = _tailIndex - deleteIndex + 1;

		for (SizeType i = deleteIndex; i < _tailIndex; i++)
			_dataArray[i] = _dataArray[i + 1];
		memset(&_dataArray[_tailIndex], 0, sizeof(NodePtr));
		delete deleteNode;

		_tailIndex -= 1;

		if (!((_tailIndex + 1) % ALLOC_SIZE))
		{
			if (Empty()) return;

			NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[_arraySize - ALLOC_SIZE]);
			_arraySize -= ALLOC_SIZE;
			memset(tempArray, 0, _arraySize * sizeof(NodePtr));
			memcpy(tempArray, _dataArray, _arraySize * sizeof(NodePtr));
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
		for (Vector::SizeType i = 0; i < _tailIndex; i++)
			delete _dataArray[i];
		delete[] _dataArray;

		_dataArray = nullptr;
		_headIndex = 1;
		_tailIndex = 1;
		_arraySize = 0;
	}
};