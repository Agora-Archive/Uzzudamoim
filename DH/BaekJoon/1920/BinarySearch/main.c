#include <stdio.h>
#include <stdlib.h> // 퀵정렬함수 include

#define TRUE 1
#define FALSE 0

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
} // 퀵정렬함수의 매개변수 중 비교함수의 반환값은 양수,0,음수로 따짐

int binarySearch(int ar[], int first, int last, int target) {
    while (first <= last) {
        int mid = first + (last - first) / 2;

        if (ar[mid] == target)
            return TRUE;
        else if (ar[mid] < target)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return FALSE;
}

int main() {
  int A;
  scanf("%d", &A);
  int searchArray[A];

  for (int i = 0; i < A; i++)
    scanf("%d", &searchArray[i]);

  qsort(searchArray, sizeof(searchArray) / sizeof(int), sizeof(int), compare);

  int B;
  scanf("%d", &B);
  int targetArray[B];

  for (int i = 0; i < B; i++)
    scanf("%d", &targetArray[i]);

  for (int i = 0; i < B; i++)
    printf("%d\n", binarySearch(searchArray, 0, sizeof(searchArray) / sizeof(int) - 1,
                         targetArray[i]));
}
