#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
	struct _node* prev;
}Node;
typedef struct _Tlinkedlist
{
	Node* head;
	Node* tail;
	Node* cur;
	int numofData;
}List;

List* create(void) //��ü ���� ����
{
	List* s;
	if ((s = malloc(sizeof(List))) == NULL) {
		printf("node could not created\n");
		exit(EXIT_FAILURE);
	}
	s->tail = NULL;
	s->cur = NULL;
	s->head = NULL;
	return s;
}

void ListInit(List* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->numofData= 0;
}
void LInsert(List* plist, int data)
{
	//�켱 ���� ��� ���� ����
	if (plist->head == NULL)//���� head�� null�� ���̵� ���� ���
	{
		plist->head = (Node*)malloc(sizeof(Node));//���� ��
		plist->tail = (Node*)malloc(sizeof(Node));//���� ��

		if (plist->head == NULL && plist->tail == NULL)
		{
			printf("���� ��� ���� ����");
			exit(1);
		}
		plist->head->prev = NULL;
		plist->head->next = plist->tail;
		plist->tail->prev = plist->head;
		plist->tail->next = NULL;
	}

	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		printf("�����Ҵ����\n");
		exit(1);
	}
	newnode->data = data;
	//���� �κ� ���� ���� ���� 
	//���� ������ ������ ��� �����
	if (plist->tail->prev == plist->head)//�ƹ� �����Ͱ� ���� ��� 
	{
		newnode->next = plist->tail;
		newnode->prev = plist->head;
		plist->tail->prev = newnode;
		plist->head->next = newnode;
	}
	else//�����Ͱ� �ϳ��� �ִ� ���
	{
		newnode->prev = plist->tail->prev;
		newnode->next = plist->tail;
		plist->tail->prev->next = newnode;
		plist->tail->prev = newnode;

	}
	(plist->numofData)++;
}

int LFirst(List* plist, int* pdata)
{
	if (plist->head->next == NULL)
	{
		return 0;
	}
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return 1;
}
int LNext(List* plist, int* pdata)
{
	if (plist->cur->next == NULL)
	{
		return 0;
	}
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return 1;
}

int LRemove(List* plist)
{
	Node* imsinext = plist->cur->next;
	Node* imsiprev = plist->cur->prev;

	plist->cur->prev->next = imsinext;
	plist->cur->next->prev = imsiprev;
	free(plist->cur);
	(plist->numofData)--;
	return 1;
}
int LCount(List* plist)
{
	return plist->numofData;

}

int Previous(List* plist, int* pdata)
{
	plist->cur = plist->cur->prev;
	if (plist->cur->prev == NULL)
	{
		return 0;
	}
	*pdata = plist->cur->data;
	return 1;
}

