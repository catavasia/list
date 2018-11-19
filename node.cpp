#include <stdio.h>
#include <stdlib.h>

#define E(code, name); const int ERROR_##name = code;
#define O(code, name); const int OK_##name = code;
const int PTR_OK = 1;
const int PTR_ERROR = -1;

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

Node* CreateAndLinkNode(Node* , Node* , int );
void PrintNode(Node* cur);
void DeleteNode( Node* cur);
Node* CreateNode();
Node* InsertAfter(Node* cur, int data);
void DeleteNode(Node* cur);
Node* InsertBefore(Node* cur, int data);
void Swap(Node* one, Node* two);
Node* FindDataAfter(Node* begin, int data);
Node* FindDataBefore(Node* begin, int data);
Node* FindEverywhere(Node* begin, int data);
List* CreateList();
//void InsertInHead(Node* cur, List* list);
int CheckPtr(Node* cur);
void PrintList(List* list);
Node* PutData(Node* cur, int data);
void AddToList(List* list, int data);
int NodeIndex(int data);


int main()
{
	Node* n = (Node*)calloc(1, sizeof(Node));
	n->data = 4;
	Node* a = (Node*)calloc(1, sizeof(Node));
	a->data = 13;
	List* list = CreateList();
	printf("%lu\n", list->size);
	AddToList(list, 5);
	AddToList(list, 9);
	
	printf("size is %lu\n", list->size);
	printf(" head is %p\n", list->head);
	PrintList(list);
	/*printf("n prev  %p\n", n->prev);
	printf("n next  %p\n", n->next);
	//printf("OK\n");
	printf(" a prev %p\n", a->prev);
	printf("a next  %p\n", a->next);
	printf(" n prev %p\n", n->prev);
	printf("n next  %p\n", n->next);
	PrintList(n);
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
	List* list = new List;
	list->head = NULL;
	//list->tail = NULL;
	list->size = 0;
	printf("list was created\n");
	return list;
}

void AddToList(List* list, int data)
{
	Node* new_node = CreateNode();
	list->head = new_node;
	new_node = PutData(new_node, data);
	list->size++;
}
/*void InsertInHead(Node* cur, List* list)
{
	if(list->head != NULL)
		InsertAfter(list->head);
	
	list->head = cur;
}

void InsertInTail(Node* cur, List* list)
{
	list->tail->next = cur;
	cur->prev = list->tail;
	cur->next = list->tail;
	list->tail = cur;
}
	
*/

Node* PutData(Node* cur, int data)
{
	cur->data = data;
	return cur;
}

Node* CreateNode()
{
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = 0;
	return new_node;
}
Node* CreateAndLinkNode(Node* prev, Node* next, int data)
{
	Node* new_node = (Node*)calloc(1, sizeof(Node));
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

void PrintList(List* list)
{
	Node* cur = list->head;
	while(!cur)
	{
		PrintNode(cur);
		printf("Node was printed\n");
		cur = cur->next;
	}

}
void DeleteNode(Node* cur)
{
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
	//printf("Cur was deleted\n");
}

Node* InsertAfter(Node* cur, int data)
{
	Node* new_node = CreateNode();
	new_node->data = data;
	cur->next->prev = new_node;
	new_node->next = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
	return new_node;
}

Node* InsertDataBefore(Node* cur, int data)
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

int CheckPtr(Node* cur)
{
	if(cur == NULL)
		return PTR_ERROR;
	return PTR_OK;
}
	
//int NodeIndex(Node* n)

	

		
	


	

