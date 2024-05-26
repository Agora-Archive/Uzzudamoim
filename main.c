#include "St_linkedlist.h"
#include <stdio.h>

int Fun_sort(Ldata d1, Ldata d2) {
    if (d1 > d2) {
        return 0;
    }
    else
        return 1;
}
int main() {

    list list;
    Lname name[100];
    Ldata score[4];
    Lname Del_name[100];
    int order;
    ListInit(&list);
    SetSortRule(&list, Fun_sort);
    LInsert(&list, "이시형",82.4,93.5,78.4);
    LInsert(&list, "김수현", 67.5, 32.2, 88.3);
    LInsert(&list, "정민교", 22.3, 53.3, 76.2);
    LInsert(&list, "김태형", 98.3, 73.5, 26.4);
    LInsert(&list, "송강", 27.4, 93.5, 88.4);
    printf("현재 데이터의 수 : %d\n", Lcount(&list));
    printf("\n");

    if (LFirst(&list, name,score,&order)) {
        printf("%-6s %5.1f %5.1f %5.1f\tsum: %3.1f\t %d\n ", 
            name,score[0],score[1],score[2],score[3],order);
        printf("--------------------------------------------------------");
        printf("\n");
       

        while (LNext(&list, name, score,&order)) {
            printf("%-6s %5.1f %5.1f %5.1f\tsum: %3.1f\t %d\n ",
                name, score[0], score[1], score[2], score[3],order);
            printf("--------------------------------------------------------");
            printf("\n");
        }
         printf("\n");
   
    }

    if (LFirst(&list, name,score,&order)) {
        if (score[0] <= 30) {//국어 점수가 30점보다 낮으면 삭제
            LRemove(&list,Del_name);
            printf("%s 삭제\n", Del_name);
        }


        while (LNext(&list,name,score,&order)) {
            if (score[0] <= 30) {
                LRemove(&list, Del_name);
                printf("%s 삭제\n", Del_name);
            }
        }
    }
    printf("현재 데이터의 수 : %d\n", Lcount(&list));
    LInsert(&list, "지코", 30.54, 37.5, 55.4);

    printf("현재 데이터의 수 : %d\n", Lcount(&list));
    printf("\n");

    if (LFirst(&list, name, score, &order)) {
        printf("%-6s %5.1f %5.1f %5.1f\tsum: %3.1f\t %d\n ",
            name, score[0], score[1], score[2], score[3], order);
        printf("--------------------------------------------------------");
        printf("\n");


        while (LNext(&list, name, score, &order)) {
            printf("%-6s %5.1f %5.1f %5.1f\tsum: %3.1f\t %d\n ",
                name, score[0], score[1], score[2], score[3], order);
            printf("--------------------------------------------------------");
            printf("\n");
        }
        printf("\n");

    }
}