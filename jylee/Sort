#include <stdio.h>

void BubbleSort(int arr[], int n) {
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < (n - i) - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int k, data;
	int arr[1000];
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d", &data);
		arr[i] = data;
	}

	BubbleSort(arr, k);

	for (int i = 0; i < k; i++) {
		printf("%d\n", arr[i]);
	}
}
