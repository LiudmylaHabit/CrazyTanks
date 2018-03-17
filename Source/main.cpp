#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include "..\Header\Tank.h"
#include "..\Header\Const.h"

using namespace std;

char play_field[Height+2][Width+2];

void setcur(int x, int y)//установка курсора на позицию  x y 
{ 
	COORD coord; 
	coord.X = x; 
	coord.Y = y; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	for (int i = 0; i < Height+2; i++)
	{
		for (int j = 0; j < Width+2; j++)
		{
			cout << play_field[i][j];
		}
		cout << endl;
	}
};

void TryToMove(Tank* t, int index)
{
	if (play_field[t->coordinate[0] + direction[index][0]][t->coordinate[1] + direction[index][1]] == empty) 
	{
		play_field[t->coordinate[0]][t->coordinate[1]] = empty;
		t->Move(index);
	}
};

void GenerateWall(char play_field[Height+2][Width+2])
{
	for (int i = 0; i < WALL_COUNT; i++)
	{
		for (int try_count = 0; try_count < 100; try_count++)
		{
			int row = rand()%Height + 1;
			int col = rand()%Width + 1;
			if (play_field[row][col] == empty)
			{
				play_field[row][col] = wall;
				break;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < Height+2; i++)
	{
		for (int j = 0; j < Width+2; j++)
		{
			play_field[i][j] = empty;
			if (i == 0 || i == Height+1 || j == 0 || j == Width+1)
			{
				play_field[i][j] = wall;
			}
		}
	}
	Tank* t = new Tank();
	play_field[t->coordinate[0]][t->coordinate[1]] = player;
	GenerateWall(play_field);
	setcur(0,0);

	unsigned char ch;
	do
	{
		ch=_getch();
		if (ch==224) //Проверка нажатия функциональной клавиши
		{
			ch=_getch();
			switch(ch)
			{
			case 75: 
				TryToMove(t, 3);
				break;
			case 77: 
				TryToMove(t, 1);
				break;
			case 72: 
				TryToMove(t, 0);
				break;
			case 80: 
				TryToMove(t, 2);
				break;
			default: 
				printf("unknown\n");
			}
			play_field[t->coordinate[0]][t->coordinate[1]] = player;
			setcur(0,0);
		}
	}
	while(ch!=27);
	return 0;
}