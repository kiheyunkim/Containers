#include "Vector.h"



Vector::Vector() :_headIndex(1), _tailIndex(1), _arraySize(0), _dataArray(nullptr) {}

Vector::~Vector()
{
	for (size_t i = 0; i < _tailIndex; i++)
		delete _dataArray[i];
	delete[] _dataArray;
}

Vector::Iterator Vector::Begin() const { return &_dataArray[_headIndex]; }

Vector::Iterator Vector::End() const { return  &_dataArray[_tailIndex]; }

Vector::reverseIterator Vector::RBegin() const { return _dataArray[_tailIndex]; }

Vector::reverseIterator Vector::REnd() const { return _dataArray[_headIndex]; }

Vector::constIterator Vector::CBegin() const {return &_dataArray[_headIndex];}

Vector::constIterator Vector::CEnd() const {return &_dataArray[_tailIndex];}

Vector::constReverseIterator Vector::CrBegin() const {return _dataArray[_tailIndex];}

Vector::constReverseIterator Vector::CrEnd() const {return _dataArray[_headIndex];}

Vector::sizeType Vector::Size() const { return _tailIndex - _headIndex - 1; }

Vector::sizeType Vector::MaxSize() const { return _arraySize - 2; }

Vector::sizeType Vector::capacity() const { return _arraySize; }

bool Vector::Empty() const { return _headIndex == _tailIndex; }

void Vector::Reserve()
{
	Node** tempArray = new Node*[_arraySize];
	memcpy(tempArray, _dataArray, _arraySize * sizeof(Node*));

	for (size_t index = _headIndex ; index <= _tailIndex; index++)
		_dataArray[index] = tempArray[_tailIndex - index];

	delete[] tempArray;
}

Vector::reference Vector::operator[](size_t index) { return _dataArray[index + 1]->_GetAddr(); }

Vector::reference Vector::at(size_t index) { return _dataArray[index + 1]->_GetAddr(); }

Vector::reference Vector::front() { return _dataArray[_headIndex]->_GetAddr(); }

Vector::reference Vector::back() { return _dataArray[_tailIndex - 1]->_GetAddr(); }

void Vector::Assign(const size_t count, const int value)
{
	size_t i = 0;

	while (count != i)
	{
		PushBack(value);
		i++;
	}
}

void Vector::PushBack(const int value)
{
	if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
	{
		Node** tempArray = new Node*[_arraySize + ALLOC_SIZE];
		_arraySize += ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Node *));

		if (_dataArray == nullptr)
		{
			_dataArray = tempArray;
			Node* leftNode = new Node(true);
			Node* rightNode = new Node(true);

			_dataArray[0] = leftNode;
			_dataArray[1] = rightNode;
		}
		else
		{
			memcpy(tempArray, _dataArray, (_arraySize - ALLOC_SIZE) * sizeof(Node *));
			delete[] _dataArray;
			_dataArray = tempArray;
		}
	}

	_dataArray[_tailIndex + 1] = _dataArray[_tailIndex];			//secure space

	Node* newNode = new Node();										//Create new Node
	newNode->_SetValue(value);
	_dataArray[_tailIndex] = newNode;

	_tailIndex += 1;
}

void Vector::PopBack()
{
	if (Empty()) return;

	Node* deleteNode = _dataArray[_tailIndex - 1];
	_dataArray[_tailIndex - 1] = _dataArray[_tailIndex];
	memset(&_dataArray[_tailIndex], 0, sizeof(Node*));
	_tailIndex -= 1;

	delete deleteNode;

	if (!((_tailIndex + 1) % ALLOC_SIZE))
	{
		if (Empty()) return;

		Node** tempArray = new Node*[_arraySize - ALLOC_SIZE];
		_arraySize -= ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Node*));
		memcpy(tempArray, _dataArray, _arraySize * sizeof(Node*));
	}
}

Iterator Vector::insert(const Iterator position, const int value)
{
	if (_tailIndex % ALLOC_SIZE == ALLOC_SIZE - 2 || _dataArray == nullptr)
	{
		Node** tempArray = new Node*[_arraySize + ALLOC_SIZE];
		_arraySize += ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Node *));

		if (_dataArray == nullptr)
		{
			_dataArray = tempArray;
			Node* leftNode = new Node(true);
			Node* rightNode = new Node(true);

			_dataArray[0] = leftNode;
			_dataArray[1] = rightNode;
		}
		else
		{
			memcpy(tempArray, _dataArray, (_arraySize - ALLOC_SIZE) * sizeof(Node *));
			delete[] _dataArray;
			_dataArray = tempArray;
		}
	}
	
	int insertIndex = 1;
	
	while (true)
	{
		insertIndex++;
		if (_dataArray[insertIndex]->_GetEdge())	exit(1);					// invalid iterator
		if (position._GetNode() == &_dataArray[insertIndex]) break;	
	}

	size_t moveCount = _tailIndex - insertIndex + 1;

	for (size_t i = 0; i <moveCount; i++)											//secure space
		_dataArray[_tailIndex + 1 - i] = _dataArray[_tailIndex - i];


	Node* newNode = new Node();													//Create new Node
	newNode->_SetValue(value);
	_dataArray[insertIndex] = newNode;

	_tailIndex += 1;
	return &_dataArray[insertIndex];
}

void Vector::erase(const Iterator position)
{
	if (Empty()) return;

	int deleteIndex = 0;

	while (true)
	{
		deleteIndex++;
		if (_dataArray[deleteIndex]->_GetEdge())	exit(1);					// invalid iterator
		if (position._GetNode() == &_dataArray[deleteIndex]) break;
	}

	Node* deleteNode = _dataArray[deleteIndex];
	size_t moveCount = _tailIndex - deleteIndex + 1;

	for (size_t i = deleteIndex; i < _tailIndex; i++)
		_dataArray[i] = _dataArray[i + 1];
	memset(&_dataArray[_tailIndex], 0, sizeof(Node*));
	delete deleteNode;

	_tailIndex -= 1;

	if (!((_tailIndex + 1) % ALLOC_SIZE))
	{
		if (Empty()) return;

		Node** tempArray = new Node*[_arraySize - ALLOC_SIZE];
		_arraySize -= ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Node*));
		memcpy(tempArray, _dataArray, _arraySize * sizeof(Node*));
	}
}

void Vector::swap(Vector &vector)
{
	Vector vec;

	vec._headIndex = vector._headIndex;
	vec._tailIndex = vector._tailIndex;
	vec._arraySize = vector._arraySize;
	vec._dataArray = vector._dataArray;

	vector._headIndex = _headIndex;
	vector._tailIndex = _tailIndex;
	vector._arraySize = _arraySize;
	vector._dataArray = _dataArray;

	_headIndex = vec._headIndex;
	_tailIndex = vec._tailIndex;
	_arraySize = vec._arraySize;
	_dataArray = vec._dataArray;
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