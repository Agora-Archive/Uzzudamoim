#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const char* a, const char* b) {
    char ab[20], ba[20];
    sprintf(ab, "%s%s", *(char**)a, *(char**)b);
    sprintf(ba, "%s%s", *(char**)b, *(char**)a);
    return strcmp(ba, ab);
}
//�� ���ڿ��� ���ļ� ���� -> ������ �� � ���� �� ū ������ ��   
//�� ���ڿ��� �� �ϱ� ����

void MergeTwoArea(char* arr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    char** sortArr = (char**)malloc(sizeof(char*) * (right - left + 1));
    if (sortArr == NULL) {
        printf("�����Ҵ� ����");
        exit(1);
    }

    int sIdx = 0;
    while (fIdx <= mid && rIdx <= right) {
        if (compare(&arr[fIdx], &arr[rIdx]) >= 0) { // compare �Լ� ����Ͽ� ���� ���� ����
            /// 0 ū ���� ������ ��� �޼��� �� ũ�� ������ �迭 �պκп� ���� ���� ���� �����Ѵ�.
            sortArr[sIdx++] = arr[fIdx++];
        }
        else {
            sortArr[sIdx++] = arr[rIdx++];
        }
    }

    while (fIdx <= mid) {
        sortArr[sIdx++] = arr[fIdx++];
    }

    while (rIdx <= right) {
        sortArr[sIdx++] = arr[rIdx++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = sortArr[i - left];
    }

    free(sortArr);
}

void MergeSort(char* arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        MergeTwoArea(arr, left, mid, right);
    }
}

char* solution(int numbers[], size_t numbers_len) {
    // �ʿ��� �� ���̸� ��� (�� ���ڰ� �ִ� 4�ڸ�, �߰��� '\0'�� ���� 1�ڸ�)
    size_t total_length = numbers_len * 4 + 1;
    char* answer = (char*)malloc(total_length);
    if (answer == NULL) {
        printf("�����Ҵ� ����");
        exit(1);
    }
    answer[0] = '\0'; // �� ���ڿ��� �ʱ�ȭ

    char** stringArray = (char**)malloc(numbers_len * sizeof(char*));
    if (stringArray == NULL) {
        printf("�����Ҵ� ����");
        exit(1);
    }

    for (int i = 0; i < numbers_len; i++) {
        stringArray[i] = (char*)malloc(5 * sizeof(char)); // �� ���ڿ��� ���� �޸� �Ҵ� (�ִ� 4�ڸ� + '\0')
        if (stringArray[i] == NULL) {
            printf("�����Ҵ� ����");
            exit(1);
        }
        snprintf(stringArray[i], 5, "%d", numbers[i]); // ���ڸ� ���ڿ��� ��ȯ
    }

    // ���� ���� ���
    MergeSort(stringArray, 0, numbers_len - 1);

    // �ڿ������� ���ڿ��� ��ġ�鼭 �޸� ���� 
    for (int i = numbers_len - 1; i >= 0; i--) {
        strcat(answer, stringArray[i]);
        free(stringArray[i]); 
    }
    free(stringArray); // �迭 �޸� ����
    if (answer[0] == '0') // �� �տ� ���ڰ� 0�� ��� �ڿ� ���ڵ� ��� 0�̱� ������ ���� ó�� �����ش�.
    {
        strcpy(answer, "0");

    }

    return answer;
}

int main() {
    int numbers[] = { 0, 0, 0 };
    size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]);

    char* result = solution(numbers, numbers_len);
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    }

    return 0;
}