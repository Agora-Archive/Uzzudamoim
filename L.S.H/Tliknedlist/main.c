#include "Node.h"


int main(void)
{
	int data = 0;
	List* list = create();
	ListInit(list);
	LInsert(list, 1);
	LInsert(list, 2);
	LInsert(list, 3);
	LInsert(list, 4);
	LInsert(list, 5);
	LInsert(list, 6);

	if (LFirst(list, &data));
	{
		printf("%d ", data);

		for (int i = 0; i < (LCount(list) - 1); i++)
		{
			if (LNext(list, &data))
			{
				printf("%d ", data);
			}
		
		}
		printf("\n");
	}
	printf("총 내부 개수는 : %d개입니다.\n", LCount(list));

	Previous(list, &data);
	printf("%d\n", data);
	Previous(list, &data);
	printf("%d\n", data);
	Previous(list, &data);
	printf("%d\n", data);
	LRemove(list);//삭제 후

	if (LFirst(list, &data));
	{
		printf("%d ", data);

		for (int i = 0; i < (LCount(list) - 1); i++)
		{
			if (LNext(list, &data))
			{
				printf("%d ", data);
			}

		}
		printf("\n");
	}
	printf("총 내부 개수는 : %d개입니다.\n", LCount(list));
}