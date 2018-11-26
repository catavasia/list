#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

const int PTR_OK = 1;
const int PTR_NULL = -1;

struct Node
{
	char* data;
	Node* next;
	Node* prev;
	Node(char* s)
	{
		next = NULL;
		prev = NULL;
		data = s;
	}
};

struct List
{
	Node* head;
	size_t size;
	List()
	{
		head = NULL;
		size = 0;
	}
	~List()
	{
		size = 0;
		head = NULL;
	}
};

//List* CreateList(); //создание списка
int CheckPtr(Node* cur);
void PrintNode(Node* cur);
Node* CreateNode(long);
Node* AddToHeadList(List* list, long data); // вставляет в начало списка
Node* Search(List* list, long data);

/*
int main()
{
	List* new_list = CreateList();
	Node* new_node = AddToHeadList(new_list, 't');
	Node* a = AddToHeadList(new_list, 'h');
	PrintNode(a);
	printf(" ptr %p\n", new_node);
	Search(new_list, 'j');
	return 0;
}
*/

/*List* CreateList()
{
	List* new_list = new List;
	new_list->head = NULL;
	new_list->size = 0;
	printf("list was created\n");
	return new_list;
}
*/
Node* AddToHeadList(List* list, long data)
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

Node* CreateNode(long* data)
{
	Node* new_node = new Node;
	new_node->prev = NULL;
	new_node->next = NULL;
	size_t s = strlen(data);
	new_node->data = new long[s+1];
	new_node->data[s] = '\0';
	strcpy(new_node->data, data);
	return new_node;
}

void PrintNode(Node* cur)
{
	printf("%c\n", cur->data);
}


Node* Search(List* list, long* data)
{
	Node* cur = list->head;
	while(cur!= NULL)
	{
		if(cur->data == data)
			return cur;
		cur = cur->next;
		printf("ptr is %p\n", cur);
	}
	return cur;
}

int CheckPtr(Node* cur)
{
	if(cur == NULL)
		return PTR_NULL;
	else
		return PTR_OK;
}
	
	
	
	


	

