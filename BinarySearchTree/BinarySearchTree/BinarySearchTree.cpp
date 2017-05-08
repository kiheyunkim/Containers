#include "BinarySearchTree.h"
#include<iostream>
#include "Node.h"


BinarySearchTree::BinarySearchTree() :_root(nullptr) {}

BinarySearchTree::~BinarySearchTree()
{
	while (_root != nullptr)
		std::cout << Pop(_root->_GetValue())->_GetValue() << " ";
	std::cout << std::endl;
}

bool BinarySearchTree::_isThere(const int _value) const
{
	if (_root == nullptr) return false;

	Node* cur = _root;
	while (cur != nullptr)
	{
		if (cur->_GetValue() == _value)
			return true;

		if (cur->_GetValue() > _value)
			cur = cur->_GetLeftNode();
		else
			cur = cur->_GetRightNode();
	}
	return false;
}

void BinarySearchTree::Push(const int _value)
{
	if (_isThere(_value)) return;

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

Node* BinarySearchTree::Pop(const int _value)
{
	if (!_isThere(_value)) return nullptr;

	Node* prevCur = _root;
	Node* cur = _root;
	Node* returnNode = nullptr;
	
	while (cur->_GetValue() != _value)
	{
		prevCur = cur;
		if (cur->_GetValue() > _value)
			cur = cur->_GetLeftNode();
		else
			cur = cur->_GetRightNode();
	}

	if (cur == _root&&cur->_GetLeftNode() == nullptr&&cur->_GetRightNode() == nullptr)
	{
		_root = nullptr;
		returnNode = cur;
		delete cur;
		return returnNode;
	}

	if (prevCur->_GetLeftNode() == cur)
	{
		if (cur->_GetLeftNode() == nullptr&&cur->_GetRightNode() == nullptr)
		{
			prevCur->_SetLeftNode(nullptr);
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		Node* replaceNode = cur;

		if (cur->_GetRightNode() == nullptr)
		{
			cur = cur->_GetLeftNode();

			if (cur->_GetLeftNode() == nullptr&&cur->_GetRightNode() == nullptr)
			{

			}



		}




	}





	

	if (cur == _root && cur->_GetLeftNode() == nullptr && cur->_GetRightNode() == nullptr)		//Only in root
	{
		_root = nullptr;
		returnNode = cur;
		delete cur;
		return returnNode;
	}

	if (prevCur->_GetRightNode() == cur)														
	{
		if (cur->_GetLeftNode() == nullptr && cur->_GetRightNode() == nullptr)					//terminal node;
		{
			prevCur->_SetRightNode(nullptr);
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		if (cur->_GetRightNode() == nullptr)													//1-Dimen Order
		{
			prevCur->_SetRightNode(cur->_GetLeftNode());
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		if (cur->_GetLeftNode() == nullptr)														//1-Dimen Order
		{
			prevCur->_SetRightNode(cur->_GetRightNode());
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		Node* replacePos = cur;										 							//2-Dimen Order
		cur = cur->_GetLeftNode();

		if (cur->_GetRightNode() == nullptr)
		{
			replacePos->_SetLeftNode(cur->_GetLeftNode());
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		while (cur->_GetRightNode() != nullptr)
		{
			prevCur = cur;
			cur = cur->_GetRightNode();
		}

		replacePos->_SetValue(cur->_GetValue());
		prevCur->_SetRightNode(nullptr);
		returnNode = cur;
		delete cur;
		return returnNode;
	}

	if (prevCur->_GetLeftNode() == cur)
	{
		if (cur->_GetLeftNode() == nullptr && cur->_GetRightNode() == nullptr)			//terminal node;
		{
			prevCur->_SetLeftNode(nullptr);
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		if (cur->_GetRightNode() == nullptr)											//1-Dimen Order
		{
			prevCur->_SetLeftNode(cur->_GetLeftNode());
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		if (cur->_GetLeftNode() == nullptr)												//1-Dimen Order
		{
			prevCur->_SetLeftNode(cur->_GetRightNode());
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		Node* replacePos = cur;										 					//2-Dimen Order
		cur = cur->_GetLeftNode();


		if (cur->_GetRightNode() == nullptr)
		{
			replacePos->_SetLeftNode(cur->_GetLeftNode());
			returnNode = cur;
			delete cur;
			return returnNode;
		}

		while (cur->_GetRightNode() != nullptr)
		{
			prevCur = cur;
			cur = cur->_GetRightNode();
		}

		replacePos->_SetValue(cur->_GetValue());
		prevCur->_SetRightNode(nullptr);
		returnNode = cur;
		delete cur;
		return returnNode;
	}

	return nullptr;
}