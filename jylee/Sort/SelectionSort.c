#include <stdio.h>

void InserSort(int arr[], int n) {
	int i, j;
	int insData;

	for (i = 1; i < n; i++) {
		insData = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
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

	InserSort(arr, k);

	for (int i = 0; i < k; i++) {
		printf("%d\n", arr[i]);
	}
}
