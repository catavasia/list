#include <stdio.h>
#include <stdlib.h>
#include "node.h"

const int PTR_OK = 1;
const int PTR_NULL = -1;

struct List
{
	Node* head;
	size_t size;
};

List* CreateList(); //создание списка
void DeleteNodeFromList(List* list, Node* cur);
Node* Search(List* list, int data);
void AddToHeadList(List* list, Node* new_node);
void DeleteList(List* list);

int main()
{
	List* new_list = CreateList();
	
	Node* cur = Search(new_list, 7);
	printf("cur  %p\n", cur);
	printf("new_node %p\n", new_node);
	printf("a %p\n", a);
	printf("b %p\n", b);
	printf("list head %p\n", new_list->head);
	printf("b next  %p\n", b->next);
	//printf("OK\n");
	/*printf("size of int is %lu\n", sizeof(int));
	printf("size of pointer is %lu\n", sizeof(int*));
	printf("size of struct is %lu\n", sizeof(Node));
	List* list = CreateList();
	printf("list head %p\n", list->head);
	printf("list tail %p\n", list->tail);
	AddtoList(n,list);
	printf(" pointer is %p\n", n);
	printf("next  %p\n", n->next);
	printf("list tail %p\n", list->tail);
	printf("list head %p\n", list->head);
	printf("list tail %p\n", list->tail);
	//Swap(n,a);
	//PrintNode(n);
	//PrintNode(a);
	Node* b = CreateAndLinkNode(n, a, 55);
	PrintNode(b);
	Node* c = InsertAfter(b, 33);
	PrintNode(c);
	printf("%p\n", b->next);
	printf("%p\n", c);
	printf("%p\n", a->prev);
	printf("%p\n",c);
	DeleteNode(c);
	printf("%p\n", b->next);
	printf("%p\n", a);
	Node* h = InsertBefore(b, 88);
	PrintNode(h);
	printf("%p\n", h->next);
	printf("%p\n", b);
	*/
	//int check = CheckPtr(n);
	//printf("check is %d", check);
	return 0;
}

List* CreateList()
{
	List* new_list = new List;
	new_list->head = NULL;
	//list->tail = NULL;
	new_list->size = 0;
	printf("list was created\n");
	return new_list;
}

void AddToHeadList(List* list, Node* new_node)
{
	list->size++;
	//printf("new node is  %p\n", new_node);
	int check = CheckPtr(list->head);
	//printf("check %d\n", check);
	if( check == PTR_NULL)
	{
		list->head = new_node;
		//printf(" first node connected\n");
		return ;
	}
	else
	list->head->prev = new_node;
	//printf(" %p\n", list->head->prev);
	//printf(" list old head %p\n", list->head);
	new_node->next= list->head;
	//printf(" new node next %p\n", new_node.next);
	//printf(" new node next ok\n");
	list->head = new_node;
	//printf(" list new head %p\n", list->head);
}

void DeleteNodeFromList(List* list, Node* cur)
{
	list->size--;
	if(cur->next == NULL && cur->prev != NULL)
	{
		cur->prev->next = NULL;
		delete cur;
		printf("last node was deleted\n");
		return;
	}
	if(cur->prev == NULL && cur->next != NULL)
	{
		list->head = cur->next;
		cur->next->prev = NULL;
		printf("first node was deleted\n");
		delete cur;
		return;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;
	printf("Cur was deleted\n");
}

Node* Search(List* list, int data)
{
	Node* cur = list->head;
	while(!cur)
	{
		if(cur->data == data)
			return cur;
		cur = cur->next;
		printf("ptr is %p\n", cur);
	}
	return cur;
}

void DeleteList(List* list)
{
	Node* cur = list->head;
	while(cur!=NULL)
	{
		DeleteNodeFromList(list, cur);
		cur = cur->next;
	}
}
int CheckPtr(Node* cur)
{
	if(cur == NULL)
		return PTR_NULL;
	else
		return PTR_OK;
}
	

