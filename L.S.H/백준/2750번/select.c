#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Bubble(int arr[], int count) //������������ ����
{
	int minnum,j;
	for (int i = 1; i < count;i++) //�ι�° index���� �񱳽��� ù��° �Ŵ� ���ĵǾ� �ִٰ� ����
	{
		minnum = arr[i];

		for ( j = i - 1; j >= 0; j--) // ������ �տ� index ���ڵ�� ���Ѵ�.
		{
			if (arr[j] > minnum)// �ڷ� ���ڸ� �о�����ϴ� ���
			{
				arr[j + 1] = arr[j];
			}
			else // minnum�� �տ� ���� �ٷ� �ڿ� �־�� �Ѵ�.
			{
				break;
			}

		
		}

		arr[j + 1] = minnum; // �տ� ���� �ٷ� �ڿ� �ش� ���ڸ� ���´�. �ٸ� ���ڵ��� �ڷ� ��ĭ�� �о���� ����

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