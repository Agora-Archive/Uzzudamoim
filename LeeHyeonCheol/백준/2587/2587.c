#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

void Swap(int* A, int* B);
int Partition(int Dataset[], int Left, int Right);
void Quick_sort(int Dataset[], int Left, int Right);
void Radix_sort(int Dataset[], int num, int maxLen);

int main(void)
{
	int i = 0;
	int Dataset[5] = {0,};

	for (i = 0; i < 5; i++)
		scanf("%d", &Dataset[i]);
	
	int len = sizeof(Dataset) / sizeof(Dataset[0]);
	int mid;
	int sum = 0;

	//Quick_sort(Dataset, 0, len - 1);
	Radix_sort(Dataset, 5, 2);

	for (i = 0; i < len; i++)
		sum += Dataset[i];
	mid = Dataset[2];

	printf("%d\n", sum / len);
	printf("%d\n", mid);

	return 0;
}


void Swap(int* A, int* B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

int Partition(int Dataset[], int Left, int Right)
{
	int First = Left;
	srand(time(NULL));
	int len = Right - Left + 1;
	int Piv_loc = rand() % len + Left;
	int Pivot = Dataset[Piv_loc];

	if (Pivot != 0)
		Swap(&Dataset[First], &Dataset[Piv_loc]);

	while (Left <= Right) {
		while (Dataset[Left] <= Pivot && Left < Right)
			++Left;

		while (Dataset[Right] >= Pivot && Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&Dataset[Left], &Dataset[Right]);
		else
			break;
	}

	Swap(&Dataset[First], &Dataset[Right]);

	return Right;
}

void Quick_sort(int Dataset[], int Left, int Right)
{
	if (Left < Right) {
		int Index = Partition(Dataset, Left, Right);

		Quick_sort(Dataset, Left, Index - 1);
		Quick_sort(Dataset, Index + 1, Right);
	}
}

void Radix_sort(int Dataset[], int num, int maxLen)
{
	Node* Popped;
	LinkedQueue* Queue[10];
	
	for (int i = 0; i < 10; i++)
		create_queue(&Queue[i]);

	int bi;
	int pos;
	int di; 
	int divfac = 1;
	int radix;
	int BUCKET_NUM = 10;

	for (pos = 0; pos < maxLen; pos++) {
		for (di = 0; di < num; di++) {
			radix = (Dataset[di] / divfac) % 10;

			enqueue(Queue[radix], create_node(Dataset[di]));
		}

		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
			while (!is_empty(Queue[bi])) {
				Popped = dequeue(Queue[bi]);
				Dataset[di++] = Popped->Data;
			}
		}

		divfac *= 10;
	}
}