#pragma once
class Node;

class BinarySearchTree
{
private:
	Node* _root;
		
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Push(const int value);
	Node* Pop(const int value);
};

