#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

int main(void) {
	int i = 0;
	int count = 0;
	Node* List = NULL;
	Node* Cur = NULL;
	Node* new_node = NULL;
	Node* temp = NULL;

	Element FILE[8] = {
		{"�����", 100.0, 45.9, 78.5},
		{"������", 64.8, 78.9, 100},
		{"������", 82.4, 93.5, 88.4},
		{"�߽ż�", 99.5, 43.9, 88.3},
		{"����ȣ", 100.0, 99.9, 78.5},
		{"�̴�ȣ", 88.9, 99.9, 78.9},
		{"����ȣ", 85.4, 78.6, 31.5},
		{"������", 82.4, 93.5, 78.4}
	};

	for (i = 0; i < 8; i++) {
		new_node = create_node(FILE[i]);
		append_node(&List, new_node);
	}
	descend_sort_list(List);		// total�� ���Ͽ� �������� ����

	count = get_node_count(List);
	for (i = 0; i < count; i++) {
		Cur = get_node(List, i);
		printf("List[%d] : %s, %5.1lf, %5.1lf, %5.1lf, %5.1lf\n", i, Cur->data.name, Cur->data.kor,
			Cur->data.math, Cur->data.com, Cur->data.total);
	}
	printf("\n\n");

	temp = get_node(List, 7);		// ������ ��� ����
	remove_node(&List, temp);
	destroy_node(temp);
	
	Element a = { "����ö", 100, 100, 100 };		// ���ο� ��� �߰�
	temp = create_node(a);
	insert_new_head(&List, temp);
	descend_sort_list(List);

	count = get_node_count(List);
	for (i = 0; i < count; i++) {
		Cur = get_node(List, i);
		printf("List[%d] : %s, %5.1lf, %5.1lf, %5.1lf, %5.1lf\n", i, Cur->data.name, Cur->data.kor,
			Cur->data.math, Cur->data.com, Cur->data.total);
	}

	// �޸𸮿��� ��� ��� ����
	for (i = 0; i < count; i++) {
		Cur = get_node(List, 0);

		if (Cur != NULL) {
			remove_node(&List, Cur);
			destroy_node(Cur);
		}
	}

	return 0;
}