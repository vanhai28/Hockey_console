#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Ball.h"
#include "Player.h"
#include "gameFunction.h"

using namespace std;

int main() 
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 150, 0, 680, 750, true);
	Nocursortype();
	//An con tro console
	CONSOLE_CURSOR_INFO cci;

	cci.dwSize = 5;
	cci.bVisible = false;

	int delay = 110;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	int yourScore = 0;
	
	int computerScore = 0;

	bool started = false;
	bool isWait = false;
	char key = 0;
	//Khoi tao
	Player you(WIDTH_BODER / 2, HEIGHT_BODER + 5 - 2, 4);
	Player computer(WIDTH_BODER / 2, 7, 4);
	Ball ball(WIDTH_BODER / 2 - 1, (HEIGHT_BODER + 8) / 2);

	//Tao van toc ban dau cho qua bong. Bong se luon huong ve phia ban truoc.
	ball.SetVX((rand() % 4) - 3);
	ball.SetVY(1);
	
	do
	{
		menu(key, h);

		switch (key)
		{
		case '1':
			//Man choi 1 dau voi may
			playPingpong(you, computer);
			break;
		case '2':
			//Man choi 2 dap vo hop
			DrawBorder(h);
			stagePingpongBox(you, ball, h);
			break;
		case '3':
			//Huong dan
			break;
		case '0':
			//Thoat
			return 0;
		}
		
		key = 0;
	}while (1);
	
	return 0;
}
