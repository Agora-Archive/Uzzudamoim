#ifndef LISTQUEUE_H
#define LSITQUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;


typedef struct Queue 
{

	Node* front;
	Node* rear;
}Queue;

void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}
int QueueEmpty(Queue * q)
{
	if (q->front != NULL)
	{
		return  false;
	}

	else
		return true;
}
void Enqueue(Queue* q, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		exit(1);
	}
	newNode->data = data;
	
	if (QueueEmpty(q))
	{
		q->front = newNode;
		q->rear = newNode;

	}
	else	
	{
		q->rear->next = newNode;
			q->rear = newNode;
	}

}
int Dequeue(Queue* q)
{
	Node* imsi;
	int data;
	if (QueueEmpty(q))
	{
		exit(1);
	}

	imsi = q->front;
	data = q->front->data;
	q->front = q->front->next;

	free(imsi);
	return data;
}


#endif 
