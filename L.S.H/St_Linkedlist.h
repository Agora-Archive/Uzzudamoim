#ifndef ST_LINKEDLIST_H
#define ST_LINKEDLIST_H

#define TRUE 1
#define FALSE 0
typedef double Ldata;
typedef char Lname;
typedef struct node {
	Lname name[100];
	Ldata score[4];//국어 영어 수학, 합계;
	struct node* next;
} Node;
typedef struct Linkedlist {
	Node* head;
	Node* cur;
	Node* before;
	int count;
	int (*comp)(Ldata d1, Ldata d2);
	int order;
} Linkedlist;

typedef Linkedlist list;
void ListInit(list* list);
void LInsert(list* list,char* name, double kor,double math, double en);
int LFirst(list* list,Lname * name ,Ldata* data,int* order);
int LNext(list* list, Lname* name, Ldata* data, int *order);
void  LRemove(list* list ,char * Del_name);
int Lcount(list* list);
void SetSortRule(list* list, int (*comp)(Ldata d1, Ldata d2));

#endif
