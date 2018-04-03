#include <iostream>
#include "console.h"
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




struct ToaDo
{
	int x,y;
};


enum TrangThai {UP, DOWN, LEFT, RIGHT};

struct KieuSnake
{
	ToaDo dot[40];
	int n;
	TrangThai tt;
};



void HienThi (KieuSnake snake)
{
	clrscr();
	
	for(int i=0; i < snake.n; i++)
	{
	
	}
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
	
		//xu li game
		
		//game over
		
		
		Sleep(80);
	}
	return 0;
}
