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
		printf("�����Ҵ� ����");
		exit(1);
	}
	newnode->time = data;
	if (QueueEmpty(node))
	{
		//front�� rear�� ���ο� ��带 ����Ű�� ��
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
	if (node->front == node->rear)//������ ���Ḯ��Ʈ���� �� ����� ���
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