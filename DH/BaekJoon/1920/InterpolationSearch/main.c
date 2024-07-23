#include <stdio.h>
#include <stdlib.h> // 퀵정렬함수 include

#define TRUE 1
#define FALSE 0

/*int compare(const void *a, const void *b)
  {
      int num1 = *(int *)a;
      int num2 = *(int *)b;

      if (num1 < num2)    // a가 b보다 작을 때는
          return -1;      // -1 반환

      if (num1 > num2)    // a가 b보다 클 때는
          return 1;       // 1 반환

      return 0;    // a와 b가 같을 때는 0 반환
  }*/

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
} // 퀵정렬함수의 매개변수 중 비교함수의 반환값은 양수,0,음수로 따짐

int ISearch(int ar[], int first, int last, int target) {
  int mid;

  if (first > last)
    return 0;

  mid =
      ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) +
      first;

  if (ar[mid] == target)
    return TRUE;
  else if (target < ar[mid])
    return ISearch(ar, first, mid - 1, target);
  else if (target > ar[mid])
    return ISearch(ar, mid + 1, last, target);
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

  int idx;

  for (int i = 0; i < B; i++)
    printf("%d\n", ISearch(searchArray, 0, sizeof(searchArray) / sizeof(int) - 1,
                         targetArray[i]));
}
