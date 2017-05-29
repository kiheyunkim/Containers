#include "Vector.h"

Vector::Vector() :_headIndex(1), _tailIndex(1), _arraySize(0), _dataArray(nullptr) {}

Vector::~Vector()
{
	for (size_t i = 0; i < _tailIndex; i++)
		delete _dataArray[i];
	delete[] _dataArray;
}

Vector::Iterator Vector::Begin() const { return static_cast<Iterator>(_dataArray[_headIndex]); }
Vector::Iterator Vector::End() const { return  static_cast<Iterator>(_dataArray[_tailIndex]); }
Vector::reverseIterator Vector::RBegin() const { return static_cast<Reverse_Iterator>(_dataArray[_tailIndex]); }
Vector::reverseIterator Vector::REnd() const { return static_cast<Reverse_Iterator>(_dataArray[_headIndex]); }
Vector::constIterator Vector::CBegin() const { return static_cast<constIterator>(_dataArray[_headIndex]); }
Vector::constIterator Vector::CEnd() const { return static_cast<constIterator>(_dataArray[_tailIndex]); }
Vector::constReverseIterator Vector::CrBegin() const { return static_cast<constReverseIterator>(_dataArray[_tailIndex]); }
Vector::constReverseIterator Vector::CrEnd() const { return static_cast<constReverseIterator>(_dataArray[_headIndex]); }
Vector::sizeType Vector::Size() const { return _tailIndex - _headIndex - 1; }
Vector::sizeType Vector::MaxSize() const { return _arraySize - 2; }
Vector::sizeType Vector::capacity() const { return _arraySize; }

bool Vector::Empty() const { return _headIndex == _tailIndex; }

void Vector::Reserve()
{
	NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[_arraySize]);
	memcpy(tempArray, _dataArray, _arraySize * sizeof(NodePtr));

	for (size_t index = _headIndex ; index <= _tailIndex; index++)
		_dataArray[index] = tempArray[_tailIndex - index];

	delete[] tempArray;
}

Vector::reference Vector::operator[](size_t index) { return _dataArray[index + 1]->_GetAddr(); }

Vector::reference Vector::at(size_t index) { return _dataArray[index + 1]->_GetAddr(); }

Vector::reference Vector::front() { return _dataArray[_headIndex]->_GetAddr(); }

Vector::reference Vector::back() { return _dataArray[_tailIndex - 1]->_GetAddr(); }

void Vector::Assign(size_t count, int value)
{
	size_t i = 0;

	while (count != i)
	{
		PushBack(value);
		i++;
	}
}

void Vector::PushBack(int value)
{
	if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
	{
		NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[_arraySize + ALLOC_SIZE]);
		_arraySize += ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(NodePtr));

		if (_dataArray == nullptr)
		{
			_dataArray = tempArray;
			NodePtr leftNode = static_cast<NodePtr>(new Node(true));
			NodePtr rightNode = static_cast<NodePtr>(new Node(true));

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

	NodePtr newNode = static_cast<NodePtr>(new Node());										//Create new Node
	newNode->_SetValue(value);
	_dataArray[_tailIndex] = newNode;

	_tailIndex += 1;
}

void Vector::PopBack()
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

Iterator Vector::insert(const Iterator& position, const int value)
{
	if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
	{
		NodePtr* tempArray = static_cast<NodePtr*>(new NodePtr[_arraySize + ALLOC_SIZE]);
		_arraySize += ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(NodePtr));

		if (_dataArray == nullptr)
		{
			_dataArray = tempArray;
			NodePtr leftNode = static_cast<NodePtr>(new Node(true));
			NodePtr rightNode = static_cast<NodePtr>(new Node(true));

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

	size_t moveCount = _tailIndex - insertIndex + 1;

	for (size_t i = 0; i <moveCount; i++)											//secure space
		_dataArray[_tailIndex + 1 - i] = _dataArray[_tailIndex - i];


	NodePtr newNode = static_cast<NodePtr>(new Node());													//Create new Node
	newNode->_SetValue(value);
	_dataArray[insertIndex] = newNode;

	_tailIndex += 1;
	return _dataArray[insertIndex];
}

void Vector::erase(const Iterator& position)
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
	size_t moveCount = _tailIndex - deleteIndex + 1;

	for (size_t i = deleteIndex; i < _tailIndex; i++)
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

void Vector::swap(Vector &vector)
{
	Vector tempVector;

	memcpy(&tempVector, this, sizeof(Vector));
	memcpy(this, &vector, sizeof(Vector));
	memcpy(&vector, &tempVector, sizeof(Vector));
}

void Vector::clear()
{
	for (size_t i = 0; i < _tailIndex; i++)
		delete _dataArray[i];
	delete[] _dataArray;

	_dataArray = nullptr;
	_headIndex = 1;
	_tailIndex = 1;
	_arraySize = 0;
}