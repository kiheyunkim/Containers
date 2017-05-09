#pragma once
#include<stdlib.h>
#include<memory>
#include"Node.h"

#define		ALLOCSIZE		12

class Tree
{
private:
	Node* root;
	Node** indexArray;
	size_t arraySize;
	int currentIndex;

private:
	void reConstructTree();

public:
	Tree();
	Tree(Tree& tree);
	~Tree();
	bool IsEmpty() const;
	void Push(const int value);
	void Pop();
	bool Search(const int val);
	
	void print()
	{
		if (root == nullptr) return;
		for (int i = 0; i < currentIndex; i++)
			printf("%d ", indexArray[i]->_GetValue());
		printf("\n");
	}

	void operator=(const Tree tree);
};

