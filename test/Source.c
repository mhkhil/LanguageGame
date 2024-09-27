#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE 10000

int i = 0;
int clothes;
int vehicle;
int likeability = 0;
char heroine[50]; // 소개팅녀의 이름을 저장할 배열
char maincharacter[50]; // 사용자 이름을 저장할 배열

void Load(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다: %s\n", fileName);
        return;
    }

    char buffer[SIZE] = { 0, };
    fread(buffer, 1, SIZE, file);
    printf("%s", buffer);
    fclose(file);
}

// 옷 선택 함수
void Clothes()
{
    Load("clothes1.txt");

    printf("\n");
    printf("  --------------------------------------------------------------------\n");
    printf(" | 오늘은 친구가 주선해준 소개팅에 가는 날이다. 무엇을 입고 가야할까? |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. 정장 2. 츄리닝 3. 캐주얼                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  ☞ 당신의 선택은? ");
    scanf_s("%d", &clothes);

    switch (clothes)
    {
    case 1:
        Load("정장.txt");
        likeability += 1;
        break;
    case 2:
        Load("아디다스.txt");
        likeability -= 3;
        break;
    case 3:
        Load("캐주얼.txt");
        likeability += 3;
        break;
    default:
        Load("경고.txt");
        likeability -= 10;
        break;
    }
}

// 차량 선택 함수
void Vehicle()
{
    printf("  --------------------------------------------------------------------\n");
    printf(" | 준비하다 보니 시간이 지체됐다! 무엇을 타고 가야 할까?              |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. 택시 2. 지하철 3. 보도                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  ☞ 당신의 선택은? ");
    scanf_s("%d", &vehicle);

    switch (vehicle)
    {
    case 1: printf("호감도 + 3");
        likeability += 3;
        _getchar();
        break;
    case 2: printf("호감도 - 1");
        likeability -= 1;
        _getchar();
        break;
    case 3: printf("호감도 -3");
        likeability -= 3;
        _getchar();
        break;
    default: printf("호감도 - 10");
        likeability -= 10;
        _getchar();
        break;
    }
}

int main()
{
    char dialog[5][100]; // 대화 저장을 위한 배열 (5개의 대화)

    printf("당신의 이름은? ");
    scanf_s("%s", maincharacter, sizeof(maincharacter));

    printf("소개팅녀의 이름은? ");
    scanf_s("%s", heroine, sizeof(heroine));

    // 대화 내용 초기화
    sprintf_s(dialog[0], sizeof(dialog[0]), "%s님이신가요?", heroine);
    sprintf_s(dialog[1], sizeof(dialog[1]), "어! 네네! %s님이시죠?", heroine);
    sprintf_s(dialog[2], sizeof(dialog[2]), "네! 아 먼저 자리에 앉아도 될까요?");
    sprintf_s(dialog[3], sizeof(dialog[3]), "네네 편하게 앉으세요!");
    sprintf_s(dialog[4], sizeof(dialog[4]), "으악! %s씨 발에 바퀴벌레 있어요!", maincharacter);

    // 대화 진행
    while (i < 5) // 대화 수에 맞게 조정
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
                    printf(" | 만나기로 한 카페에 들어가보니 한 여성분이 기다리고 계신다. 말을 걸어봐야겠다!              |\n");
                    printf("  --------------------------------------------------------------------\n");
                }

                // 대화 출력
                if (i % 2 == 0)
                {
                    printf("소개팅녀 : %s\n", dialog[i]);
                }
                else
                {
                    printf("나 : %s\n", dialog[i]);
                }
                i++;
            }
        }
    }

    // 프로그램 종료 전에 대기
    printf("대화가 끝났습니다. 아무 키나 눌러서 종료하세요...\n");
    getchar(); // 개행 문자를 처리
    getchar(); // 입력 대기

    return 0;
}