#include<iostream>
#include"Node.h"
#include "Tree.h"

Tree::Tree() :arraySize(0), currentIndex(0), root(nullptr), indexArray(nullptr) {}

Tree::~Tree()
{
	if (root != nullptr)
	{
		for (size_t index = currentIndex-1; index > 0; index--)
			delete indexArray[index];
		delete[] indexArray;
	}

}

bool Tree::isEmpty() const { return root == nullptr; }

void Tree::reConstructTree()
{
	for (int index = currentIndex-1; index > 0; index--)
	{
		if ((index + 1) % 2 == 0)									//if New Node is left Child Node 
			indexArray[((index + 1) / 2) - 1]->_SetLeftNode(indexArray[index]);
		else														//if New Node is right Child Node
			indexArray[((index + 1) / 2) - 1]->_SetRightNode(indexArray[index]);
	}
	root = indexArray[0];
}

void Tree::Push(const int value)
{
	if ((currentIndex % ALLOCSIZE == 0) || indexArray == nullptr)
	{

		Node** tempArray = new Node*[arraySize + ALLOCSIZE];
		arraySize += ALLOCSIZE;
		memset(tempArray, 0, arraySize * sizeof(Node*));

		if (indexArray != nullptr)
		{
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


	if (currentIndex == 0)		//return for first Node
	{
		root = *indexArray;
		currentIndex += 1;
		return;
	}

	if ((currentIndex + 1) % 2 == 0)	//if New Node is left Child Node 
		indexArray[((currentIndex +1) / 2) - 1]->_SetLeftNode(newNode);
	else								//if New Node is right Child Node
		indexArray[((currentIndex +1) / 2) - 1]->_SetRightNode(newNode);

	currentIndex += 1;
}

void Tree::Pop()
{
	if (isEmpty()) return;

	if (currentIndex == 0)
	{
		delete indexArray[currentIndex];
		delete[] indexArray;
		indexArray = nullptr;
		root = nullptr;
		return;
	}

	delete indexArray[currentIndex];
	currentIndex--;

	if (!(currentIndex%ALLOCSIZE))
	{

		Node** tempArray = new Node*[arraySize - ALLOCSIZE];
		arraySize -= ALLOCSIZE;
		memset(tempArray, 0, arraySize * sizeof(Node*));
		memcpy(tempArray, indexArray, arraySize * sizeof(Node*));
		reConstructTree();
		root = tempArray[0];
	}
}

Node* Tree::Search(const int val) const
{
	for (size_t index = 0; index < (size_t)currentIndex - 1; index++)
		if(indexArray[index]->_GetValue()==val)
			return indexArray[index];
	return NULL;
}

void Tree::print() const
{
	for (size_t index = 0; index < (size_t)currentIndex - 1; index++)
		std::cout << indexArray[index]->_GetValue() << " ";
	std::cout<<std::endl;
}