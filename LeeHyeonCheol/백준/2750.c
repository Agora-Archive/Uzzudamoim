#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void BubbleSort(int DataSet[], int Length);
void SelectionSort(int DataSet[], int Length);

int main(void)
{
	int i, j;
	int number;
	int num[1000];
	int temp;

	scanf("%d", &number);

	for (i = 0; i < number; i++) {
		scanf("%d", &num[i]);
	}


	//BubbleSort(num, number);
	SelectionSort(num, number);

	for (i = 0; i < number; i++)
		printf("%d\n", num[i]);

	return 0;
}

void BubbleSort(int DataSet[], int Length)
{
	int i, j;
	int temp;

	for (i = 0; i < Length - 1; i++) {
		for (j = 0; j < Length - i - 1; j++) {
			if (DataSet[j] > DataSet[j + 1]) {
				temp = DataSet[j];
				DataSet[j] = DataSet[j + 1];
				DataSet[j + 1] = temp;
			}
		}
	}
}

void SelectionSort(int DataSet[], int Length)
{
	int i, j;
	int temp;
	int min;

	for (i = 0; i < Length - 1; i++) {
		min = i;
		for (j = i; j < Length; j++) {
			if (DataSet[j] < DataSet[min]) {
				min = j;
			}
		}
		temp = DataSet[i];
		DataSet[i] = DataSet[min];
		DataSet[min] = temp;
	}
}