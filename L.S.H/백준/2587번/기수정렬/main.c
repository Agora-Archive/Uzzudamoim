#define _CRT_SECURE_NO_WARNINGS
#include "Radixsort.h"

int countDigits(int num) {
	int count = 0;
	if (num == 0) return 1; // 0은 한 자리수
	if (num < 0) num = -num; // 음수는 양수로 변환

	while (num != 0) {
		num /= 10;
		count++;
	}
	return count;
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
		int max = arr[0];
		for (int i = 1; i < 5;i++)
		{
			if (max < arr[i])
				max = arr[i];
		}

		imsi = countDigits(max);
		
		RadixSort(arr, count, imsi);
		
		

		printf("%d\n%d", average(arr, count), median(arr, count));

	}



