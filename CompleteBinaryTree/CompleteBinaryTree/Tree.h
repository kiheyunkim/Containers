#pragma once
#include<stdlib.h>
#include<memory>
#include"Node.h"

#define		ALLOCSIZE		6

class Tree
{
private:
	size_t arraySize;
	int currentIndex;
	Node* root;
	Node** indexArray;

public:
	Tree();
	~Tree();
	bool isEmpty();
	void reConstructTree();
	void Push(int value);
	void Pop();
	void sort();
	void Search();
	void print()
	{
		for (int i = 0; i < currentIndex; i++)
			printf("%d ", indexArray[i]->_GetValue());
		printf("\n");
	}
};

