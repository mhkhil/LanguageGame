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
char heroine[50]; // 社鯵特橿税 戚硯聖 煽舌拝 壕伸
char maincharacter[50]; // 紫遂切 戚硯聖 煽舌拝 壕伸

void Load(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("督析聖 伸 呪 蒸柔艦陥: %s\n", fileName);
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
    Load("進.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  --------------------------------------------------------------------\n");
    printf(" | 神潅精 庁姥亜 爽識背層 社鯵特拭 亜澗 劾戚陥. 巷譲聖 脊壱 亜醤拝猿? |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. 舛舌 2. 鋳軒閑 3. 蝶爽杖                                        |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  �� 雁重税 識澱精? ");
    scanf_s("%d", &clothes);
    getchar(); // 脊径 獄遁 搾酔奄
    system("cls");

    switch (clothes)
    {
    case 1:
        textcolor(GRAY);
        Load("舛舌.txt");
        likeability += 1;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 舛舌 鈷球君走惟 託形脊壱 蟹亜醤走~!                                |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 + 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        textcolor(SkyBlue);
        Load("焼巨陥什.txt");
        likeability -= 3;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 蝕獣 畷廃 惟 置壱走!! 焼巨陥什 闘傾戚閑差 格稽 舛梅陥!             |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        textcolor(YELLOW);
        Load("蝶爽杖2.txt");
        likeability += 3;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | 社鯵特決税 舛汐精 蝶爽杖決戚走! 崎虞錘艦闘拭陥亜 避 寅苧稽 限仲醤畏陥! |\n");
        printf(" |                                                                        |\n");
        printf(" | 硲姶亀 + 3                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(DarkRed);
        Load("井壱.txt");
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 降亜 込壱 蟹穐陥!!                                                 |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

void Vehicle()
{
    Load("壱肯.txt");
    textcolor(WHITE);
    printf("  --------------------------------------------------------------------\n");
    printf(" | 層搾馬陥 左艦 獣娃戚 走端菊陥! 嬢胸惟 亜醤 拝猿?                   |\n");
    printf(" |                                                                    |\n");
    printf(" | 1. 澱獣 2. 走馬旦 3. 亀左                                          |\n");
    printf("  --------------------------------------------------------------------\n");
    printf("  �� 雁重税 識澱精? ");
    scanf_s("%d", &vehicle);
    getchar(); // 脊径 獄遁 搾酔奄
    system("cls");

    switch (vehicle)
    {
    case 1:
        likeability += 3;
        Load("澱獣.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 澱獣! 澱獣! 陥楳備 鉦紗獣娃左陥 10歳 析啄 哀 呪 赤醸陥..!          |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 + 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        likeability -= 1;
        Load("走馬旦.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 勧 蒋拭辞 走馬旦聖 兜団辞 5歳 簡嬢獄携陥...                        |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 - 1                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        likeability -= 3;
        Load("左亀.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 鎧 降杏製精 格巷 汗携陥.. 10歳戚蟹 簡嬢獄携嬢..                    |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 - 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(DarkGreen);
        likeability -= 10;
        Load("暗栽戚.txt");
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 暗栽戚研 展壱 穐陥! 壱原趨 暗栽焼! 馬走幻 30歳聖 簡嬢獄携嬢..      |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

void Onethings()
{
    textcolor(darkBLUE);
    Load("社鯵特.txt");
    printf("\n");

    textcolor(WHITE);
    printf("  ----------------------------------------------------------------\n");
    printf(" | 昔持拭辞 亜舌 掻推廃 依税 霜庚拭 更虞壱 企岩背醤 拝猿?         |\n");
    printf(" |                                                                |\n");
    printf(" | 1.亜膳   2.耕庭損   3.%s還                                      |\n", heroine);
    printf("  ----------------------------------------------------------------\n");
    printf("  �� 雁重税 識澱精? ");
    scanf_s("%d", &onething);
    getchar(); // 脊径 獄遁 搾酔奄
    system("cls");

    switch (onething)
    {
    case 1:
        textcolor(RED);
        printf("社鯵特橿 : 嬢袴~ 魚呪趨虞~ 煽亀 亜膳戚 薦析 掻推廃 依 旭焼推!");
        getchar();
        likeability += 3;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 陥楳備 企岩聖 設 廃 依 旭焼!                                       |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 + 3                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 2:
        textcolor(RED);
        printf("社鯵特橿 : 焼.. ぞぞ.. 焼 鉱拭 搾神澗 依 旭精汽 戚薦 十十 増亜坐醤馬蟹..");
        getchar();
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 耕庭損 貝 確 壕重馬走 省紹嬢!                                      |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 - 10                                                         |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    case 3:
        textcolor(RED);
        printf("社鯵特橿 : 誓? ぞぞ 姶紫背推~");
        getchar();
        likeability += 1;
        textcolor(WHITE);
        printf("  ------------------------------------------------------------------------\n");
        printf(" | 人 蟹 号榎 畳短 湿什赤醸嬢 |\n");
        printf(" |                                                                        |\n");
        printf(" | 硲姶亀 + 1                                                             |\n");
        printf("  ------------------------------------------------------------------------\n");
        getchar();
        break;
    default:
        textcolor(DarkRed);
        Load("井壱.txt");
        likeability -= 10;
        textcolor(WHITE);
        printf("  --------------------------------------------------------------------\n");
        printf(" | 降亜 込壱 蟹穐陥!!                                                 |\n");
        printf(" |                                                                    |\n");
        printf(" | 硲姶亀 - 10                                                        |\n");
        printf("  --------------------------------------------------------------------\n");
        getchar();
        break;
    }
}

int main()
{
    char dialog[5][100]; // 企鉢 煽舌聖 是廃 壕伸 (5鯵税 企鉢)
    textcolor(BLUE);

    PlaySound(TEXT("戚原闘-葛掘.wav"), NULL, SND_ASYNC | SND_LOOP);

    printf("雁重税 戚硯精? ");
    scanf_s("%s", maincharacter, sizeof(maincharacter));
    while (getchar() != '\n'); // 脊径 獄遁 搾酔奄

    textcolor(RED);
    printf("社鯵特橿税 戚硯精? ");
    scanf_s("%s", heroine, sizeof(heroine));
    while (getchar() != '\n'); // 脊径 獄遁 搾酔奄

    // 企鉢 鎧遂 段奄鉢
    sprintf_s(dialog[0], sizeof(dialog[0]), "%s還戚重亜推?", heroine);
    sprintf_s(dialog[1], sizeof(dialog[1]), "嬢! 革革! %s還戚獣倉?", maincharacter);
    sprintf_s(dialog[2], sizeof(dialog[2]), "革! 焼 胡煽 切軒拭 症焼亀 吃猿推?");
    sprintf_s(dialog[3], sizeof(dialog[3]), "革革 畷馬惟 症生室推!");
    sprintf_s(dialog[4], sizeof(dialog[4]), "緋... 析舘 更 岨 獣佃瑳猿推?");
    sprintf_s(dialog[5], sizeof(dialog[5]), "革! 煽澗 宜端虞脅推!");
    sprintf_s(dialog[6], sizeof(dialog[6]), "製.. 穿 褐託虞脅推..!");
    sprintf_s(dialog[7], sizeof(dialog[7]), ".....");
    sprintf_s(dialog[8], sizeof(dialog[8]), "..........");

while (i < 1000) // 企鉢 呪拭 限惟 繕舛
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
            Load("朝凪.txt");
            printf("  ----------------------------------------------------------------------------------\n");
            printf(" | 幻蟹奄稽 廃 朝凪拭 級嬢亜左艦 廃 食失歳戚 奄陥軒壱 域重陥. 源聖 杏嬢坐醤畏陥!    |\n");
            printf("  ----------------------------------------------------------------------------------\n");
            getchar();
            system("cls");
        }
        else if (i == 2)
        {
            Load("朝凪.txt");
            printf("  ----------------------------------------------------------------------------------\n");
            printf(" | 幻蟹奄稽 廃 朝凪拭 級嬢亜左艦 廃 食失歳戚 奄陥軒壱 域重陥. 源聖 杏嬢坐醤畏陥!    |\n");
            printf("  ----------------------------------------------------------------------------------\n");
            getchar();
            system("cls");
        }
        else if (i == 3)
        {
            textcolor(BLUE);
            printf("蟹 : % s還戚重亜推 ? ", heroine);
            getchar();
            textcolor(RED);
            printf("社鯵特橿 : 嬢! 革革! % s還戚獣倉 ? ", maincharacter);
            getchar();
            textcolor(BLUE);
            printf("蟹 : 革! 焼 胡煽 切軒拭 症焼亀 吃猿推 ?");
            getchar();
            textcolor(RED);
            printf("社鯵特橿 : 革革 畷馬惟 症生室推 !");
            getchar();
            textcolor(BLUE);
            printf("蟹 : 緋... 析舘 更 岨 獣佃瑳猿推 ?");
            getchar();
            textcolor(RED);
            printf("社鯵特橿 : 革! 煽澗 宜端虞脅推 !");
            getchar();
            textcolor(BLUE);
            printf("蟹 : 製.. 穿 褐託虞脅推..! 薦亜 域至馬壱 臣惟推 !");
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
            printf("蟹 : 誠託 域至馬壱 尽柔艦陥 !");
            getchar();
            textcolor(RED);
            printf("社鯵特橿 : 神~! 呪壱馬写嬢推 !");
            getchar();
            textcolor(BLUE);
            printf("蟹 : ぞぞ.....");
            getchar();
            textcolor(RED);
            printf("社鯵特橿 : ぞぞぞ............");
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 戚群呪亜 幻貝 走 1歳亀 辰 照掬辞 嬢事廃 舛旋戚 達焼尽陥.           |\n");
            printf(" |                                                                    |\n");
            printf(" | 察軒 企鉢 爽薦研 達焼醤 背!                                        |\n");
            printf("  --------------------------------------------------------------------\n");
            getchar();
            textcolor(RED);
            printf("社鯵特橿 : 焼! 箸獣 %s還税 昔持拭辞 亜舌 掻推廃 依精 杭亜推? ", maincharacter);
            getchar();
            textcolor(WHITE);
            printf("  --------------------------------------------------------------------\n");
            printf(" | 譲 戚 源 嬢巨識亜 級精 旋 赤澗汽?                                  |\n");
            printf(" |                                                                    |\n");
            printf(" | 析舘 企岩聖 背左切!                                                |\n");
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