#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE 10000

int i = 0;
int clothes;
int vehicle;
int likeability = 0;
char heroine[50]; // �Ұ��ó��� �̸��� ������ �迭
char maincharacter[50]; // ����� �̸��� ������ �迭

void Load(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�: %s\n", fileName);
        return;
    }

    char buffer[SIZE] = { 0, };
    fread(buffer, 1, SIZE, file);
    printf("%s", buffer);
    fclose(file);
}

// �� ���� �Լ�
void Clothes()
{
    Load("clothes1.txt");

    printf("\n");
    printf("  --------------------------------------------------------------------\n");
    printf(" | ������ ģ���� �ּ����� �Ұ��ÿ� ���� ���̴�. ������ �԰� �����ұ�? |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. ���� 2. �򸮴� 3. ĳ�־�                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  �� ����� ������? ");
    scanf_s("%d", &clothes);

    switch (clothes)
    {
    case 1:
        Load("����.txt");
        likeability += 1;
        break;
    case 2:
        Load("�Ƶ�ٽ�.txt");
        likeability -= 3;
        break;
    case 3:
        Load("ĳ�־�.txt");
        likeability += 3;
        break;
    default:
        Load("���.txt");
        likeability -= 10;
        break;
    }
}

// ���� ���� �Լ�
void Vehicle()
{
    printf("  --------------------------------------------------------------------\n");
    printf(" | �غ��ϴ� ���� �ð��� ��ü�ƴ�! ������ Ÿ�� ���� �ұ�?              |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. �ý� 2. ����ö 3. ����                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  �� ����� ������? ");
    scanf_s("%d", &vehicle);

    switch (vehicle)
    {
    case 1: printf("ȣ���� + 3");
        likeability += 3;
        _getchar();
        break;
    case 2: printf("ȣ���� - 1");
        likeability -= 1;
        _getchar();
        break;
    case 3: printf("ȣ���� -3");
        likeability -= 3;
        _getchar();
        break;
    default: printf("ȣ���� - 10");
        likeability -= 10;
        _getchar();
        break;
    }
}

int main()
{
    char dialog[5][100]; // ��ȭ ������ ���� �迭 (5���� ��ȭ)

    printf("����� �̸���? ");
    scanf_s("%s", maincharacter, sizeof(maincharacter));

    printf("�Ұ��ó��� �̸���? ");
    scanf_s("%s", heroine, sizeof(heroine));

    // ��ȭ ���� �ʱ�ȭ
    sprintf_s(dialog[0], sizeof(dialog[0]), "%s���̽Ű���?", heroine);
    sprintf_s(dialog[1], sizeof(dialog[1]), "��! �׳�! %s���̽���?", heroine);
    sprintf_s(dialog[2], sizeof(dialog[2]), "��! �� ���� �ڸ��� �ɾƵ� �ɱ��?");
    sprintf_s(dialog[3], sizeof(dialog[3]), "�׳� ���ϰ� ��������!");
    sprintf_s(dialog[4], sizeof(dialog[4]), "����! %s�� �߿� �������� �־��!", maincharacter);

    // ��ȭ ����
    while (i < 5) // ��ȭ ���� �°� ����
    {
        system("mode con: cols=100 lines=50");
        if (GetAsyncKeyState(VK_SPACE) & 0x0001)
        {
            if (i < 5)
            {
                if (i == 0)
                {
                    Clothes();
                }
                else if (i == 1)
                {
                    Vehicle();
                }
                else if (i == 2)
                {
                    printf("  --------------------------------------------------------------------\n");
                    printf(" | ������� �� ī�信 ������ �� �������� ��ٸ��� ��Ŵ�. ���� �ɾ���߰ڴ�!              |\n");
                    printf("  --------------------------------------------------------------------\n");
                }

                // ��ȭ ���
                if (i % 2 == 0)
                {
                    printf("�Ұ��ó� : %s\n", dialog[i]);
                }
                else
                {
                    printf("�� : %s\n", dialog[i]);
                }
                i++;
            }
        }
    }

    // ���α׷� ���� ���� ���
    printf("��ȭ�� �������ϴ�. �ƹ� Ű�� ������ �����ϼ���...\n");
    getchar(); // ���� ���ڸ� ó��
    getchar(); // �Է� ���

    return 0;
}