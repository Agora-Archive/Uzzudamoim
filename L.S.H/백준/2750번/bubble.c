#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Bubble(int arr[], int count)
{
	for (int i = 0; i < count - 1;i++)//배열이 4개 인 경우 뒤에서 부터 정렬을 하기 떄문에 맨 3개만 정렬되면 된거임
	{
		for (int j = 0; j < (count - 1 - i);j++) //i를 정렬한 개수로 보면됨 
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
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