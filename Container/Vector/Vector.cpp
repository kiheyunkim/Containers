#include "Vector.h"
	

Vector::Vector() :_headIndex(1), _tailIndex(1), _arraySize(0), _dataArray(nullptr) {}

Vector::~Vector()
{
	for (size_t i = 0; i < _tailIndex; i++)
		delete _dataArray[i];
	delete[] _dataArray;
}

Vector::Iterator Vector::Begin() const { return static_cast<Vector::Iterator>(_dataArray[_headIndex]); }
Vector::Iterator Vector::End() const { return  static_cast<Vector::Iterator>(_dataArray[_tailIndex]); }
Vector::ReverseIterator Vector::ReverseBegin() const { return static_cast<Vector::ReverseIterator>(_dataArray[_tailIndex]); }
Vector::ReverseIterator Vector::ReverseEnd() const { return static_cast<Vector::ReverseIterator>(_dataArray[_headIndex]); }
Vector::ConstIterator Vector::ConstBegin() const { return static_cast<Vector::ConstIterator>(_dataArray[_headIndex]); }
Vector::ConstIterator Vector::ConstEnd() const { return static_cast<Vector::ConstIterator>(_dataArray[_tailIndex]); }
Vector::ConstReverseIterator Vector::ConstReverseBegin() const { return static_cast<ConstReverseIterator>(_dataArray[_tailIndex]); }
Vector::ConstReverseIterator Vector::ConstReverseEnd() const { return static_cast<ConstReverseIterator>(_dataArray[_headIndex]); }
Vector::SizeType Vector::Size() const { return _tailIndex - _headIndex - 1; }
Vector::SizeType Vector::MaxSize() const { return _arraySize - 2; }
Vector::SizeType Vector::Capacity() const { return _arraySize; }

bool Vector::Empty() const { return _headIndex == _tailIndex; }

void Vector::Reserve()
{
	Vector::NodePtr* tempArray = static_cast<Vector::NodePtr*>(new Vector::NodePtr[_arraySize]);
	memcpy(tempArray, _dataArray, _arraySize * sizeof(Vector::NodePtr));

	for (Vector::SizeType index = _headIndex ; index <= _tailIndex; index++)
		_dataArray[index] = tempArray[_tailIndex - index];

	delete[] tempArray;
}

Vector::Reference Vector::operator[](Vector::SizeType index) { return _dataArray[index + 1]->_GetAddr(); }

Vector::Reference Vector::At(Vector::SizeType index) { return _dataArray[index + 1]->_GetAddr(); }

Vector::Reference Vector::Front() { return _dataArray[_headIndex]->_GetAddr(); }

Vector::Reference Vector::Back() { return _dataArray[_tailIndex - 1]->_GetAddr(); }

void Vector::Assign(Vector::SizeType count, Vector::ValueType value)
{
	Vector::SizeType i = 0;

	while (count != i)
	{
		PushBack(value);
		i++;
	}
}

void Vector::PushBack(Vector::ValueType value)
{
	if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
	{
		Vector::NodePtr* tempArray = static_cast<Vector::NodePtr*>(new Vector::NodePtr[_arraySize + ALLOC_SIZE]);
		_arraySize += ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Vector::NodePtr));

		if (_dataArray == nullptr)
		{
			_dataArray = tempArray;
			Vector::NodePtr leftNode = static_cast<Vector::NodePtr>(new Node(true));
			Vector::NodePtr rightNode = static_cast<Vector::NodePtr>(new Node(true));

			_dataArray[0] = leftNode;
			_dataArray[1] = rightNode;
		}
		else
		{
			memcpy(tempArray, _dataArray, (_arraySize - ALLOC_SIZE) * sizeof(Vector::NodePtr));
			delete[] _dataArray;
			_dataArray = tempArray;
		}
	}

	_dataArray[_tailIndex + 1] = _dataArray[_tailIndex];			//secure space

	Vector::NodePtr newNode = static_cast<Vector::NodePtr>(new Node());										//Create new Node
	newNode->_SetValue(value);
	_dataArray[_tailIndex] = newNode;

	_tailIndex += 1;
}

