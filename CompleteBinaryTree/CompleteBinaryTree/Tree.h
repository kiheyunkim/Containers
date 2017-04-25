#pragma once

#define		ALLOCSIZE		6


class Node;

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
	bool isEmpty() const;
	void reConstructTree();
	void Push(const int value);
	void Pop();
	Node* Search(const int value) const;
	void print() const;
};

