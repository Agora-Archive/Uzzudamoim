#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Bubble(int arr[], int count) //오름차순으로 정렬
{
	int minnum,j;
	for (int i = 1; i < count;i++) //두번째 index부터 비교시작 첫번째 거는 정렬되어 있다고 가정
	{
		minnum = arr[i];

		for ( j = i - 1; j >= 0; j--) // 정렬은 앞에 index 숫자들과 비교한다.
		{
			if (arr[j] > minnum)// 뒤로 숫자를 밀어줘야하는 경우
			{
				arr[j + 1] = arr[j];
			}
			else // minnum은 앞에 숫자 바로 뒤에 있어야 한다.
			{
				break;
			}

		
		}

		arr[j + 1] = minnum; // 앞에 숫자 바로 뒤에 해당 숫자를 놓는다. 다른 숫자들은 뒤로 한칸씩 밀어버린 상태

	}

}

int main()
{
	int Count;

	scanf("%d", &Count);

	int* arr = (int*)malloc(Count * sizeof(int));
	if (arr == NULL)
	{
		exit(1);
	}

	for (int i = 0; i < Count;i++)
	{

		scanf("%d", &arr[i]);

	}


	Bubble(arr, Count);
	for (int i = 0; i < Count;i++)
	{
		printf("%d\n", arr[i]);
	}

}