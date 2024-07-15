#include <stdio.h>

void swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot >= arr[high] && low <= right)
			low++;
		while (pivot <= arr[high] && high >=left+1)
			high--;
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

void quicksort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}

int main() {
	int arr[5];

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	int len = sizeof(arr) / sizeof(int);
	int i;

	quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	printf("%d", arr[0]);
	printf("%d", arr[2]);

	return 0;
}
