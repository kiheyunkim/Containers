#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
class Node
{
private:
	int value;
	Node *rightChild;
	Node *leftChild;

public:
	typedef int value_type;

public:
	Node();
	~Node();
	value_type GetValue() const;
	value_type* GetAddr();
	Node *GetLeftChildNode() const;
	Node *GetRightChildNode() const;
	void SetValue(value_type value);
	void SetLeftChildNode(const Node* ptr);
	void SetRightChildNode(const Node* ptr);

public:
	Node& operator=(const Node& node);
	Node& operator+(int value);
	Node& operator-(int value);
	void operator+=(int value);
	void operator-=(int value);
	bool operator==(const Node& node);
	bool operator!=(const Node& node);
};

#endif // !_NODE_H_