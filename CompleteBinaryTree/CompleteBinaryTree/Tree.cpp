#include "Tree.h"

Tree::Tree() :arraySize(0), currentIndex(0), root(nullptr), indexArray(nullptr) {}

Tree::Tree(Tree& tree) : arraySize(0), currentIndex(0), root(nullptr), indexArray(nullptr)
{
	arraySize = tree.arraySize;
	currentIndex = tree.currentIndex;

	Node** tempArray = new Node*[arraySize];
	memset(tempArray, 0, arraySize * sizeof(Node*));
	indexArray = tempArray;

	for (int i = 0; i < currentIndex; i++)
		tempArray[i] = new Node(*tree.indexArray[i]);

	root = tempArray[0];
	reConstructTree();
}

Tree::~Tree()
{
	if (root != nullptr)
	{
		for (size_t index = currentIndex - 1; index > 0; index--)
			delete indexArray[index];
		delete[] indexArray;
	}
}

bool Tree::IsEmpty() const { return root == nullptr; }

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
	if (IsEmpty()) return;

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
}

bool Tree::Search(const int value)
{
	for (int i = 0; i < currentIndex; i++)
		if (indexArray[i]->_GetValue() == value)
			return true;
	return false;
}

void Tree::operator=(const Tree tree)
{
	//delete all Existing datas
	if (root != nullptr)
	{
		for (size_t index = currentIndex - 1; index > 0; index--)
			delete indexArray[index];
		delete[] indexArray;
	}

	arraySize = tree.arraySize;
	currentIndex = tree.currentIndex;

	Node** tempArray = new Node*[arraySize];
	memset(tempArray, 0, arraySize * sizeof(Node*));
	indexArray = tempArray;

	for (int i = 0; i < currentIndex; i++)
		tempArray[i] = new Node(*tree.indexArray[i]);

	root = tempArray[0];
	reConstructTree();
}