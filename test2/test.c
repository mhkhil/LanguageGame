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

void Clothes()
{
    textcolor(darkBLUE);
    Load("옷.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  --------------------------------------------------------------------\n");
    printf(" | 오늘은 친구가 주선해준 소개팅에 가는 날이다. 무엇을 입고 가야할까? |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. 정장 2. 츄리닝 3. 캐주얼                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  ☞ 당신의 선택은? ");
    scanf_s("%d", &clothes);
    getchar(); // 입력 버퍼 비우기
    system("cls");

    switch (clothes)
    {
    case 1:
        textcolor(GRAY);
        Load("정장.txt");
        likeability += 1;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 정장 멋드러지게 차려입고 나가야지~!                                |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 + 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        textcolor(SkyBlue);
        Load("아디다스.txt");
        likeability -= 3;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 역시 편한 게 최고지!! 아디다스 트레이닝복 너로 정했다!             |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        textcolor(YELLOW);
        Load("캐주얼2.txt");
        likeability += 3;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | 소개팅룩의 정석은 캐주얼룩이지! 브라운니트에다가 흰 팬츠로 맞춰야겠다! |\n");
        printf(" |                                                                        |\n");
        printf(" | 호감도 + 3                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(DarkRed);
        Load("경고.txt");
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 발가 벗고 나갔다!!                                                 |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

void Vehicle()
{
    Load("고민.txt");
    textcolor(WHITE);
    printf("  --------------------------------------------------------------------\n");
    printf(" | 준비하다 보니 시간이 지체됐다! 어떻게 가야 할까?                   |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. 택시 2. 지하철 3. 도보                                          |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  ☞ 당신의 선택은? ");
    scanf_s("%d", &vehicle);
    getchar(); // 입력 버퍼 비우기
    system("cls");

    switch (vehicle)
    {
    case 1:
        likeability += 3;
        Load("택시.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 택시! 택시! 다행히 약속시간보다 10분 일찍 갈 수 있었다..!          |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 + 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        likeability -= 1;
        Load("지하철.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 눈 앞에서 지하철을 놓쳐서 5분 늦어버렸다...                        |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        likeability -= 3;
        Load("보도.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 내 발걸음은 너무 느렸다.. 10분이나 늦어버렸어..                    |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(DarkGreen);
        likeability -= 10;
        Load("거북이.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 거북이를 타고 갔다! 고마워 거북아! 하지만 30분을 늦어버렸어..      |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

void Onethings()
{
    textcolor(darkBLUE);
    Load("소개팅.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  ----------------------------------------------------------------\n");
    printf(" | 인생에서 가장 중요한 것의 질문에 뭐라고 대답해야 할까?         |\n");
    printf(" |                                                                |\n");
    printf(" | 1.가족   2.미쿠쨩   3.%s님                                      |\n", heroine);
    printf("  ----------------------------------------------------------------\n");
    printf("  ☞ 당신의 선택은? ");
    scanf_s("%d", &onething);
    getchar(); // 입력 버퍼 비우기
    system("cls");

    switch (onething)
    {
    case 1:
        textcolor(RED);
        printf("소개팅녀 : 어머~ 따수워라~ 저도 가족이 제일 중요한 것 같아요!");
        getchar();
        likeability += 3;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 다행히 대답을 잘 한 것 같아!                                       |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 + 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        textcolor(RED);
        printf("소개팅녀 : 아.. ㅎㅎ.. 아 밖에 비오는 것 같은데 이제 슬슬 집가봐야하나..");
        getchar();
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 미쿠쨩 난 널 배신하지 않았어!                                      |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 10                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        textcolor(RED);
        printf("소개팅녀 : 응? ㅎㅎ 감사해요~");
        getchar();
        likeability += 1;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | 와 나 방금 엄청 센스있었어 |\n");
        printf(" |                                                                        |\n");
        printf(" | 호감도 + 1                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(DarkRed);
        Load("경고.txt");
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 발가 벗고 나갔다!!                                                 |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

int main()
{
    char dialog[5][100]; // 대화 저장을 위한 배열 (5개의 대화)
    textcolor(BLUE);

    PlaySound(TEXT("이마트-노래.wav"), NULL, SND_ASYNC | SND_LOOP);

    printf("당신의 이름은? ");
    scanf_s("%s", maincharacter, sizeof(maincharacter));
    while (getchar() != '\n'); // 입력 버퍼 비우기

    textcolor(RED);
    printf("소개팅녀의 이름은? ");
    scanf_s("%s", heroine, sizeof(heroine));
    while (getchar() != '\n'); // 입력 버퍼 비우기

    // 대화 내용 초기화
    sprintf_s(dialog[0], sizeof(dialog[0]), "%s님이신가요?", heroine);
    sprintf_s(dialog[1], sizeof(dialog[1]), "어! 네네! %s님이시죠?", maincharacter);
    sprintf_s(dialog[2], sizeof(dialog[2]), "네! 아 먼저 자리에 앉아도 될까요?");
    sprintf_s(dialog[3], sizeof(dialog[3]), "네네 편하게 앉으세요!");
    sprintf_s(dialog[4], sizeof(dialog[4]), "흠... 일단 뭐 좀 시켜볼까요?");
    sprintf_s(dialog[5], sizeof(dialog[5]), "네! 저는 돌체라떼요!");
    sprintf_s(dialog[6], sizeof(dialog[6]), "음.. 전 녹차라떼요..!");
    sprintf_s(dialog[7], sizeof(dialog[7]), ".....");
    sprintf_s(dialog[8], sizeof(dialog[8]), "..........");

while (i < 1000) // 대화 수에 맞게 조정
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
            Load("카페.txt");
            printf("  ----------------------------------------------------------------------------------\n");
            printf(" | 만나기로 한 카페에 들어가보니 한 여성분이 기다리고 계신다. 말을 걸어봐야겠다!    |\n");
            printf("  ----------------------------------------------------------------------------------\n");
            getchar();
            system("cls");
        }
        else if (i == 2)
        {
            Load("카페.txt");
            printf("  ----------------------------------------------------------------------------------\n");
            printf(" | 만나기로 한 카페에 들어가보니 한 여성분이 기다리고 계신다. 말을 걸어봐야겠다!    |\n");
            printf("  ----------------------------------------------------------------------------------\n");
            getchar();
            system("cls");
        }
        else if (i == 3)
        {
            textcolor(BLUE);
            printf("나 : % s님이신가요 ? ", heroine);
            getchar();
            textcolor(RED);
            printf("소개팅녀 : 어! 네네! % s님이시죠 ? ", maincharacter);
            getchar();
            textcolor(BLUE);
            printf("나 : 네! 아 먼저 자리에 앉아도 될까요 ?");
            getchar();
            textcolor(RED);
            printf("소개팅녀 : 네네 편하게 앉으세요 !");
            getchar();
            textcolor(BLUE);
            printf("나 : 흠... 일단 뭐 좀 시켜볼까요 ?");
            getchar();
            textcolor(RED);
            printf("소개팅녀 : 네! 저는 돌체라떼요 !");
            getchar();
            textcolor(BLUE);
            printf("나 : 음.. 전 녹차라떼요..! 제가 계산하고 올게요 !");
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
            printf("나 : 읏차 계산하고 왔습니다 !");
            getchar();
            textcolor(RED);
            printf("소개팅녀 : 오~! 수고하셨어요 !");
            getchar();
            textcolor(BLUE);
            printf("나 : ㅎㅎ.....");
            getchar();
            textcolor(RED);
            printf("소개팅녀 : ㅎㅎㅎ............");
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 이럴수가 만난 지 1분도 채 안돼서 어색한 정적이 찾아왔다.           |\n");
            printf(" |                                                                    |\n");
            printf(" | 빨리 대화 주제를 찾아야 해!                                        |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
            textcolor(RED);
            printf("소개팅녀 : 아! 혹시 %s님의 인생에서 가장 중요한 것은 뭔가요? ", maincharacter);
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 엇 이 말 어디선가 들은 적 있는데?                                  |\n");
            printf(" |                                                                    |\n");
            printf(" | 일단 대답을 해보자!                                                |\n");
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