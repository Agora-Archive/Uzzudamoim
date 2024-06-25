#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	char* name;
	int id;
	struct tagNode* prev;
	struct tagNode* next;
} Node;


Node* create(char* name, int id);
void destroy(Node* node);
void append(Node** head, Node* new_node);
void insert(Node* cur, Node* new_node);
void remove_node(Node** head, Node* remove);
Node* getNodeAt(Node* head, int location);
int getNodeCount(Node* head);

Node* getNodeAfterDay(Node* head, char* name, int day);

#endif