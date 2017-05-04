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
	bool isEmpty() const;
	void reConstructTree();
	void Push(const int value);
	void Pop();
	bool Search(const int val);
	void print()
	{
		for (int i = 0; i < currentIndex; i++)
			printf("%d ", indexArray[i]->_GetValue());
		printf("\n");
	}
	void operator=(const Tree tree);
};

