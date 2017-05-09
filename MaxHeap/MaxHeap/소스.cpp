#include "MaxHeapTree.h"

void main()
{
	MaxHeapTree tree;

	tree.Push(5);
	tree.print();
	tree.Push(1);
	tree.print();
	tree.Push(2);
	tree.print();
	tree.Push(12);
	tree.print();
	tree.Push(18);
	tree.print();

	tree.Pop();
	tree.print();
	tree.Pop();
	tree.print();
	tree.Pop();
	tree.print();
	tree.Pop();
	tree.print();
	tree.Pop();
	tree.print();
}