#include "St_Linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void SInsert(list* list,char* name, double kor, double math, double en)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->name, name);
    newnode->score[0] = kor;
    newnode->score[1] = math;
    newnode->score[2] = en;
    newnode->score[3] = kor + math + en;
    Node* first = list->head;
    while ((first->next) != NULL && list->comp(newnode->score[3], first->next->score[3]) != 0) {
        first = first->next;
    }
    newnode->next = first->next;
    first->next = newnode;
    (list->count)++;
}
void SetSortRule(list* list, int (*comp)(Ldata d1, Ldata d2))
{
    list->comp = comp;
}

void ListInit(list* list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->head->next = NULL;
    list->comp = NULL;
    list->count = 0;
    list->order = 0;
}
void FInsert(list* list,char* name ,int kor, int math, int en) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->name, name);
    newnode->score[0] = kor;
    newnode->score[1] = math;
    newnode->score[2] = en;
    newnode->score[3] = kor + math + en;
    newnode->next = list->head->next;
    list->head->next = newnode;
    (list->count)++;
}
void LInsert(list* list, char* name,double kor, double math, double en) {
    if (list->head->next == NULL) {
        FInsert(list, name,kor,math,en);
    }
    else
        SInsert(list, name,kor,math,en);
}
int LFirst(list* list, Lname* name, Ldata* data,int* order){
    if (list->head->next == NULL) {
        return FALSE;
    }
    list->order = 1;
    list->before = list->head;
    list->cur = list->head->next;
    strcpy(name, list->cur->name);
    data[0] = list->cur->score[0];
    data[1] = list->cur->score[1];
    data[2] = list->cur->score[2];
    data[3] = list->cur->score[3];
    *order = list->order;
    return TRUE;
}
int LNext(list* list, Lname* name, Ldata* data, int* order){
    if (list->cur->next == NULL) {
        return FALSE;
    }
    list->order = list->order + 1;
    list->before = list->cur;
    list->cur = list->cur->next;
    strcpy(name, list->cur->name);
    data[0] = list->cur->score[0];
    data[1] = list->cur->score[1];
    data[2] = list->cur->score[2];
    data[3] = list->cur->score[3];
    *order = (list -> order);
    return TRUE;
}
void LRemove(list* list,char* Del_name) {
    Node* rpos = list->cur;
    list->before->next = list->cur->next;
    list->cur = list->before;
    strcpy(Del_name, rpos->name);
    free(rpos);
    (list->count)--;

}
int Lcount(list* list) { return list->count; }

void SetSortRule(list* list, int (*comp)(Ldata d1, Ldata d2));
