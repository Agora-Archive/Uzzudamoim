#ifndef RADIX_H
#define RADIX_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct _Node //ť�� ���Ḯ��Ʈ�� ������ ��� 
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
int QueueEmpty(Queue* q)
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
	newNode->next = NULL;

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

void RadixSort(int arr[], int num, int maxLen)
{
	Queue buckets[10];
	
	int bi;
	int divfac = 1;
	int radix;
	int di;
	for (bi = 0;bi< 10;bi++) //�� ���ڿ� �ش��ϴ� ���� ť�� �ʱ�ȭ�Ѵ�.
	{
		QueueInit(&buckets[bi]);
	}

	for (int i = 0; i < maxLen;i++) //LSD������� �ڿ��� ���� �ִ� �� ������ ���̸� ������ �ݺ��Ѵ�.
	{
		for (int j = 0; j < num;j++)//�� ���� ��ŭ �迭�� ������ ť �迭�� ��´�.
		{
			radix = (arr[j] / divfac) % 10;
			Enqueue(&buckets[radix], arr[j]);

		}
		//�ȿ� ������ �� ������  �ٽ� ���� �迭�� �־��ش�.
		for (bi = 0, di = 0; bi < 10; bi++)
		{
			while (!QueueEmpty(&buckets[bi]))
			{
				arr[di++] = Dequeue(&buckets[bi]);

			}
		}
		divfac *= 10; //ù��° �ڸ��� �ι� ° �ڸ��� ���� �� �ְ� �ڸ� ���� �÷��ش�.

	}


}


#endif
