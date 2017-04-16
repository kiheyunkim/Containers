#include<stdio.h>
#include"CircularQueue.h"
void main()
{
	CircularQueue<int> Cqueue;

	printf("%d\n", Cqueue.Push(1));
	printf("%d\n", Cqueue.Push(2));
	printf("%d\n", Cqueue.Push(3));
	printf("%d\n", Cqueue.Push(4));
	printf("%d\n", Cqueue.Push(5));
	printf("%d\n", Cqueue.Push(6));
	Cqueue.print();
	Cqueue.Pop();
	printf("%d\n", Cqueue.Push(7));
	Cqueue.print();
}