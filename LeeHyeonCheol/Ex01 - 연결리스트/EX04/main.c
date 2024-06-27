#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(void)
{
	int makeProc = 0;
	int che_order = 0, bul_order = 0, dub_order = 0;
	int sec;
	
	LinkedQueue* Queue;
	Node* Popped;

	create_queue(&Queue);

	srand(time(NULL));
	
	for (sec = 0; sec < 3600; sec++) {
		if (sec % CUS_COME_TERM == 0) {
			switch (rand() / (RAND_MAX / 3 + 1)) {
			case CHE_BUR:
				enqueue(Queue, create_node(CHE_TERM));
				che_order++;
				break;
			case BUL_BUR:
				enqueue(Queue, create_node(BUL_TERM));
				bul_order++;
				break;
			case DUB_BUR:
				enqueue(Queue, create_node(DUB_TERM));
				dub_order++;
				break;
			}
		}

		if (makeProc <= 0 && !is_empty(Queue)) {
			makeProc = dequeue(Queue);
		}
		
		makeProc--;
	}
	printf("Simaulation Report \n");
	printf(" - Cheese burger: %d\n", che_order);
	printf(" - Bulgogi burger: %d\n", bul_order);
	printf(" - Double burger: %d\n", bul_order);
	printf(" - Waiting room size: %d\n", Queue->Count);


	destroy_queue(Queue);

	return 0;
}