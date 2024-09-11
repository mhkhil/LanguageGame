#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 10

void Shuffle(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int seed = rand() % size;

		int temporary = 0;

		temporary = array[seed];

		array[seed] = array[i];

		array[i] = temporary;
	}
}

int main()
{
#pragma region 셔플 함수
	// [1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
	// int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 
	// srand(time(NULL));
	// 
	// int size = sizeof(list) / sizeof(int);
	// 
	// Shuffle(list, size);
	// 
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("list [%d]의 값 : %d\n", i, list[i]);
	// }
#pragma endregion

#pragma region 포인터 배열
	// const char* dialog[SIZE];
	// 
	// dialog[0] = "안녕하세요?";
	// dialog[1] = "누구신가요?";
	// dialog[2] = "탐정입니다.";
	// dialog[3] = "탐정님 저 좀 도와주세요";
	// dialog[4] = "무슨 일이신가요?";
	// dialog[5] = "누군가 제 고양이를 죽였어요";
	// dialog[6] = "고양이의 이름은요";
	// dialog[7] = "괭이에요.";
	// dialog[8] = "나이는요?";
	// dialog[9] = "5살이에요.";
	// 
	// // 탐정 [5] 대사
	// // 의뢰인 [5] 대사
	// 
	// // 스페이스 -> 의뢰인 대사
	// 
	// int i = 0;
	// 
	// while (i < SIZE)
	// {
	// 	// 0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
	// 
	// 	// 0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
	// 
	// 	// 0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
	// 
	// 	// 0x8001 : 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태
	// 	
	// 	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	// 	{
	// 		if (i % 2 == 0)
	// 		{
	// 			printf("탐정 : %s\n", dialog[i]);
	// 		}
	// 		else
	// 		{
	// 			printf("의뢰인 : %s\n", dialog[i]);
	// 		}
	// 
	// 		i++;
	// 	}
	// 
	// }
	// 
	// Sleep(3000);
	// 
	// printf("대화가 종료되었습니다.\n");

#pragma endregion



	return 0;
}