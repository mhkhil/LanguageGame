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

	dialog[0] = "��.. Ȥ��";
	strcpy_s(dialog1_1, "%s%s");
	strcpy_s(dialog1_2, dialog[0]);
	strcpy_s(dialog1_3, heroine);
	strcpy_s(dialog1_4, "���̽Ű���?");
	dialog1_5 = dialog1_1 + dialog1_2 + dialog1_3 + dialog1_4;
	dialog[1] = "��! �׳�! &&���̽���?";
	dialog[2] = "��! �� ���� �ڸ��� �ɾƵ� �ɱ��?";
	dialog[3] = "�׳� ���ϰ� ��������!";
	dialog[4] = "";
	dialog[5] = "";
	dialog[6] = "";
	dialog[7] = "";
	dialog[8] = "";
	dialog[9] = "";

	// Ž�� [5] ���
	// �Ƿ��� [5] ���

	// �����̽� -> �Ƿ��� ���

	printf("����� �̸���? ");
	scanf_s("%s", &maincharacter,100);

	printf("�Ұ��ó��� �̸���? ");
	scanf_s("%s", &heroine,100);

	printf("%s %s", maincharacter, heroine);
	system("mode con: cols=100 lines=50");

	while (i < SIZE)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			if (i % 2 == 1)
			{
				printf("�� : %s\n", dialog[i]);
			}
			else if (i % 2 == 0)
			{
				printf("�Ұ��ó� : %s\n", dialog[i]);
			}

			i++;
		}

	}
	return 0;
}