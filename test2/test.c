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
int communication;
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
    printf(" | 무엇을 입고 가야할까?                                              |\n");
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
    Load("소개팅2.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  ----------------------------------------------------------------\n");
    printf(" | 인생에서 가장 중요한 것의 질문에 뭐라고 대답해야 할까?         |\n");
    printf(" |                                                                |\n");
    printf(" | 1.가족   2.미쿠쨩   3.%s씨                                  |\n", heroine);
    printf("  ----------------------------------------------------------------\n");
    printf("  ☞ 당신의 선택은? ");
    scanf_s("%d", &onething);
    getchar(); // 입력 버퍼 비우기
    system("cls");

    switch (onething)
    {
    case 1:
        textcolor(RED);
        printf("%s : 어머~ 따수워라~ 저도 가족이 제일 중요한 것 같아요!\n", heroine);
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
        printf("%s : 아.. ㅎㅎ.. 아 밖에 비오는 것 같은데 이제 슬슬 집가봐야하나..\n", heroine);
        getchar();
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 미쿠쨩 난 널 배신하지 않았어!                                      |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        textcolor(RED);
        printf("%s : 응? ㅎㅎ 감사해요~\n", heroine);
        getchar();
        likeability += 1;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | 와 나 방금 엄청 센스있었어                                             |\n");
        printf(" |                                                                        |\n");
        printf(" | 호감도 + 1                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(RED);
        printf("%s : ... 왜 대답을 안 하시지?\n", heroine);
        getchar();
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | %s씨 말을 무시해버렸다..                                       |\n", heroine);
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

void Communication()
{
    textcolor(WHITE);
    Load("소개팅2.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  ----------------------------------------------------------------\n");
    printf(" | 연인 사이의 연락 수단으로 어떤 것을 선호하냐는                 |\n");
    printf(" | 질문에 뭐라고 대답해야 할까?                                   |\n");
    printf(" | 1.카톡   2.전화   3.영상통화                                   |\n");
    printf("  ----------------------------------------------------------------\n");
    printf("  ☞ 당신의 선택은? ");
    scanf_s("%d", &communication);
    getchar(); // 입력 버퍼 비우기
    system("cls");

    switch (communication)
    {
    case 1:
        textcolor(RED);
        printf("%s : 오! 카톡 좋죠! 저도 카톡이 제일 편한 것 같아요\n", heroine);
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
        printf("%s : 전화도 애틋하긴 한데 끊을 타이밍을 못 잡겠더라고요..ㅎㅎ\n", heroine);
        getchar();
        likeability += 1;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 살짝 시큰둥하시지만 잘 대답한 것 같아!                             |\n");
        printf(" |                                                                    |\n");
        printf(" | 호감도 + 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        textcolor(RED);
        printf("%s : 영상통화는.. 음.. 전 조금 부담스러운 것 같아요\n", heroine);
        getchar();
        likeability -= 3;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | 영상통화가 어때서                                                      |\n");
        printf(" |                                                                        |\n");
        printf(" | 호감도 - 3                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(RED);
        printf("%s : ... 왜 대답을 안 하시지?\n", heroine);
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | %s씨 말을 무시해버렸다..                                       |\n", heroine);
        printf(" |                                                                    |\n");
        printf(" | 호감도 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

void Ending()
{
    textcolor(WHITE);
    Load("도시.txt");

    textcolor(WHITE);
    printf("  ----------------------------------------------------------------\n");
    printf(" | 어느덧 소개팅을 한 지 일주일이 지났다.                         |\n");
    printf(" | 받은 연락은 0통..                                              |\n");
    printf(" | 아아 난 이번에도 실패인 것인가                                 |\n");
    printf("  ----------------------------------------------------------------\n");
    getchar();
    textcolor(YELLOW);
    printf(" \a 띠링♬ ");
    getchar(); // 입력 버퍼 비우기
    textcolor(WHITE);
    printf("  ----------------------------------------------------------------\n");
    printf(" | 무슨 연락이지?                                                 |\n");
    printf("  ----------------------------------------------------------------\n");
    getchar();
    system("cls");

    if (likeability >= 12)
    {
        textcolor(SkyBlue);
        printf("해피엔딩 잠금해제\n");
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | ??? : 저...                                                    |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 엇 이 분은 %s씨?                                            |\n", heroine);
        printf(" |                                                                |\n");
        printf(" | 뭐지? 그린라이트인가?                                          |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 누구세요                                               |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 저번에 소개팅 했던 %s인데요..                       |\n", heroine, heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 일주일동안 연락 못 드려서 죄송해요..                   |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 생각할 시간이 필요했어요...                            |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 사실.. 저도 소개팅이 처음이거든요..                    |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 역시                                                           |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 사실 그 날도 길작가님이 쓰신                          |\n", heroine);
        printf(" | \"모쏠들을 위한 소개팅 대화법\" 12회독 하고 왔었어요..           |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 나보다 더 하네                                                 |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 그래서.. 음...                                        |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 음..... 어.......                                     |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 으으.........                                         |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 우리 만날래요?                                        |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 난 그대로 몸이 굳어버렸고 내 눈에선 눈물이 흘러나왔다           |\n");
        printf(" |                                                                 |\n");
        printf(" | 진짜.. 이젠 진짜로 '사랑'이라는 것을 하는구나                   |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 좋아요..!                                              |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 그 이후 우리들은 서로의 첫사랑이 되었다..                       |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
    }
    else if (likeability >= 2)
    {
        textcolor(SkyBlue);
        printf("노멀엔딩 잠금해제\n");
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 엇 %s씨한테서 온 카톡이다.                                   |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 안녕하세요                                              |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 어 %s씨 오랜만이네요 ㅎㅎ                              |\n", maincharacter, heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 일주일동안 연락이 없었죠? 바빠서 연락을 못 드렸어요     |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 네.. 요즘 잘 지내요? 얼굴 한 번 보고싶네                |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 그것보다 %s님한테만 알려드릴 게 있어요                |\n", heroine, maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 엇 뭐죠?                                                |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : **보험에 좋은 제품이 있는데..                           |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 알고보니 %s씨는 보험회사직원이었고 난 눈물을 흘리며          |\n", heroine);
        printf(" | 계속 들어주다가 차단하고 대화삭제를 눌렀다..                   |\n");
        printf(" | 아직 나에게 사랑은 이른가보다..                                |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
    }
    else if (likeability >= -19)
    {
        textcolor(SkyBlue);
        printf("배드엔딩 잠금해제\n");
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 아 뭐야 소개팅을 주선해준 친구, 철구의 연락이었다.             |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(GREEN);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 철구 : 야야 잘됐냐                                             |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 겠냐고.. 하 진짜 일주일동안 연락없는데 망한거지?      |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(GREEN);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 철구 : ㅋㅋ 모쏠쉑 그럴 줄 알았다                              |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 하.. 맥주 한 잔 하자..                                |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(GREEN);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 철구 : ㅇㅋㅇㅋ 지금 내려와                                    |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 난 다시 평범한 일상으로 돌아왔고                               |\n");
        printf(" |                                                                |\n");
        printf(" | %s씨는 아픈 추억으로 가슴 속에 깊이 묻어두기로 했다            |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
    }
    else if (likeability >= -40)
    {
        textcolor(SkyBlue);
        printf("히든엔딩 잠금해제\n");
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 어?????                                                        |\n");
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : %s님 혹시 지금 밖으로 나와줄 수 있어요?             |\n", heroine, maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 난 급히 옷을 갈아입고 집 밖에 찾아온 %s씨에게로 달려갔다.   |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 안녕하세요..ㅎㅎ                                       |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 안녕하세요...ㅎㅎ                                      |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 갑자기 어쩐일로 찾아오신거죠?                          |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 사실..                                                 |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : %s님의 취향을 보고 반해버렸어요!!                    |\n", heroine, maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 에?                                                    |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 사실.. 저도.. 좋아하거든요.. 미쿠쨩..                  |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 에?                                                    |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 제 이상형이 오래도록 미쿠쨩 좋아하는 사람이었어요..  |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 에?                                                    |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(RED);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 사귀어 주세요!! //> <//                                |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(BLUE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | %s : 에?                                                    |\n", maincharacter);
        printf("  ----------------------------------------------------------------\n");
        getchar();
        textcolor(WHITE);
        printf("  ----------------------------------------------------------------\n");
        printf(" | 그렇게 우리는 나, %s씨, 미쿠쨩 셋이서 오래오래 행복했다.        |\n", heroine);
        printf("  ----------------------------------------------------------------\n");
        getchar();
    }
}

int main()
{
    char dialog[5][100]; // 대화 저장을 위한 배열 (5개의 대화)
    textcolor(BLUE);

    PlaySound(TEXT("이마트-노래.wav"), NULL, SND_ASYNC | SND_LOOP);

    printf("\n");
    textcolor(WHITE);
    Load("커버3.txt");
    printf("          시작하려면 Enter를 누르세요...");

    getchar();
    system("cls");

    textcolor(BLUE);
    printf("당신의 이름은? (3글자 입력)");
    textcolor(WHITE);
    Load("실루엣.txt");
    scanf_s("%s", maincharacter, sizeof(maincharacter));
    while (getchar() != '\n'); // 입력 버퍼 비우기
    system("cls");

    textcolor(RED);
    printf("소개팅녀의 이름은? (3글자 입력)");
    textcolor(WHITE);
    Load("여자 실루엣.txt");
    scanf_s("%s", heroine, sizeof(heroine));
    while (getchar() != '\n'); // 입력 버퍼 비우기
    system("cls");

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
            printf("  --------------------------------------------------------------------\n");
            printf(" | 오늘은 친구가 주선해준 소개팅에 가는 날이다.                       |\n");
            printf(" |                                                                    |\n");
            printf(" | 평생 모쏠을 살아온 암흑같은 내게 단비같은 기회가 찾아왔다.         |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 오늘을 위해 길작가가 쓴 베스트셀러 \"모쏠들을 위한 소개팅 대화법\"을 |\n");
            printf(" |                                                                    |\n");
            printf(" | 6회독하고 왔다.                                                    |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 10시까지 만나기로 했고 지금 시각은 현재 7시 반.                    |\n");
            printf(" |                                                                    |\n");
            printf(" | 나갈 때 무슨 옷을 입고 갈지 정하자.                                |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
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
        else if (i == 3)
        {
            textcolor(BLUE);
            printf("%s : % s씨이신가요 ? ",maincharacter, heroine);
            getchar();
            textcolor(RED);
            printf("%s : 어! 네네! % s님이시죠 ? ",heroine, maincharacter);
            getchar();
            textcolor(BLUE);
            printf("%s : 네! 아 먼저 자리에 앉아도 될까요 ?", maincharacter);
            getchar();
            textcolor(RED);
            printf("%s : 네네 편하게 앉으세요 !", heroine);
            getchar();
            textcolor(BLUE);
            printf("%s : 흠... 일단 뭐 좀 시켜볼까요 ?", maincharacter);
            getchar();
            textcolor(RED);
            printf("%s : 네! 저는 돌체라떼요 !", heroine);
            getchar();
            textcolor(BLUE);
            printf("%s : 음.. 전 녹차라떼요..! 제가 계산하고 올게요 !", maincharacter);
            getchar();
            textcolor(WHITE);
            printf(".");
            getchar();
            printf(".");
            getchar();
            printf(".");
            getchar();
            textcolor(BLUE);
            printf("%s : 읏차 계산하고 왔습니다 !", maincharacter);
            getchar();
            textcolor(RED);
            printf("%s : 오~! 수고하셨어요 !", heroine);
            getchar();
            textcolor(BLUE);
            printf("%s : ㅎㅎ.....", maincharacter);
            getchar();
            textcolor(RED);
            printf("%s : ㅎㅎㅎ............", heroine);
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 이럴수가 만난 지 1분도 채 안돼서 어색한 정적이 찾아왔다.           |\n");
            printf(" |                                                                    |\n");
            printf(" | 빨리 대화 주제를 찾아야 해!                                        |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
            textcolor(RED);
            printf("%s : 아! 혹시 %s님의 인생에서 가장 중요한 것은 뭔가요? ", heroine, maincharacter);
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
        else if (i == 5)
        {
            textcolor(RED);
            printf("%s : 오~ %s씨에 대해 한 층 더 잘 알게 된 것 같아요", heroine, maincharacter);
            getchar();
            textcolor(BLUE);
            printf("%s : 아하핳 그런가요? 질문 재밌네요 더 아시는 거 있으세요?", maincharacter);
            getchar();
            textcolor(RED);
            printf("%s : %s씨는 연인 사이의 연락 수단으로 어떤 것을 선호하시나요 ? ", heroine, maincharacter);
            getchar();
            system("cls");
        }
        else if(i == 6)
        {
            Communication();
            system("cls");
        }
        else if (i == 7)
        {
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 그런데 생각해보니 이 질문들 어제 본 책에서 읽은 내용이다           |\n");
            printf(" |                                                                    |\n");
            printf(" | %s씨도 알고보니 소개팅이 처음이신 걸까?                        |\n", heroine);
            printf("  --------------------------------------------------------------------\n");
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 우린 2시간 정도 대화를 하다가 %s씨가 갑자기 급한 일이          |\n", heroine);
            printf(" |                                                                    |\n");
            printf(" | 생겼다고 하셔서 각자 집으로 돌아갔다.                              |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
            printf("다음 장에 엔딩이 나옵니다.");
            getchar();
            system("cls");
        }
        else if (i == 8)
        {
            Ending();
            system("cls");
        }
        else if (i == 9)
        {
            Load("웨딩.txt");
            printf("플레이해주셔서 감사합니다!\n");
            getchar();
            break;
        }
        i++;
    }
}
    return 0;
}