#define _CRT_SECURE_NO_WARNINGS
#include "infor.h"
#include <stdio.h>
#include <string.h>

int main(void) 
{
	com* list1 = create();
	ListInit(list1);
	char *name = "�̽���";
	int i = 99;
	LInsert(list1, name, i);
	
	name = "��μ�";
	i = 44;
	LInsert(list1, name, i);

	name = "�ڼ�ȯ";
	i = 15;
	LInsert(list1, name, i);

	name = "����ö";
	i = 11;
	LInsert(list1, name, i);

	if (First(list1, &name, &i))
	{
		printf("�̸��� %s�̰� ����� %d�Դϴ�.\n", name, i);
	}
	for (int j = 0; j < (ListCount(list1) - 1); j++)
	{
		if (Next(list1, &name, &i))
		{
			printf("�̸��� %s�̰� ����� %d�Դϴ�.\n", name, i);
		}
		
	}
	find_person(list1, "�̽���", 6);
}
