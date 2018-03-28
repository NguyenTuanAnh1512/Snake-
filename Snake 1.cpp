#include <iostream>
#include "console.h"
#include <Windows.h>
#include <conio.h>
using namespace std;


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
