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

int main()
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



}


Node* CreateNode(int data)
{
	Node* new_node = new Node;
	int check = CheckPtr(new_node);
	if(check == PTR_NULL)
	{
		printf("new node ptr is NULL\n");
		return NULL;
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = data;
	return new_node;
}

Node* CreateAndLinkNode(Node* prev, Node* next, int data)
{
	Node* new_node = CreateNode(data);
	new_node->prev = prev;
	next->prev = new_node;
	new_node->next = next;
	prev->next = new_node;
	new_node->data = data;
	return new_node;
}

void PrintNode(Node* cur)
{
	printf("data %d\n", cur->data);
}

Node* InsertNodeAfter(Node* cur, int data)
{
	Node* new_node = CreateNode(data);
	cur->next = new_node;
	new_node->prev = cur;
	return new_node;
}

void Swap(Node* one, Node* two)
{
	int c = one->data;
	one->data = two->data;
	two->data = c;
}

Node* FindDataAfter(Node* begin, int data)
{
	Node* cur = begin;
	while(!cur)
	{
		if(cur->data == data)
			return cur;
		cur = cur->next;
	}
	return cur;
}
Node* FindDataBefore(Node* begin, int data)
{
	Node* cur = begin;
	while(!cur)
	{
		if(cur->data == data)
			return cur;
		cur = cur->prev;
	}
	return cur;
}
Node* FindEverywhere(Node* begin, int data)
{
	Node* cur_before = FindDataBefore(begin,data);
	if( cur_before!= NULL)
		return cur_before;
	Node* cur_after = FindDataAfter(begin,data);
	if( cur_after!= NULL)
		return cur_after;
	return NULL;
}

void PrintSince(Node* begin)
{
	Node* cur = begin;
	while(!cur)
	{
		PrintNode(cur);
		cur = cur->next;
	}
}

void DeleteNode(Node* cur)
{
	if(cur->next == NULL && cur->prev != NULL)
	{
		cur->prev->next = NULL;
		delete cur;
		printf("last node was deleted\n");
		return;
	}
	if(cur->prev == NULL && cur->next != NULL)
	{
		cur->next->prev = NULL;
		printf("first node was deleted\n");
		delete cur;
		return;
	}
	if(cur->prev == NULL && cur->next == NULL)
	{
		delete cur;	
		printf("lonely node was deleted\n");
		return;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;
	printf("Cur was deleted\n");
}

int CheckPtr(Node* cur)
{
	if(cur == NULL)
		return PTR_NULL;
	else
		return PTR_OK;
}
