#pragma once
#include<malloc.h>
#include"Node.h"

#define		ALLOCSIZE		12

class Tree
{
private:
	int currentIndex;
	Node* root;
	Node** indexArray;

public:
	Tree();
	~Tree();
	void Push(int value);
};

Tree::Tree() :currentIndex(0), root(nullptr), indexArray(nullptr)
{
	indexArray = (Node **)malloc(sizeof(Node*) * ALLOCSIZE);
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

void Tree::Push(int value)
{
	if (currentIndex != 0 || !(currentIndex + 1) % ALLOCSIZE)
	{

	}
}
