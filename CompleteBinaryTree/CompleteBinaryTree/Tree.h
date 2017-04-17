#pragma once
#include<stdlib.h>
#include<memory>
#include"Node.h"

#define		ALLOCSIZE		6

class Tree
{
private:
	int currentIndex;
	Node* root;
	Node** indexArray;

public:
	Tree();
	~Tree();
	bool isEmpty();
	void Push(int value);
	void Pop();
	void sort();
	void Search();
	void print()
	{
		for (int i = 0; i < currentIndex; i++)
			printf("%d ", indexArray[i]->_GetValue());
	}
};

