#ifndef RADIX_H
#define RADIX_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct _Node //큐를 연결리스트로 구현한 경우 
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
	for (bi = 0;bi< 10;bi++) //각 숫자에 해당하는 연결 큐를 초기화한다.
	{
		QueueInit(&buckets[bi]);
	}

	for (int i = 0; i < maxLen;i++) //LSD방식으로 뒤에서 부터 최대 긴 숫자의 길이를 가지고 반복한다.
	{
		for (int j = 0; j < num;j++)//각 숫자 만큼 배열에 꺼내서 큐 배열에 담는다.
		{
			radix = (arr[j] / divfac) % 10;
			Enqueue(&buckets[radix], arr[j]);

		}
		//안에 정렬을 다 했으면  다시 원래 배열에 넣어준다.
		for (bi = 0, di = 0; bi < 10; bi++)
		{
			while (!QueueEmpty(&buckets[bi]))
			{
				arr[di++] = Dequeue(&buckets[bi]);

			}
		}
		divfac *= 10; //첫번째 자리면 두번 째 자리를 비교할 수 있게 자리 수를 늘려준다.

	}


}


#endif
