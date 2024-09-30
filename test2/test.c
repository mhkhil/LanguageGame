#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>

void textcolor(int ColorType) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorType);
}
enum ColorType {
    BLACK,  	//0
    darkBLUE,	//1
    DarkGreen,	//2
    darkSkyBlue,    //3
    DarkRed,  	//4
    DarkPurple,	//5
    DarkYellow,	//6
    GRAY,		//7
    DarkGray,	//8
    BLUE,		//9
    GREEN,		//10
    SkyBlue,	//11
    RED,		//12
    PURPLE,		//13
    YELLOW,		//14
    WHITE		//15
} COLOR;

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
    textcolor(darkBLUE);
    Load("clothes1.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  --------------------------------------------------------------------\n");
    printf(" | ������ ģ���� �ּ����� �Ұ��ÿ� ���� ���̴�. ������ �԰� �����ұ�? |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. ���� 2. �򸮴� 3. ĳ�־�                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  �� ����� ������? ");
    scanf_s("%d", &clothes);
    getchar(); // �Է� ���� ����
    system("cls");

    switch (clothes)
    {
    case 1:
        textcolor(GRAY);
        Load("����.txt");
        likeability += 1;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | ���� �ڵ巯���� �����԰� ��������~!                                |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� + 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    case 2:
        textcolor(SkyBlue);
        Load("�Ƶ�ٽ�.txt");
        likeability -= 3;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | ���� ���� �� �ְ���!! �Ƶ�ٽ� Ʈ���̴׺� �ʷ� ���ߴ�!             |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    case 3:
        textcolor(YELLOW);
        Load("ĳ�־�.txt");
        likeability += 3;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | �Ұ��÷��� ������ ĳ�־������! �����Ʈ���ٰ� �� ������ ����߰ڴ�! |\n");
        printf(" |                                                                        |\n");
        printf(" | ȣ���� + 3                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        break;
    default:
        textcolor(DarkRed);
        Load("���.txt");
        likeability -= 10;
        textcolor(WHITE);
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
    Load("���.txt");
    printf("  --------------------------------------------------------------------\n");
    printf(" | �غ��ϴ� ���� �ð��� ��ü�ƴ�! ������ Ÿ�� ���� �ұ�?              |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. �ý� 2. ����ö 3. ����                                          |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  �� ����� ������? ");
    scanf_s("%d", &vehicle);
    getchar(); // �Է� ���� ����
    system("cls");

    switch (vehicle)
    {
    case 1:
        likeability += 3;
        Load("�ý�.txt");
        printf("  --------------------------------------------------------------------\n");
        printf(" | �ý�! �ý�! ������ ��ӽð����� 10�� ���� �� �� �־���..!          |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� + 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    case 2:
        likeability -= 1;
        Load("����ö.txt");
        printf("  --------------------------------------------------------------------\n");
        printf(" | �� �տ��� ����ö�� ���ļ� 5�� �ʾ���ȴ�...                        |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    case 3:
        likeability -= 3;
        Load("����.txt");
        printf("  --------------------------------------------------------------------\n");
        printf(" | �� �߰����� �ʹ� ���ȴ�.. 10���̳� �ʾ���Ⱦ�..                    |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    default:
        likeability -= 10;
        Load("�ź���.txt");
        printf("  --------------------------------------------------------------------\n");
        printf(" | �ź��̸� Ÿ�� ����! ���� �źϾ�! ������ 30���� �ʾ���Ⱦ�..      |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        break;
    }
}

int main()
{
    char dialog[5][100]; // ��ȭ ������ ���� �迭 (5���� ��ȭ)
    textcolor(BLUE);

    PlaySound(TEXT("�̸�Ʈ-�뷡.wav"), NULL, SND_ASYNC | SND_LOOP);

    printf("����� �̸���? ");
    scanf_s("%s", maincharacter, sizeof(maincharacter));
    while (getchar() != '\n'); // �Է� ���� ����

    textcolor(RED);
    printf("�Ұ��ó��� �̸���? ");
    scanf_s("%s", heroine, sizeof(heroine));
    while (getchar() != '\n'); // �Է� ���� ����

    // ��ȭ ���� �ʱ�ȭ
    textcolor(BLUE);
    sprintf_s(dialog[0], sizeof(dialog[0]), "%s���̽Ű���?", heroine);
    textcolor(RED);
    sprintf_s(dialog[1], sizeof(dialog[1]), "��! �׳�! %s���̽���?", heroine);
    textcolor(BLUE);
    sprintf_s(dialog[2], sizeof(dialog[2]), "��! �� ���� �ڸ��� �ɾƵ� �ɱ��?");
    textcolor(RED);
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
                textcolor(WHITE);
                Clothes();
            }
            else if (i == 1)
            {
                textcolor(WHITE);
                Vehicle();
                getchar();
                system("cls");
            }
            else if (i == 2)
            {
                Load("�ź���.txt");
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