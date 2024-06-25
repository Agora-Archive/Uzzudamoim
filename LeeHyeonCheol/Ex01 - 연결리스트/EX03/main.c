#include "LinkedList.h"

int main(void)
{
	int i = 0;
	int count = 0;
	Node* List = NULL;
	Node* new_node = NULL;
	Node* cur = NULL;

	char* NAME[4] = { "mr.A", "mr.B", "mr.C", "mr.D" };

	for (i = 0; i < 4; i++) {
		new_node = create(NAME[i], i);
		append(&List, new_node);
	}

	count = getNodeCount(List);
	for (i = 0; i < count; i++) {
		cur = getNodeAt(List, i);
		printf("List[%d] : %s, %d\n", i, cur->name, cur->id);
	}

	cur = getNodeAfterDay(List, NAME[2], 7);
	printf("7ÀÏ ÈÄ: %s, %d\n", cur->name, cur->id);

	return 0;
}