void Vector::PopBack()
{
	if (Empty()) return;

	Vector::NodePtr deleteNode = _dataArray[_tailIndex - 1];
	_dataArray[_tailIndex - 1] = _dataArray[_tailIndex];
	memset(&_dataArray[_tailIndex], 0, sizeof(Vector::NodePtr));
	_tailIndex -= 1;

	delete deleteNode;

	if (!((_tailIndex + 1) % ALLOC_SIZE))
	{
		if (Empty()) return;

		Vector::NodePtr* tempArray = static_cast<Vector::NodePtr*>(new Vector::NodePtr[_arraySize - ALLOC_SIZE]);
		_arraySize -= ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Vector::NodePtr));
		memcpy(tempArray, _dataArray, _arraySize * sizeof(Vector::NodePtr));
	}
}

Iterator Vector::insert(ConstIterator& position, Vector::ValueType value)
{
	if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
	{
		Vector::NodePtr* tempArray = static_cast<Vector::NodePtr*>(new Vector::NodePtr[_arraySize + ALLOC_SIZE]);
		_arraySize += ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Vector::NodePtr));

		if (_dataArray == nullptr)
		{
			_dataArray = tempArray;
			Vector::NodePtr leftNode = static_cast<Vector::NodePtr>(new Node(true));
			Vector::NodePtr rightNode = static_cast<Vector::NodePtr>(new Node(true));

			_dataArray[0] = leftNode;
			_dataArray[1] = rightNode;
		}
		else
		{
			memcpy(tempArray, _dataArray, (_arraySize - ALLOC_SIZE) * sizeof(Vector::NodePtr));
			delete[] _dataArray;
			_dataArray = tempArray;
		}
	}
	
	int insertIndex = 1;
	
	while (true)
	{
		insertIndex++;
		if (_dataArray[insertIndex]->_GetEdge())	exit(1);					// invalid iterator
		if (const_cast<Vector::Iterator&>(position)._GetNode() == _dataArray[insertIndex]) break;
	}

	Vector::SizeType moveCount = _tailIndex - insertIndex + 1;

	for (Vector::SizeType i = 0; i <moveCount; i++)											//secure space
		_dataArray[_tailIndex + 1 - i] = _dataArray[_tailIndex - i];


	Vector::NodePtr newNode = static_cast<Vector::NodePtr>(new Node());													//Create new Node
	newNode->_SetValue(value);
	_dataArray[insertIndex] = newNode;

	_tailIndex += 1;
	return _dataArray[insertIndex];
}

void Vector::Erase(ConstIterator& position)
{
	if (Empty()) return;

	int deleteIndex = 0;

	while (true)
	{
		deleteIndex++;
		if (_dataArray[deleteIndex]->_GetEdge())	exit(1);					// invalid iterator
		if (const_cast<Vector::Iterator&>(position)._GetNode() == _dataArray[deleteIndex]) break;
	}

	Vector::NodePtr deleteNode = _dataArray[deleteIndex];
	Vector::SizeType moveCount = _tailIndex - deleteIndex + 1;

	for (Vector::SizeType i = deleteIndex; i < _tailIndex; i++)
		_dataArray[i] = _dataArray[i + 1];
	memset(&_dataArray[_tailIndex], 0, sizeof(Vector::NodePtr));
	delete deleteNode;

	_tailIndex -= 1;

	if (!((_tailIndex + 1) % ALLOC_SIZE))
	{
		if (Empty()) return;

		Vector::NodePtr* tempArray = static_cast<Vector::NodePtr*>(new Vector::NodePtr[_arraySize - ALLOC_SIZE]);
		_arraySize -= ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Vector::NodePtr));
		memcpy(tempArray, _dataArray, _arraySize * sizeof(Vector::NodePtr));
	}
}

void Vector::Swap(Vector &vector)
{
	Vector tempVector;

	memcpy(&tempVector, this, sizeof(Vector));
	memcpy(this, &vector, sizeof(Vector));
	memcpy(&vector, &tempVector, sizeof(Vector));
}

void Vector::Clear()
{
	for (Vector::SizeType i = 0; i < _tailIndex; i++)
		delete _dataArray[i];
	delete[] _dataArray;

	_dataArray = nullptr;
	_headIndex = 1;
	_tailIndex = 1;
	_arraySize = 0;
}