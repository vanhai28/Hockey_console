
#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Ball.h"
#include "Player.h"
#include "gameFunction.h"
//#include <SDL_mixer.h>
using namespace std;
//Mix_Music * music = NULL;
#pragma comment (lib, "winmm.lib")
int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, 680, 750, true);
	Nocursortype();

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	PlaySound(L"logo2.wav", NULL, SND_FILENAME || SND_ASYNC);
	drawTextPingpong(h, 4, 20);
	system("cls");


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
		showMenu(key, h);

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
			ReadGuide(key, h);
			break;
		case '0':
			//Thoat
			exit(0);
		}

		key = 0;
	} while (1);

}
