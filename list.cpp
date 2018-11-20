#include <stdio.h>
#include <stdlib.h>

#define E(code, name); const int ERROR_##name = code;
#define O(code, name); const int OK_##name = code;
const int PTR_OK = 1;
const int PTR_NULL = -1;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

struct List
{
	Node* head;
	//Node* tail;
	size_t size;
};

Node* CreateAndLinkNode(Node* , Node* , int ); // вставка между узлами
List* CreateList(); //создание списка
int CheckPtr(Node* cur);
void PrintNode(Node* cur);
//void DeleteNode( Node* cur);
Node* CreateNode(int);
Node* AddToHeadList(List* list, int data); // вставляет в начало списка
Node* InsertNodeAfter(Node* cur, int data);
void DeleteNodeBetween(Node* cur);
void DeleteNodeFromHead(List* list, Node* cur);
void DeleteNodeFromTail(Node* cur);
void DeleteNode(List* list, Node* cur);
Node* Search(List* list, int data);
/*
Node* InsertNodeBefore(Node* cur, int data);
void Swap(Node* one, Node* two);
Node* FindDataAfter(Node* begin, int data);
Node* FindDataBefore(Node* begin, int data);
Node* FindEverywhere(Node* begin, int data);
//void InsertInHead(Node* cur, List* list);
int CheckPtr(Node* cur);
int NodeIndex(int data);
void PrintSince(Node* begin);
*/
int main()
{
	List* new_list = CreateList();
	Node* new_node = AddToHeadList(new_list, 6);
	Node* a = AddToHeadList(new_list, 7);
	Node* b = AddToHeadList(new_list, 9);
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

Node* AddToHeadList(List* list, int data)
{
	list->size++;
	Node* new_node = CreateNode(data);
	int check = CheckPtr(list->head);
	if( check == PTR_NULL)
	{
		list->head = new_node;
		return new_node;
	}
	list->head->prev = new_node;
	new_node->next = list->head;
	list->head = new_node;
	return new_node;
}
/*
Node* AddToTailList(List* list, int data)
{
	int check = CheckPtr(list->head);
	if( check == PTR_NULL)
	{
		Node* new_node = CreateNode(data);
		list->head = new_node;
		return new_node;
	}
}
*/	
Node* CreateNode(int data)
{
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = data;
	return new_node;
}


/*
Node* InsertNodeAfter(Node* cur, int data)
{
	Node* new_node = CreateNode(data);
	cur->next = new_node;
	new_node->prev = cur;
	return new_node;
}
*/
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
	printf("%d\n", cur->data);
}
/*
void PrintSince(Node* begin)
{
	Node* cur = begin;
	while(!cur)
	{
		PrintNode(cur);
		cur = cur->next;
	}
}
*/

void DeleteNodeFromHead(List* list, Node* cur)
{
	list->size--;
	list->head = cur->next;
	cur->next->prev = NULL;
	free(cur);
}

void DeleteNodeFromTail(Node* cur)
{
	cur->prev->next = NULL;
	free(cur);
}

void DeleteNodeBetween(Node* cur)
{
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
	printf("Cur was deleted\n");
	
}

void DeleteNode(List* list, Node* cur)
{
	if (CheckPtr(cur->prev)== PTR_NULL)
		DeleteNodeFromHead(list, cur);
	if (CheckPtr(cur->next)== PTR_NULL)
		DeleteNodeFromTail(cur);
	else
		DeleteNodeBetween(cur);
	list->size--;
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
/*
Node* InsertNodeBefore(Node* cur, int data)
{
	Node* new_node = CreateNode();
	new_node->data = data;
	cur->prev->next = new_node;
	new_node->prev = cur->prev;
	cur->prev = new_node;
	new_node->next = cur;
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

Node* SearchEverywhere(Node* begin, int data)
{
	Node* cur_before = FindDataBefore(begin,data);
	if( cur_before!= NULL)
		return cur_before;
	Node* cur_after = FindDataBefore(begin,data);
	if( cur_after!= NULL)
		return cur_after;
	return NULL;
}
*/
int CheckPtr(Node* cur)
{
	if(cur == NULL)
		return PTR_NULL;
	else
		return PTR_OK;
}
	
//int NodeIndex(Node* n)

	
	
	


	

