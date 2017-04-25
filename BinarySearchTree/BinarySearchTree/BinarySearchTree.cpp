#include "BinarySearchTree.h"
#include "Node.h"


BinarySearchTree::BinarySearchTree() :_root(nullptr) {}

BinarySearchTree::~BinarySearchTree(){}

void BinarySearchTree::Push(const int _value)
{
	if (_root == nullptr)
	{
		Node* newNode = new Node();
		newNode->_SetValue(_value);
		_root=newNode;
		return;
	}
	
	Node* newNode = new Node();
	newNode->_SetValue(_value);
	Node* cur = _root;

	while (true)
	{
		if (_value >= cur->_GetValue())
		{
			if (cur->_GetRightNode() == nullptr)
			{
				cur->_SetRightNode(newNode);
				return;
			}
			else
			{
				cur=cur->_GetRightNode();
				continue;
			}
		}
		if (_value < cur->_GetValue())
		{
			if (cur->_GetLeftNode() == nullptr)
			{
				cur->_SetLeftNode(newNode);
				return;
			}
			else
			{
				cur=cur->_GetLeftNode();
				continue;
			}
		}
	}
}