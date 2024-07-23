/*#include <stdio.h>

#define TRUE 1
#define FALSE 0

int ISearch(int ar[], int first, int last, int target) {
  int mid;

  if (first > last)
    return -1;

  mid =
      ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) +
      first;

  if (ar[mid] == target)
    return TRUE;
  else if (target < ar[mid])
    return ISearch(ar, first, mid - 1, target);
  else if (target > ar[mid])
    return ISearch(ar, mid + 1, last, target);
  else
    return FALSE;
}

int main() {
  int A;
  scanf("%d", &A);
  int searchArray[A];

  for (int i = 0; i < A; i++)
    scanf("%d", &searchArray[i]);

  int B;
  scanf("%d", &B);
  int targetArray[B];

  for (int i = 0; i < A; i++)
    scanf("%d", &targetArray[i]);

  int idx;

  for (int i = 0; i < B; i++)
    printf("%d", ISearch(searchArray, 0, sizeof(searchArray) / sizeof(int) - 1,
                         targetArray[i]));
}
*/

#include "BinarySearchTree.h"
#include <stdio.h>

int main(void) {
  BTreeNode *bstRoot;
  BTreeNode *sNode;

  int A;
  scanf("%d", &A);
  int searchArray[A];

  for (int i = 0; i < A; i++)
    scanf("%d", &searchArray[i]);

  BSTMakeAndInit(&bstRoot);

  for (int i = 0; i < A; i++)
    BSTInsert(&bstRoot, searchArray[i]);

  int B;
  scanf("%d", &B);
  int targetArray[B];

  for (int i = 0; i < A; i++)
    scanf("%d", &targetArray[i]);

  for (int i = 0; i < A; i++) {
    sNode = BSTSearch(bstRoot, targetArray[i]);
    if (sNode == NULL)
      printf("0\n");
    else
      printf("1\n");
  }

  return 0;
}
