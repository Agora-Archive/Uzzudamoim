#define _CRT_SECURE_NO_WARNINGS

#include "LinkedQueue.h"

void create_queue(LinkedQueue** Queue) {
	*Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	if (*Queue == NULL) {
		printf("Queue could not be created\n");
		exit(EXIT_FAILURE);
	}

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

Node* create_node(int Data) {
	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL) {
		printf("node could not be created\n");
		exit(EXIT_FAILURE);
	}

	new_node->Data = Data;

	new_node->NextNode = NULL;

	return new_node;
}

void destroy_node(Node* Node) {
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

int dequeue(LinkedQueue* Queue) {
	Node* Front = Queue->Front;

	if (Queue->Front->NextNode == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
		Queue->Front = Queue->Front->NextNode;

	(Queue->Count)--;
	int result = Front->Data;
	free(Front);

	return result;
}

int is_empty(LinkedQueue* Queue) {
	return (Queue->Front == NULL);
}
