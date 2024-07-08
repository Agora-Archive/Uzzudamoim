#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
* 각 레벨k일 경우 자료의 총 개수는 2의 k승 -1개
* 반복 횟수는 k레벨 만큼 -> K
* 레벨이 내려갈 때 마다 기준 레벨의 자료 개수의 2배 만큼 증가 함 -> 자료의 개수를 저장하는 변수 필요!
* 출력방식
* 1.배열을 사용하여 입력한 순서 저장
* 2.각 레벨 출력방식 -> 레벨을 거꾸로 생각 밑으로 내려갈 수록 위에 있는 level의 인덱스 거리는 
2의 k레벨 - 현재레벨 만큼 벌어짐 이를 이용하여 인덱스 사이의 거리를 구할 수 있음
3. 어디서부터 시작할 것인가?  위에서 구한 인덱스 거리  / 2  -1 부터 시작하여  인덱스 거리 만큼 더해서 출력하는 방식


필요한 변수 -> level을 받을 변수 k, 순서를 받을 배열(1023) ,각 레벨당 자료의 개수를 저장하는 변수,
각 레벨의 인덱스 거리를 저장하는 변수, 어디서부터 시작할 것인가에 대한 변수
*/
int main()
{
	int input = 0; //레벨
	int NumOrder[1023] = { 0, }; //입력 받을 순서를 저장할 배열
	int LevelCount = 1; // 각 레벨에서 출력해야할 자료의 개수
	int startIndex = 0; //인덱스 몇번부터 시작할지 저장할 변수
	int plusIndex = 0; // 각 레벨에서 인덱스 사이 거리를 저장하는 변수
	scanf("%d", &input);
	int Sum = (pow(2, input) - 1); //총 자료의 개수;
	int imsi;
	for (int i = 0;i < Sum; i++)
	{
		scanf("%d", &imsi);
		NumOrder[i] = imsi;
	}
	for (int i = 1; i <= input;i++) 
	{
		if (i == 1)
		{
			printf("%d\n", NumOrder[Sum / 2]);
			continue;
		}
		LevelCount *= 2; //레벨의 개수는 내려갈 수록 2배 
		plusIndex = pow(2, input - i + 1);// 레벨을 거꾸로 생각
		startIndex = plusIndex / 2 - 1; //인덱스가 0번 부터 시작하기 때문에 -1
		for (int j = 0; j < LevelCount;j++)
		{	
			printf("%d ", NumOrder[startIndex]);
			startIndex += plusIndex;
		}
		printf("\n");
	}

}