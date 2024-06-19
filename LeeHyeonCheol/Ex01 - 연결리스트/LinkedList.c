#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static void terminate(const char* message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Node* create_node(Element New_data) 
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	
	if (new_node == NULL) {
		terminate("Error in create: node could not be created.");
	}

	strcpy(new_node->data.name, New_data.name);
	new_node->data.kor = New_data.kor;
	new_node->data.math = New_data.math;
	new_node->data.com = New_data.com;
	new_node->data.total = New_data.kor + New_data.math + New_data.com;

	new_node->next = NULL;

	return new_node;
}

void destroy_node(Node* Node) 
{
	free(Node);
}

void append_node(Node** Head, Node* New_node) 
{
	if ((*Head) == NULL) {
		*Head = New_node;
	}
	else {
		// 테일을 찾아 New_node를 연결한다.
		Node* Tail = *Head;
		while (Tail->next != NULL)
			Tail = Tail->next;
	
		Tail->next = New_node;
	}
}

void insert_after(Node* Cur, Node* New_node) 
{
	New_node->next = Cur->next;
	Cur->next = New_node;
}

void insert_new_head(Node** Head, Node* New_Head) 
{
	if (Head == NULL) {
		*Head = New_Head;
	}
	else {
		New_Head->next = *Head;
		*Head = New_Head;
	}
}

void remove_node(Node** Head, Node* Remove) 
{
	if (*Head == Remove) {
		*Head = Remove->next;
	}
	else {
		Node* Cur = *Head;
		while (Cur != NULL && Cur->next != Remove) {
			Cur = Cur->next;
		}
		if (Cur != NULL)
			Cur->next = Remove->next;
	}
}

Node* get_node(Node* Head, int Location) 
{
	Node* Cur = Head;

	while (Cur != NULL && (--Location) >= 0) {
		Cur = Cur->next;
	}

	return Cur;
}

int get_node_count(Node* Head) 
{
	int count = 0;
	Node* Cur = Head;

	while (Cur != NULL) {
		Cur = Cur->next;
		count++;
	}

	return count;
}

void descend_sort_list(Node* Head) {
	Node* p, * q;
	Element temp;

	for (p = Head; p != NULL; p = p->next) {
		for (q = p; q != NULL; q = q->next) {
			if (q->data.total > p->data.total) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}