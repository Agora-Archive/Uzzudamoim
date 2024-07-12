#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode {
	int* Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue {
	Node* Front;
	Node* Rear;
	int  Count;
} LinkedQueue;

void create_queue(LinkedQueue** Queue);
void destroy_queue(LinkedQueue* Queue);

Node* create_node(int* Data);
void destroy_node(Node* Node);

void enqueue(LinkedQueue* Queue, Node* new_node);
Node* dequeue(LinkedQueue* Queue);
int is_empty(LinkedQueue* Queue);

#endif