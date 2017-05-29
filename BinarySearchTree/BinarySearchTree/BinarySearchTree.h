#pragma once
class Node;

class BinarySearchTree
{
private:
	Node* _root;
		
private:
	bool _isThere(int _value) const;
	Node* _findReplaceNode(const Node* node) const;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Push(int value);
	Node* Pop(int value);
};

