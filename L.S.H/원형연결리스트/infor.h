#ifndef INFORMATION_H
#define INFORMATION_H
#include <stdbool.h>


typedef struct information Node;
typedef struct control com;
void ListInit(com* list);
void LInsert(com* list, char* name, int number);
bool First(com* list, char** name, int* plus);
bool Next(com* list, char** name, int* plus);
int ListCount(com* list);
void find_person(com* list,char*name, int plus);//�Ű������� ���� �̸��� ã��
com* create(void);



#endif


