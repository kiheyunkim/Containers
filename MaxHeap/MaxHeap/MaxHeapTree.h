#pragma once
#include<iostream>
#include"Node.h"

#define		ALLOCSIZE		12


class MaxHeapTree
{
private:
	size_t		arraySize;
	int			currentIndex;
	Node*		root;
	Node**		indexArray;

private:
	void	_swap(Node* n1, Node* n2);
	void	_reConstructTree();

public:
	MaxHeapTree();
	MaxHeapTree(MaxHeapTree& heap);
	~MaxHeapTree();
	bool	IsEmpty() const;
	void	Push(const int value);
	void	Pop();
	bool	Search(const int val);

public:
	void	operator=(const MaxHeapTree tree);

	void print()
	{
		for (int i = 0; i < currentIndex; i++)
			std::cout << indexArray[i]->_GetValue() << " ";
		std::cout << std::endl;
	}
};

