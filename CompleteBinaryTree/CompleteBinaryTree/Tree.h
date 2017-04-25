#pragma once
#include<stdlib.h>
#include<memory>
#include"Node.h"

#define		ALLOCSIZE		12

class Tree
{
private:
	size_t arraySize;
	int currentIndex;
	Node* root;
	Node** indexArray;

public:
	Tree();
	Tree(Tree& tree);
	~Tree();
	bool isEmpty();
	void reConstructTree();
	void Push(int value);
	void Pop();
	bool Search(int val);
	void print()
	{
		for (int i = 0; i < currentIndex; i++)
			printf("%d ", indexArray[i]->_GetValue());
		printf("\n");
	}
	void operator=(Tree tree);
};

