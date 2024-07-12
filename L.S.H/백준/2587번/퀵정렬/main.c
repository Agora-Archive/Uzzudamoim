/*
다섯개의 자연수가 주어짐 
-> 중앙값과 평균을 구하는 문제
->중앙값의 경우 정렬 
-> 퀵 정렬 사용
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Swap(int arr[], int index1, int index2) // 교환 함수
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}


int Partition(int arr[], int left, int right)
{

	int pivot = arr[left]; //왼쪽으로 정렬
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
		{
			low++;
		}

		while (pivot <= arr[high] && high >= (left + 1))
		{
			high--;
		}

		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}

	Swap(arr, left, high);
	return high;
}


void Qsort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		Qsort(arr, left, pivot - 1);
		Qsort(arr, pivot + 1, right);
	}
}

int average(int arr[], int count)
{
	int sum = 0;
	for (int i = 0; i < count;i++)
	{
		sum += arr[i];
	}

	return sum / count;
}

int median(int arr[], int count)
{
	if (count % 2 == 0)//짝수 개인 경우
	{
		return (arr[count / 2] + arr[count / 2 + 1]) / 2;
	}
	else
	{
		return arr[count / 2];
	}
};


int main()
{
	int arr[5];
	int count = 5;
	int imsi;
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &arr[i]);		
	}
	Qsort(arr, 0, 4);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);

	}
	printf("%\n");

	printf("%d\n%d", average(arr, count), median(arr, count));



}