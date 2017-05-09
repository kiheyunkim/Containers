#include<memory>
#include "MaxHeapTree.h"

void MaxHeapTree::_swap(Node* n1, Node* n2)
{
	int temp = n2->_GetValue();
	n2->_SetValue(n1->_GetValue());
	n1->_SetValue(temp);
}

MaxHeapTree::MaxHeapTree() :arraySize(0), currentIndex(0), root(nullptr), indexArray(nullptr) {}

MaxHeapTree::MaxHeapTree(MaxHeapTree& heap) : arraySize(0), currentIndex(0), root(nullptr), indexArray(nullptr)
{
	arraySize = heap.arraySize;
	currentIndex = heap.currentIndex;

	Node** tempArray = new Node*[arraySize];
	memset(tempArray, 0, arraySize * sizeof(Node*));
	indexArray = tempArray;

	for (int i = 0; i < currentIndex; i++)
		tempArray[i] = new Node(*heap.indexArray[i]);

	root = tempArray[0];
	reConstructTree();
}

MaxHeapTree::~MaxHeapTree()
{
	if (root != nullptr)
	{
		for (size_t index = currentIndex - 1; index > 0; index--)
			delete indexArray[index];
		delete[] indexArray;
	}
}

bool MaxHeapTree::IsEmpty() const { return root == nullptr; }

void MaxHeapTree::reConstructTree()
{
	for (int index = currentIndex - 1; index > 0; index--)
	{
		if ((index + 1) % 2 == 0)									//if New Node is left Child Node 
			indexArray[((index + 1) / 2) - 1]->_SetLeftNode(indexArray[index]);
		else														//if New Node is right Child Node
			indexArray[((index + 1) / 2) - 1]->_SetRightNode(indexArray[index]);
	}
	root = indexArray[0];
}

void MaxHeapTree::Push(const int value)
{
	//if is has not enough Memory reallocate Memory more
	if ((currentIndex % ALLOCSIZE == 0) || indexArray == nullptr)
	{
		Node** tempArray = new Node*[arraySize + ALLOCSIZE];
		arraySize += ALLOCSIZE;
		memset(tempArray, 0, arraySize * sizeof(Node*));

		if (indexArray != nullptr)			//if it already has array, copy data in original array
		{									//to new array
			memcpy(tempArray, indexArray, (arraySize - ALLOCSIZE) * sizeof(Node*));
			delete[] indexArray;
			indexArray = tempArray;
			reConstructTree();
		}
		else
			indexArray = tempArray;
	}


	Node* newNode = new Node();
	newNode->_SetValue(value);
	indexArray[currentIndex] = newNode;


	if (currentIndex == 0)													//return for first Node
	{
		root = *indexArray;
		currentIndex += 1;
		return;
	}

	if ((currentIndex + 1) % 2 == 0)										//if New Node is left Child Node 
		indexArray[((currentIndex + 1) / 2) - 1]->_SetLeftNode(newNode);
	else																	//if New Node is right Child Node
		indexArray[((currentIndex + 1) / 2) - 1]->_SetRightNode(newNode);

	int pos = currentIndex;

	while (pos >=0)															//heap sorting
	{
		if (indexArray[pos]->_GetValue() > indexArray[((pos + 1) / 2) - 1]->_GetValue())
		{
			_swap(indexArray[pos], indexArray[((pos + 1) / 2) - 1]);
			pos = ((currentIndex + 1) / 2) - 1;
		}
		else
			break;
	}

	currentIndex += 1;
}

void MaxHeapTree::Pop()
{
	if (IsEmpty()) return;

	_swap(indexArray[currentIndex - 1], root);

	//pop last Node
	delete indexArray[currentIndex - 1];

	//if final node is deleted, initialize all variables
	if (currentIndex == 1)
	{
		delete[] indexArray;
		indexArray = nullptr;
		currentIndex = 0;
		root = nullptr;
		arraySize = 0;
		return;

	}

	currentIndex--;

	if (currentIndex % 2 == 0)	//if pop Node is left Child Node
		indexArray[((currentIndex + 1) / 2) - 1]->_SetRightNode(nullptr);
	else						//if pop Node is right Child Node
		indexArray[((currentIndex + 1) / 2) - 1]->_SetLeftNode(nullptr);


	//Memoey Re-Allocate
	if ((currentIndex% ALLOCSIZE) == 0)
	{
		if (currentIndex == 0) return;
		Node** tempArray = new Node*[arraySize - ALLOCSIZE];
		arraySize -= ALLOCSIZE;
		memset(tempArray, 0, arraySize * sizeof(Node*));
		memcpy(tempArray, indexArray, arraySize * sizeof(Node*));

		delete[] indexArray;
		indexArray = tempArray;
		reConstructTree();
	}

	int pos = 0;

	while (pos < currentIndex)
	{

		if ((pos * 2) + 1 < pos&&  indexArray[pos]->_GetValue() < indexArray[(pos * 2) + 1]->_GetValue())
		{
			_swap(indexArray[pos], indexArray[(pos * 2) + 1]);
			pos = (pos * 2) + 1;
			continue;
		}
		else
		if ((pos * 2) + 2 < pos&&indexArray[pos]->_GetValue() < indexArray[(pos * 2) + 2]->_GetValue())
		{
			_swap(indexArray[pos], indexArray[(pos * 2) + 2]);
			pos = (pos * 2) + 2;
			continue;
		}
		else
			break;
	}
}

bool MaxHeapTree::Search(const int value)
{
	for (int i = 0; i < currentIndex; i++)
		if (indexArray[i]->_GetValue() == value)
			return true;
	return false;
}

void MaxHeapTree::operator=(const MaxHeapTree heap)
{
	//delete all Existing datas
	if (root != nullptr)
	{
		for (size_t index = currentIndex - 1; index > 0; index--)
			delete indexArray[index];
		delete[] indexArray;
	}

	arraySize = heap.arraySize;
	currentIndex = heap.currentIndex;

	Node** tempArray = new Node*[arraySize];
	memset(tempArray, 0, arraySize * sizeof(Node*));
	indexArray = tempArray;

	for (int i = 0; i < currentIndex; i++)
		tempArray[i] = new Node(*heap.indexArray[i]);

	root = tempArray[0];
	reConstructTree();
}