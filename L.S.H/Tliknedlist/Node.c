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

List* create(void) //객체 동적 생성
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
	//우선 더미 노드 부터 생성
	if (plist->head == NULL)//아직 head와 null에 더미도 없는 경우
	{
		plist->head = (Node*)malloc(sizeof(Node));//더미 값
		plist->tail = (Node*)malloc(sizeof(Node));//더미 값

		if (plist->head == NULL && plist->tail == NULL)
		{
			printf("더미 노드 생성 실패");
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
		printf("동적할당실패\n");
		exit(1);
	}
	newnode->data = data;
	//꼬리 부분 부터 값을 저장 
	//값이 들어오면 꼬리에 계속 연결됨
	if (plist->tail->prev == plist->head)//아무 데이터가 없는 경우 
	{
		newnode->next = plist->tail;
		newnode->prev = plist->head;
		plist->tail->prev = newnode;
		plist->head->next = newnode;
	}
	else//데이터가 하나라도 있는 경우
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

