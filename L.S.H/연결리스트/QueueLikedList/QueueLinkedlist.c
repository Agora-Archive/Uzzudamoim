#include "QueueLinkedlist.h"
#include <stdlib.h>
#include <stdio.h>
void QueueInit(Que* node)
{
	node->front = NULL;
	node->rear = NULL;
}
int QueueEmpty(Que* node)
{
	if (node->front == NULL)
	{
		return TRUE;
	}
	else
		return FALSE;
}
void Enqueue(Que* node, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		printf("동적할당 실패");
		exit(1);
	}
	newnode->time = data;
	if (QueueEmpty(node))
	{
		//front와 rear이 새로운 노드를 가르키게 함
		node->front = newnode;
		node->rear = newnode;
	}
	else
	{
		node->rear->next = newnode;
		node->rear = newnode;
	}	
}
int Dequeue(Que* node)
{
	if (QueueEmpty(&node)) 
	{
		printf("no data");
		exit(1);
	}
	Node* imsi = node->front;
	int find_Number = node->front->time;
	if (node->front == node->rear)//마지막 연결리스트까지 다 사용한 경우
	{
		QueueInit(node);
	}
	else
	{
		node->front = node->front->next;

	}
	
	free(imsi);
	return find_Number;
}