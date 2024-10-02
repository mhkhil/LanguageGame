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
int onething;
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
    Load("��.txt");
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
        getchar();
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
        getchar();
        break;
    case 3:
        textcolor(YELLOW);
        Load("ĳ�־�2.txt");
        likeability += 3;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | �Ұ��÷��� ������ ĳ�־������! �����Ʈ���ٰ� �� ������ ����߰ڴ�! |\n");
        printf(" |                                                                        |\n");
        printf(" | ȣ���� + 3                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
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
        getchar();
        break;
    }
}

void Vehicle()
{
    Load("���.txt");
    textcolor(WHITE);
    printf("  --------------------------------------------------------------------\n");
    printf(" | �غ��ϴ� ���� �ð��� ��ü�ƴ�! ��� ���� �ұ�?                   |\n");
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
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | �ý�! �ý�! ������ ��ӽð����� 10�� ���� �� �� �־���..!          |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� + 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        likeability -= 1;
        Load("����ö.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | �� �տ��� ����ö�� ���ļ� 5�� �ʾ���ȴ�...                        |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        likeability -= 3;
        Load("����.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | �� �߰����� �ʹ� ���ȴ�.. 10���̳� �ʾ���Ⱦ�..                    |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(DarkGreen);
        likeability -= 10;
        Load("�ź���.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | �ź��̸� Ÿ�� ����! ���� �źϾ�! ������ 30���� �ʾ���Ⱦ�..      |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

void Onethings()
{
    textcolor(darkBLUE);
    Load("�Ұ���.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  ----------------------------------------------------------------\n");
    printf(" | �λ����� ���� �߿��� ���� ������ ����� ����ؾ� �ұ�?         |\n");
    printf(" |                                                                |\n");
    printf(" | 1.����   2.����»   3.%s��                                      |\n", heroine);
    printf("  ----------------------------------------------------------------\n");
    printf("  �� ����� ������? ");
    scanf_s("%d", &onething);
    getchar(); // �Է� ���� ����
    system("cls");

    switch (onething)
    {
    case 1:
        textcolor(RED);
        printf("�Ұ��ó� : ���~ ��������~ ���� ������ ���� �߿��� �� ���ƿ�!");
        getchar();
        likeability += 3;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | ������ ����� �� �� �� ����!                                       |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� + 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        textcolor(RED);
        printf("�Ұ��ó� : ��.. ����.. �� �ۿ� ����� �� ������ ���� ���� ���������ϳ�..");
        getchar();
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | ����» �� �� ������� �ʾҾ�!                                      |\n");
        printf(" |                                                                    |\n");
        printf(" | ȣ���� - 10                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        textcolor(RED);
        printf("�Ұ��ó� : ��? ���� �����ؿ�~");
        getchar();
        likeability += 1;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | �� �� ��� ��û �����־��� |\n");
        printf(" |                                                                        |\n");
        printf(" | ȣ���� + 1                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
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
        getchar();
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
    sprintf_s(dialog[0], sizeof(dialog[0]), "%s���̽Ű���?", heroine);
    sprintf_s(dialog[1], sizeof(dialog[1]), "��! �׳�! %s���̽���?", maincharacter);
    sprintf_s(dialog[2], sizeof(dialog[2]), "��! �� ���� �ڸ��� �ɾƵ� �ɱ��?");
    sprintf_s(dialog[3], sizeof(dialog[3]), "�׳� ���ϰ� ��������!");
    sprintf_s(dialog[4], sizeof(dialog[4]), "��... �ϴ� �� �� ���Ѻ����?");
    sprintf_s(dialog[5], sizeof(dialog[5]), "��! ���� ��ü�󶼿�!");
    sprintf_s(dialog[6], sizeof(dialog[6]), "��.. �� �����󶼿�..!");
    sprintf_s(dialog[7], sizeof(dialog[7]), ".....");
    sprintf_s(dialog[8], sizeof(dialog[8]), "..........");

while (i < 1000) // ��ȭ ���� �°� ����
{
system("mode con: cols=100 lines=50");
    if (GetAsyncKeyState(VK_RETURN) & 0x0001)
    {
        if (i == 0)
        {
            textcolor(WHITE);
            Clothes();
            system("cls");
        }
        else if (i == 1)
        {
            textcolor(WHITE);
            Vehicle();
            system("cls");
        }
        else if (i == 2)
        {
            Load("ī��.txt");
            printf("  ----------------------------------------------------------------------------------\n");
            printf(" | ������� �� ī�信 ������ �� �������� ��ٸ��� ��Ŵ�. ���� �ɾ���߰ڴ�!    |\n");
            printf("  ----------------------------------------------------------------------------------\n");
            getchar();
            system("cls");
        }
        else if (i == 2)
        {
            Load("ī��.txt");
            printf("  ----------------------------------------------------------------------------------\n");
            printf(" | ������� �� ī�信 ������ �� �������� ��ٸ��� ��Ŵ�. ���� �ɾ���߰ڴ�!    |\n");
            printf("  ----------------------------------------------------------------------------------\n");
            getchar();
            system("cls");
        }
        else if (i == 3)
        {
            textcolor(BLUE);
            printf("�� : % s���̽Ű��� ? ", heroine);
            getchar();
            textcolor(RED);
            printf("�Ұ��ó� : ��! �׳�! % s���̽��� ? ", maincharacter);
            getchar();
            textcolor(BLUE);
            printf("�� : ��! �� ���� �ڸ��� �ɾƵ� �ɱ�� ?");
            getchar();
            textcolor(RED);
            printf("�Ұ��ó� : �׳� ���ϰ� �������� !");
            getchar();
            textcolor(BLUE);
            printf("�� : ��... �ϴ� �� �� ���Ѻ���� ?");
            getchar();
            textcolor(RED);
            printf("�Ұ��ó� : ��! ���� ��ü�󶼿� !");
            getchar();
            textcolor(BLUE);
            printf("�� : ��.. �� �����󶼿�..! ���� ����ϰ� �ðԿ� !");
            getchar();
            textcolor(WHITE);
            printf(".");
            getchar();
            textcolor(WHITE);
            printf(".");
            getchar();
            textcolor(WHITE);
            printf(".");
            getchar();
            textcolor(BLUE);
            printf("�� : ���� ����ϰ� �Խ��ϴ� !");
            getchar();
            textcolor(RED);
            printf("�Ұ��ó� : ��~! �����ϼ̾�� !");
            getchar();
            textcolor(BLUE);
            printf("�� : ����.....");
            getchar();
            textcolor(RED);
            printf("�Ұ��ó� : ������............");
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | �̷����� ���� �� 1�е� ä �ȵż� ����� ������ ã�ƿԴ�.           |\n");
            printf(" |                                                                    |\n");
            printf(" | ���� ��ȭ ������ ã�ƾ� ��!                                        |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
            textcolor(RED);
            printf("�Ұ��ó� : ��! Ȥ�� %s���� �λ����� ���� �߿��� ���� ������? ", maincharacter);
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | �� �� �� ��𼱰� ���� �� �ִµ�?                                  |\n");
            printf(" |                                                                    |\n");
            printf(" | �ϴ� ����� �غ���!                                                |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
        }
        else if (i == 4)
        {
            Onethings();
            system("cls");
        }

        i++;
    }
}

    return 0;
}