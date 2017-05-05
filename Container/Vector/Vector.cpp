#include "Vector.h"



Vector::Vector() :_head(nullptr), _tail(nullptr), _arraySize(0), _dataArray(nullptr), _currentIndex(0) {}

Vector::~Vector()
{
	for (int i = 0; i < _currentIndex - 1; i++)
		delete _dataArray[i];
	delete[] _dataArray;
}

Vector::Iterator Vector::Begin() const { return _head; }

Vector::Iterator Vector::End() const { return _tail; }

Vector::Reverse_Iterator Vector::RBegin() const { return _tail; }

Vector::Reverse_Iterator Vector::REnd() const { return _head; }

const Vector::Iterator Vector::CBegin() const {return _head;}

const Vector::Iterator Vector::CEnd() const {return _tail;}

const Vector::Reverse_Iterator Vector::CrBegin() const {return _tail;}

const Vector::Reverse_Iterator Vector::CrEnd() const {return _head;}

size_t Vector::Size() const { return _currentIndex + 1; }

size_t Vector::MaxSize() const { return _arraySize - 1; }



void Vector::Assign(size_t count, const int value)
{
	
}

void Vector::push_back(const int value)
{
	if (_currentIndex % ALLOC_SIZE == ALLOC_SIZE - 1 || _dataArray == nullptr)
	{
		Node** tempArray = new Node*[_arraySize + ALLOC_SIZE];
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




	_tail = _dataArray[_currentIndex];

	_currentIndex += 1;
}

