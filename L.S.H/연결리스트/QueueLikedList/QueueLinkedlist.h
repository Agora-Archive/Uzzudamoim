#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#define TRUE 1
#define FALSE 0
#define QUE_LEN 100

typedef struct node
{
	int time;
	struct node* next;
}Node;
 
typedef struct Queue
{
	Node* front;
	Node* rear;
}Que;



void QueueInit(Que* node);
int QueueEmpty(Que* node);
void Enqueue(Que* node, int data);
int Dequeue(Que* node);
#endif