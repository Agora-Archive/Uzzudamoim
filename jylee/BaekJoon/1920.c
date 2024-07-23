#define CRT_SECURE_NO_WARNING
#include <stdio.h>

int ISearch(int ar[], int first, int last, int target) {
	int mid;

	if (ar[first]>target || ar[last]<target)
		return -1;

	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;

	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target);
	else
		return ISearch(ar, mid + 1, last, target);
}

void SelSort(int arr[], int n) {
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0; i < n - 1; i++) {
		maxIdx = i;

		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main() {
	int N, M;
	int A[100000];
	int B[100000];
	int idx = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	SelSort(A, N);
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	for (int i = 0; i < M; i++) {
		idx = ISearch(A, 0, M-1, B[i]);

		if (idx == -1)
			printf("0\n");
		else
			printf("1\n");
	}
	
}
