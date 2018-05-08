#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define ChieuRong 35
#define ChieuCao 25

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

void TextColor (int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
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


struct QuaChin
{
	ToaDo td;
};

struct QuaXanh
{
	ToaDo td;
};

struct KieuSnake
{
	ToaDo dot[80];
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
		if(key == 'a')
			snake.tt = LEFT;
		else if(key == 'd')
			snake.tt = RIGHT;
		else if(key == 'w')
			snake.tt = UP;
		else if(key == 's')
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


void HienThi (KieuSnake snake , QuaChin qc, QuaXanh qx)
{
	clrscr();
	
	TextColor (14);
	for(int i=0 ; i<ChieuCao ; i++)
	{
		gotoXY (ChieuRong , i);
		putchar(178);
	}
	
	TextColor (12);
	gotoXY (qc.td.x , qc.td.y);
		cout<<"O";
	
	TextColor (10);
	gotoXY (qx.td.x , qx.td.y);
		cout<<"0";
	
	TextColor (9);
	gotoXY(snake.dot[0].x, snake.dot[0].y );
		putchar(2);
	for(int i=1; i < snake.n; i++)
	{
		gotoXY (snake.dot[i].x, snake.dot[i].y);
		cout<<"*";
	}
	
}


void KhoiTao (KieuSnake &snake , QuaChin &qc, QuaXanh &qx)
{
	snake.n = 3;
	snake.dot[0].x = 2;
	snake.dot[0].y = 0;
	snake.dot[0].x = 1;
	snake.dot[0].y = 0;
	snake.dot[0].x = 0;
	snake.dot[0].y = 0;
	snake.tt = RIGHT;
	
	
	qc.td.x = 10;
	qc.td.y = 10;
	
	qx.td.x = 20;
	qx.td.y = 20;
}


int XuLy (KieuSnake &snake , QuaChin &qc, QuaXanh &qx, int &TocDo)
{
	// xu ly thua game
	if (snake.dot[0].x < 0 || snake.dot[0].x >= ChieuRong || snake.dot[0].y < 0 || snake.dot[0].y >= ChieuCao )
	 	 	 return -1;
	
	for(int i=1; i<snake.n;i++)
	{
		if(snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y)
		     return -1;
	}
	
	
	//xu ly an hoa qua
	if ( snake.dot[0].x == qc.td.x && snake.dot[0].y == qc.td.y)
	{

		for (int i = snake.n;i>0;i--)
			snake.dot[i] = snake.dot[i-1];
			
		snake.n++;
		
		if(snake.tt == UP)
			snake.dot[0].y--;
		else if(snake.tt ==DOWN)
			snake.dot[0].y++;
		else if(snake.tt ==LEFT)
			snake.dot[0].x--;
		else if(snake.tt ==RIGHT)
			snake.dot[0].x++;	
			
			
		qc.td.x = rand() % ChieuRong;
		qc.td.y = rand() % ChieuCao;
		
		qx.td.x = rand() % ChieuRong;
		qx.td.y = rand() % ChieuCao;
		
		if(TocDo > 70)
			TocDo = TocDo-10;
	}

	if ( snake.dot[0].x == qx.td.x && snake.dot[0].y == qx.td.y)
	{

		for (int i = snake.n;i>0;i--)
			snake.dot[i] = snake.dot[i-1];
		if(snake.n >=3)
			snake.n = snake.n-3;
		
		if(snake.tt == UP)
			snake.dot[0].y--;
		else if(snake.tt ==DOWN)
			snake.dot[0].y++;
		else if(snake.tt ==LEFT)
			snake.dot[0].x--;
		else if(snake.tt ==RIGHT)
			snake.dot[0].x++;	
			
			
		qx.td.x = rand() % (ChieuRong);
		qx.td.y = rand() % (ChieuCao);
		
		
		if(TocDo > 50)
			TocDo = TocDo-10;
	}
	
}


int main()
{
	srand(time(NULL));
	KieuSnake snake;
	QuaChin qc;
	QuaXanh qx;
	KhoiTao (snake , qc, qx);
	int KiemTraThuaGame=0;
	int TocDo=150;
	while(1)
	{
		//hien thi
		HienThi (snake , qc, qx);
		//dieu kien
		DieuKhien_DiChuyen (snake);
		//xu li game
		KiemTraThuaGame = XuLy (snake , qc, qx, TocDo);
		gotoXY(60,24);
		cout<<"Diem cua ban:   "<< snake.n - 3;
		//game over
		if(KiemTraThuaGame == -1)
		{
			gotoXY(40,10);
			cout<<"GAME OVER !!!";
			while (_getch() != 13);
				break;
		}
		
		Sleep(TocDo);
	}
	return 0;
}
