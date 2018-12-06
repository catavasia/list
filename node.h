#include <stdio.h>
#include <stdlib.h>
const int PTR_OK = 1;
const int PTR_NULL = -1;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

int CheckPtr(Node* cur);
Node* CreateAndLinkNode(Node* prev, Node* next , int data); // вставка между узлами
Node* CreateNode(int data);
void PrintNode(Node* cur);
Node* InsertNodeAfter(Node* cur, int data);
void Swap(Node* one, Node* two);
Node* FindDataAfter(Node* begin, int data);
Node* FindDataBefore(Node* begin, int data);
Node* FindEverywhere(Node* begin, int data);
void PrintSince(Node* begin);
void DeleteNode(Node* cur);

/*int main()
{
	Node* a = CreateNode(34);
	printf("new node was created, data = %d\n", a->data);
	Node* b = CreateNode(14);
	Node* c = CreateAndLinkNode(a, b, 16);
	PrintNode(c);
	Node* d = InsertNodeAfter(c, 13);
	printf("d prev = %p c = %p\n", d->prev, c);
	DeleteNode(a);
	Node* g = CreateNode(10);
	DeleteNode(g);



}*/


#include "node.cpp"
