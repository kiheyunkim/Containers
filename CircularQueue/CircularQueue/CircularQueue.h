#pragma once
#include<stdio.h>
#include<Windows.h>
#define MAX_LENGTH 1024

template<class T>
class CircularQueue
{
public:
	typedef T valueType;

private:
	T queueArray[MAX_LENGTH];
	int _headIndex;
	int _rearIndex;

public:
	CircularQueue();
	~CircularQueue();

public:
	int _GetHead();
	int _GetRear();
	bool Push(T data);
	bool Pop();
	bool isEmpty();

#ifdef  _DEBUG
	void print()
	{
		for (int i = _headIndex;i!=_rearIndex;)
		{
			printf("Index:%d : %d, ", i, queueArray[i]);
			i = ((i + 1) % MAX_LENGTH == 0) ? 0 : ++i;
		}
		printf("\n");
	}
#endif //  DEBUG
	
};

template<class T>
CircularQueue<T>::CircularQueue() :_headIndex(0), _rearIndex(0)
{
	memset(queueArray, 0, sizeof(queueArray));
}

template<class T>
CircularQueue<T>::~CircularQueue() {}

template<class T>
int CircularQueue<T>::_GetHead() { return _headIndex; }

template<class T>
int CircularQueue<T>::_GetRear() { return _rearIndex; }

template<class T>
bool CircularQueue<T>::Push(T data)
{
	if ((_rearIndex + 1) % MAX_LENGTH == _headIndex) return false;
	memcpy(&queueArray[_rearIndex], &data, sizeof(data));
	_rearIndex = (_rearIndex + 1 == MAX_LENGTH) ? 0 : ++_rearIndex;

	return true;
}

template<class T>
bool CircularQueue<T>::Pop()
{
	if (isEmpty()) return false;
	_headIndex = ((_headIndex + 1) == MAX_LENGTH) ? 0 : ++_headIndex;

	return true;
}

template<class T>
bool CircularQueue<T>::isEmpty() { return _headIndex == _rearIndex; }