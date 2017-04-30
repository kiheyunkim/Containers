#pragma once
class Node;

class BinarySearchTree
{
private:
	Node* _root;
		
private:
	bool _isThere(const int _value) const;

public:
	BinarySearchTree();
	~BinarySearchTree();
	void Push(const int value);
	Node* Pop(const int value);
};

