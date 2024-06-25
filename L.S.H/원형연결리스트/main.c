#define _CRT_SECURE_NO_WARNINGS
#include "infor.h"
#include <stdio.h>
#include <string.h>

int main(void) 
{
	com* list1 = create();
	ListInit(list1);
	char *name = "이시형";
	int i = 99;
	LInsert(list1, name, i);
	
	name = "김민수";
	i = 44;
	LInsert(list1, name, i);

	name = "박수환";
	i = 15;
	LInsert(list1, name, i);

	name = "강민철";
	i = 11;
	LInsert(list1, name, i);

	if (First(list1, &name, &i))
	{
		printf("이름은 %s이고 사번은 %d입니다.\n", name, i);
	}
	for (int j = 0; j < (ListCount(list1) - 1); j++)
	{
		if (Next(list1, &name, &i))
		{
			printf("이름은 %s이고 사번은 %d입니다.\n", name, i);
		}
		
	}
	find_person(list1, "이시형", 6);
}
