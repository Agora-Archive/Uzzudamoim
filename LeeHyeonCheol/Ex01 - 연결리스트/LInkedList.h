#define _CRT_SECURE_NO_WARNINGS

#ifndef LISTADT_H
#define LISTADT_H

typedef struct Element {
	char name[20];
	double kor, math, com, total;
} Element;

typedef struct Node {
	Element data;
	struct node* next;
} Node;

Node* create_node(Element New_data);
void destroy_node(Node* Node);
void append_node(Node** Head, Node* New_node);
void insert_after(Node* Cur, Node* New_node);
void insert_new_head(Node** Head, Node* New_Head);
void remove_node(Node** Head, Node* Remove);
Node* get_node(Node* Head, int Location);
int get_node_count(Node* Head);

void descend_sort_list(Node* Head);
#endif