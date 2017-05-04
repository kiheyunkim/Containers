#include "Vector.h"



Vector::Vector() :_head(nullptr), _tail(nullptr), _arraySize(0), _dataArray(nullptr), _currentIndex(0) {}

Vector::~Vector(){}

Iterator Vector::Begin() const { return _head; }

Iterator Vector::End() const { return _tail; }

Reverse_Iterator Vector::RBegin() const { return _tail; }

Reverse_Iterator Vector::REnd() const { return _head; }

const Iterator Vector::CBegin() const {return _head;}

const Iterator Vector::CEnd() const {return _tail;}

const Reverse_Iterator Vector::CrBegin() const {return _tail;}

const Reverse_Iterator Vector::CrEnd() const {return _head;}

void Vector::Assign(size_t count, const int value)
{
	
}

void Vector::push_back(const int value)
{
	if (_currentIndex % ALLOC_SIZE == 0 || _dataArray == nullptr)
	{
		Node** tempArray = new Node*[_arraySize+ALLOC_SIZE];
		_arraySize += ALLOC_SIZE;
		memset(tempArray, 0, _arraySize * sizeof(Node *));

		if (_dataArray == nullptr)
			_dataArray = tempArray;
		else
		{
			memcpy(tempArray, tempArray, (_arraySize - ALLOC_SIZE) * sizeof(Node *));
			delete[] _dataArray;
			_dataArray = tempArray;
		}
	}

	Node *newNode = new Node();
	newNode->_SetValue(value);

	_dataArray[_currentIndex] = newNode;
	_currentIndex += 1;
}

