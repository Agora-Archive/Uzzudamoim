#define _CRT_SECURE_NO_WARNINGS

#include "infor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct information
{
	char name[15];//이름
	int  number; // 사번
	Node* next;
};

typedef struct control
{
	Node* tail;
	Node* cur;
	Node* before;
	int numofData;
};

com* create(void)
{
	com* s;
	if ((s = malloc(sizeof(com))) == NULL) {
		printf("node could not created\n");
		exit(EXIT_FAILURE);
	}
	s->tail = NULL;
	s->cur = NULL;
	s->before = NULL;
	return s;
}




void ListInit(com* list)
{
	list->tail = NULL;
	list->cur = NULL;
	list->before = NULL;
	list->numofData = 0;
}
void LInsert(com* list, char* name, int number)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) {
		printf("newnode could not created\n");
		exit(EXIT_FAILURE);
	}
	strcpy(newnode->name, name);
	newnode->number = number;
	if (list->tail == NULL) //아직 아무 데이터도 들어오지 않았다면
	{
		list->tail = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = list->tail->next;
		list->tail->next = newnode;
		list->tail = newnode;
	}
	(list->numofData)++;
}
bool First(com* list, char** name, int* plus)
{
	if (list->tail == NULL)//자료가 하나도 안담긴 경우
	{
		return false;
	}
	else
	{
		list->before = list->tail;
		list->cur = list->tail->next;
		*name = list->cur->name;
		*plus = list->cur->number;
		return true;
	}
}
bool Next(com* list, char** name, int* plus)
{
	if (list->tail == NULL)
	{
		return false;
	}
	list->before = list->cur;
	list->cur = list->cur->next;
	*name = list->cur->name;
	*plus = list->cur->number;
	return true;
}
int ListCount(com* list)
{
	return list->numofData;
}

void find_person(com* list, char * name, int plus)
{
	char* imsi_name;
	int imsi_number= 0;
	First(list, &imsi_name, &imsi_number);

	if (strcmp(imsi_name, name) != 0)//이름이 같이 않을 경우 계속 찾아야함
	{
		for (int i = 0; i < (list->numofData) - 1; i++)
		{
			Next(list, &imsi_name, &imsi_number);

			if (strcmp(imsi_name,name) == 0)
			{
				break;//이름을 찾을 경우 정지; 
			}
		}
	}

	plus = plus % list->numofData;

	for (int i = 0; i < plus; i++)
	{
		Next(list, &imsi_name, &imsi_number);
	}
	printf("당직자의 이름은 %s이고 사번은 %d입니다.", imsi_name, imsi_number);
}
