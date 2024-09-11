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
#pragma region ���� �Լ�
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
	// 	printf("list [%d]�� �� : %d\n", i, list[i]);
	// }
#pragma endregion

#pragma region ������ �迭
	// const char* dialog[SIZE];
	// 
	// dialog[0] = "�ȳ��ϼ���?";
	// dialog[1] = "�����Ű���?";
	// dialog[2] = "Ž���Դϴ�.";
	// dialog[3] = "Ž���� �� �� �����ּ���";
	// dialog[4] = "���� ���̽Ű���?";
	// dialog[5] = "������ �� ����̸� �׿����";
	// dialog[6] = "������� �̸�����";
	// dialog[7] = "���̿���.";
	// dialog[8] = "���̴¿�?";
	// dialog[9] = "5���̿���.";
	// 
	// // Ž�� [5] ���
	// // �Ƿ��� [5] ���
	// 
	// // �����̽� -> �Ƿ��� ���
	// 
	// int i = 0;
	// 
	// while (i < SIZE)
	// {
	// 	// 0x0000 : ������ ���� ���� ���� ȣ�� �������� �������� ���� ����
	// 
	// 	// 0x0001 : ������ ���� ���� �ְ� ȣ�� �������� �������� ���� ����
	// 
	// 	// 0x8000 : ������ ���� ���� ���� ȣ�� �������� �����ִ� ����
	// 
	// 	// 0x8001 : ������ ���� ���� �ְ� ȣ�� �������� �����ִ� ����
	// 	
	// 	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	// 	{
	// 		if (i % 2 == 0)
	// 		{
	// 			printf("Ž�� : %s\n", dialog[i]);
	// 		}
	// 		else
	// 		{
	// 			printf("�Ƿ��� : %s\n", dialog[i]);
	// 		}
	// 
	// 		i++;
	// 	}
	// 
	// }
	// 
	// Sleep(3000);
	// 
	// printf("��ȭ�� ����Ǿ����ϴ�.\n");

#pragma endregion



	return 0;
}