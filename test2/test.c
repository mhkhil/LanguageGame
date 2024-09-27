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
    while (getchar() != '\n'); // �Է� ���� ����

    switch (clothes)
    {
    case 1:
        Load("����.txt");
        likeability += 1;
        printf("  --------------------------------------------------------------------\n");
        printf(" | ���� �ڵ巯���� �����԰� ��������~!                                |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� + 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    case 2:
        Load("�Ƶ�ٽ�.txt");
        likeability -= 3;
        printf("  --------------------------------------------------------------------\n");
        printf(" | ���� ���� �� �ְ���!! �Ƶ�ٽ� Ʈ���̴׺� �ʷ� ���ߴ�!             |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    case 3:
        Load("ĳ�־�.txt");
        likeability += 3;
        printf("  ------------------------------------------------------------------------\n");
        printf(" | �Ұ��÷��� ������ ĳ�־������! �����Ʈ���ٰ� �� ������ ����߰ڴ�! |\n");
        printf(" |                                                                        |\n");
        printf(" | ȣ���� + 3                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        break;
    default:
        Load("���.txt");
        likeability -= 10;
        printf("  --------------------------------------------------------------------\n");
        printf(" | �߰� ���� ������!!                                                 |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    }
}

void Vehicle()
{
    printf("  --------------------------------------------------------------------\n");
    printf(" | �غ��ϴ� ���� �ð��� ��ü�ƴ�! ������ Ÿ�� ���� �ұ�?              |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. �ý� 2. ����ö 3. ����                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  �� ����� ������? ");
    scanf_s("%d", &vehicle);
    while (getchar() != '\n'); // �Է� ���� ����

    switch (vehicle)
    {
    case 1:
        likeability += 3;
        printf(" | ȣ���� + 3                                                         |\n");
        break;
    case 2:
        likeability -= 1;
        printf(" | ȣ���� - 1                                                         |\n");
        break;
    case 3:
        likeability -= 3;
        printf(" | ȣ���� - 3                                                         |\n");
        break;
    default:
        likeability -= 10;
        printf(" | ȣ���� - 10                                                        |\n");
        break;
    }
}

int main()
{
    char dialog[5][100]; // ��ȭ ������ ���� �迭 (5���� ��ȭ)

    printf("����� �̸���? ");
    scanf_s("%s", maincharacter, sizeof(maincharacter));
    while (getchar() != '\n'); // �Է� ���� ����

    printf("�Ұ��ó��� �̸���? ");
    scanf_s("%s", heroine, sizeof(heroine));
    while (getchar() != '\n'); // �Է� ���� ����

    // ��ȭ ���� �ʱ�ȭ
    sprintf_s(dialog[0], sizeof(dialog[0]), "%s���̽Ű���?", heroine);
    sprintf_s(dialog[1], sizeof(dialog[1]), "��! �׳�! %s���̽���?", heroine);
    sprintf_s(dialog[2], sizeof(dialog[2]), "��! �� ���� �ڸ��� �ɾƵ� �ɱ��?");
    sprintf_s(dialog[3], sizeof(dialog[3]), "�׳� ���ϰ� ��������!");
    sprintf_s(dialog[4], sizeof(dialog[4]), "����! %s�� �߿� �������� �־��!", maincharacter);

    while (i < 5) // ��ȭ ���� �°� ����
    {
        system("mode con: cols=100 lines=50");
        if (GetAsyncKeyState(VK_SPACE) & 0x0001)
        {
            system("cls");
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
            else if (i % 2 == 1)
            {
                printf("�� : %s\n", dialog[i]);
            }
            else if (i % 2 == 0)
            {
                printf("�Ұ��ó� : %s\n", dialog[i]);
            }

            i++;
            getchar(); // ���� ��� �� ���
        }
    }

    return 0;
}