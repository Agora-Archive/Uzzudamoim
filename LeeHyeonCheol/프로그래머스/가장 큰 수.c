#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* p, const void* q);

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    
    qsort(numbers, numbers_len, sizeof(int), compare);
    
    if (numbers[0] == 0)
        return "0";
    
    char* answer = (char*)malloc(numbers_len * 4 + 1);
    
    sprintf(answer, "%d", numbers[0]);
    for (int i = 1; i < numbers_len; i++) {
        sprintf(answer, "%s%d", answer, numbers[i]);
    }
    
    return answer; 
}

int compare(const void* p, const void* q)
{
    char pq[10];
    char qp[10];
    
    sprintf(pq, "%d%d", *(int*)p, *(int*)q);
    sprintf(qp, "%d%d", *(int*)q, *(int*)p);
    
    return strcmp(qp, pq);
}
