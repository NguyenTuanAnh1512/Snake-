#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	

	
}

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}


void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

enum TrangThai {UP, DOWN, LEFT, RIGHT};


struct ToaDo
{
	int x,y;
};

struct KieuSnake
{
	ToaDo dot[40];
	int n;
	TrangThai tt;
};


void DieuKhien_DiChuyen (KieuSnake &snake)
{
	//truyen trang thai cho dot cu
	for (int i = snake.n - 1; i > 0; i--)
		snake.dot[i] = snake.dot[i-1];
		
	if (kbhit())   //phat hien co phim nhan vao
	{
		int key = _getch();
		if(key == 75)
			snake.tt = LEFT;
		else if(key == 77)
			snake.tt = RIGHT;
		else if(key == 72)
			snake.tt = UP;
		else if(key == 80)
			snake.tt = DOWN;
	}
	
	if(snake.tt == UP)
		snake.dot[0].y--;
	else if(snake.tt ==DOWN)
		snake.dot[0].y++;
	else if(snake.tt ==LEFT)
		snake.dot[0].x--;
	else if(snake.tt ==RIGHT)
		snake.dot[0].x++;	
}


void HienThi (KieuSnake snake)
{
	clrscr();
	
	for(int i=0; i < snake.n; i++)
	{
		gotoXY (snake.dot[i].x, snake.dot[i].y);
		cout<<"*";
	}
}


void KhoiTao (KieuSnake &snake)
{
	snake.n = 1;
	snake.dot[0].x = 0;
	snake.dot[0].y = 0;
	snake.tt = RIGHT;
}



int main()
{
	KieuSnake snake;
	KhoiTao (snake);
	
	while(1)
	{
		//hien thi
		HienThi (snake);
		//dieu kien
		DieuKhien_DiChuyen (snake);
		//xu li game
		
		//game over
		
		
		Sleep(80);
	}
	return 0;
}
