#define _CRT_SECURE_NO_WARNINGS

#include "LinkedQueue.h"

void create_queue(LinkedQueue** Queue) {
	*Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void destroy_queue(LinkedQueue* Queue) {
	while (!is_empty(Queue)) {
		Node* Popped = dequeue(Queue);
		destroy_node(Popped);
	}
	free(Queue);
}

Node* create_node(int* Data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->Data = (int*)malloc(sizeof(int));

	new_node->Data = Data;

	new_node->NextNode = NULL;

	return new_node;
}

void destroy_node(Node* Node) {
	free(Node->Data);
	free(Node);
}

void enqueue(LinkedQueue* Queue, Node* new_node) {
	if (Queue->Front == NULL) {
		Queue->Front = new_node;
		Queue->Rear = new_node;
		Queue->Count++;
	}
	else {
		Queue->Rear->NextNode = new_node;
		Queue->Rear = new_node;
		Queue->Count++;
	}
}

Node* dequeue(LinkedQueue* Queue) {
	Node* Front = Queue->Front;

	if (Queue->Front->NextNode == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
		Queue->Front = Queue->Front->NextNode;

	Queue->Count--;

	return Front;
}

int is_empty(LinkedQueue* Queue) {
	return (Queue->Front == NULL);
}