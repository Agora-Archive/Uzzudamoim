#include "QueueLinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2


#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

#define hour 60 *60

//배열 기반 큐가 아닌 연결리스트로 작성되었기 때문에 
//  MEMORY가 가득찬 문제는 발생하지 않는다.

int main()
{

	int makeProc = 0;//대기실이 아닌 밖에서 대기하는 사람의 남은 조리시간
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Que que;
	QueueInit(&que);
	srand(time(NULL));
	for (sec = 0; sec < hour; sec++)
	{
		if (sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
			{
				Enqueue(&que, CHE_TERM);
				cheOrder++;
				break;
			}


			case BUL_BUR:
			{

				Enqueue(&que, BUL_TERM);
				bulOrder++;
				break;
			}


			case DUB_BUR:
			{

				Enqueue(&que, DUB_TERM);
				dubOrder++;
				break;
			}







			}


		}

		if (makeProc <= 0 && !(QueueEmpty(&que)))
		{
			makeProc = Dequeue(&que);
		}
		makeProc--;

	}
	printf("Simulation Report! \n");
	printf(" - Chesse burger: %d \n", cheOrder);
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf("Waiting room size : %d\n", QUE_LEN);


}
