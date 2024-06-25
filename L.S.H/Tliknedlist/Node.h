#ifndef  NODE_H
#define NODE_H

typedef struct _node Node;
typedef struct _Tlinkedlist List;
void ListInit(List* plist);
void LInsert(List* plist, int data);
int LFirst(List* plist, int* pdata);
int LNext(List* plist, int* pdata);
int LRemove(List* plist);
int LCount(List* plist);
int Previous(List* plist, int* pdata);
List* create(void);

#endif 
