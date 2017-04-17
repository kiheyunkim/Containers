#include "Tree.h"

Tree::Tree() :currentIndex(0), root(nullptr), indexArray(nullptr) 
{
	indexArray = (Node **)malloc(sizeof(Node*) * ALLOCSIZE);
	memset(indexArray, 0, sizeof(indexArray));
}

Tree::~Tree()
{
	if (root != nullptr)
	{
		for (size_t index = currentIndex; index > 0; index--)
			free(&indexArray[index]);
	}

	free(indexArray);
}

bool Tree::isEmpty() { return root == nullptr; }

void Tree::Push(int value)
{
	if ((currentIndex % ALLOCSIZE == 0) || indexArray == nullptr)
	{
		size_t currentSize = sizeof(indexArray) / sizeof(indexArray[0]);

		Node** tempArray = (Node**)malloc(sizeof(Node*)*currentSize + ALLOCSIZE);
		memset(tempArray, 0, sizeof(tempArray));
		memcpy(tempArray, indexArray, sizeof(indexArray));
		free(indexArray);

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

	if (currentIndex % 2 == 1)	//if New Node is left Child Node 
		indexArray[currentIndex % 2]->_SetLeftNode(newNode);
	else						//if New Node is right Child Node
		indexArray[currentIndex % 2]->_SetRightNode(newNode);

	currentIndex += 1;
}

void Tree::Pop()
{
	if (isEmpty()) return;

	if (currentIndex == 0)
	{
		free(indexArray[currentIndex]);
		free(indexArray);
		indexArray = nullptr;
		root = nullptr;

		return;
	}

	free(indexArray[currentIndex]);
	currentIndex--;

	if (!(currentIndex%ALLOCSIZE))
	{
		size_t currentSize = sizeof(indexArray) / sizeof(indexArray[0]);

		Node** tempArray = (Node**)malloc(sizeof(Node*)*currentSize - ALLOCSIZE);
		memset(tempArray, 0, sizeof(tempArray));
		memcpy(tempArray, indexArray, sizeof(indexArray));
	}
}
