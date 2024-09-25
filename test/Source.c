#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 10000

int i = 0;
int clothes;
int vehicle;
int likeability = 0;
char heroine[10];
char maincharacter[10];
char dialog1_1[100];
char dialog1_2[100];
char dialog1_3[100];
char dialog1_4[100];
char dialog1_5[100];

int main()
{

	const char* dialog[SIZE];

	dialog[0] = "저.. 혹시";
	strcpy_s(dialog1_1, "%s%s");
	strcpy_s(dialog1_2, dialog[0]);
	strcpy_s(dialog1_3, heroine);
	strcpy_s(dialog1_4, "님이신가요?");
	dialog1_5 = dialog1_1 + dialog1_2 + dialog1_3 + dialog1_4;
	dialog[1] = "어! 네네! &&님이시죠?";
	dialog[2] = "네! 아 먼저 자리에 앉아도 될까요?";
	dialog[3] = "네네 편하게 앉으세요!";
	dialog[4] = "";
	dialog[5] = "";
	dialog[6] = "";
	dialog[7] = "";
	dialog[8] = "";
	dialog[9] = "";

	// 탐정 [5] 대사
	// 의뢰인 [5] 대사

	// 스페이스 -> 의뢰인 대사

	printf("당신의 이름은? ");
	scanf_s("%s", &maincharacter,100);

	printf("소개팅녀의 이름은? ");
	scanf_s("%s", &heroine,100);

	printf("%s %s", maincharacter, heroine);
	system("mode con: cols=100 lines=50");

	while (i < SIZE)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			if (i % 2 == 1)
			{
				printf("나 : %s\n", dialog[i]);
			}
			else if (i % 2 == 0)
			{
				printf("소개팅녀 : %s\n", dialog[i]);
			}

			i++;
		}

	}
	return 0;
}