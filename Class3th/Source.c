#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 11
#define HEIGHT 11

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

typedef struct Character
{
	int x;
	int y;
	const char* shape;
}Character;

char maze[HEIGHT][WIDTH] =
{
	{'1','1','1','1','1','1','1','1','1','1','1'},
	{'1','0','0','0','0','1','1','1','1','2','1'},
	{'1','1','0','1','0','0','1','1','1','0','1'},
	{'1','1','0','1','1','0','0','1','1','0','1'},
	{'1','1','0','0','1','1','0','0','1','0','1'},
	{'1','1','1','0','1','1','1','0','1','0','1'},
	{'1','1','1','0','0','0','0','1','1','0','1'},
	{'1','1','1','0','0','1','0','1','1','0','1'},
	{'1','1','1','1','1','1','0','1','1','0','1'},
	{'1','1','0','0','0','0','0','0','0','0','1'},
	{'1','1','1','1','1','1','1','1','1','1','1'},
};

void Render()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (maze[i][j] == '0')
			{
				printf("  ");
			}
			else if (maze[i][j] == '1')
			{
				printf("��");
			}
			else
			{
				printf("��");
			}
		}

		printf("\n");
	}
}

void Position(int x, int y)
{
	// X�� Y���� �����ϴ� ����ü�Դϴ�.
	COORD position = { x, y };

	// �ܼ� Ŀ���� ��ǥ�� �����ϴ� �Լ��Դϴ�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


int main()
{
	Character character = { 2, 1, "��" };

	char key = 0;

	Render();

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();

			if (key == -32)
			{
				key = _getch();
			}

			switch (key)
			{
			case UP: character.y--;
				break;
			case LEFT: character.x -= 2;
				break;
			case RIGHT: character.x += 2;
				break;
			case DOWN: character.y++;
				break;
			}

			system("cls");

			Render();
		}

		Position(character.x, character.y);
		printf("%s", character.shape);
	}


	return 0;
}