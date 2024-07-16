#include <stdio.h> 
#include <math.h>


void makeTree(int* tree, int* inorder, int start, int end, int index) {
    if (start > end) {
        return; 
    } // 더 이상 노드가 없을 때 함수 종료

    int mid = (start + end) / 2;
    tree[index] = inorder[mid];

    // 재귀
    makeTree(tree, inorder, start, mid - 1, 2 * index + 1);
    makeTree(tree, inorder, mid + 1, end, 2 * index + 2);
}

void printTreeLevels(int* tree, int K) {
    int level_start = 0;

    // 각 레벨별로 출력
    for (int i = 0; i < K; i++) {
        int level_end = level_start + pow(2, i) - 1;
        for (int j = level_start; j <= level_end; j++) {
            printf("%d ", tree[j]);
        }
        printf("\n");
        level_start = level_end + 1;
    }
}

int main(void) {
    int K;
    scanf("%d", &K);

    int tree_size = pow(2, K) - 1;
    int inorder[tree_size];  // 중위 순회 배열
    int tree[tree_size];     // 출력할 트리 배열

    for (int i = 0; i < tree_size; i++) {
        scanf("%d", &inorder[i]);
    }
  
    makeTree(tree, inorder, 0, tree_size - 1, 0);
    printTreeLevels(tree, K);

    return 0;
}
