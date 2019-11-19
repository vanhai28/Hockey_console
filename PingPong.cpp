// Do_An_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdio.h"
#include "iostream"
#include "time.h"
#include "thread"
#include "Windows.h"
#include "Point2D.h"
#include "Ball.h"
#include"Bar.h"

using namespace std;

int HEIGH_CONSOLE = 40, WIDTH_CONSOLE = 50;
int SPEED = 5;
int STATE = 0;

Point2D START_POS_OF_BALL((WIDTH_CONSOLE / 2 + 1), (HEIGH_CONSOLE / 2));
Point2D START_POS_OF_BAR_1(WIDTH_CONSOLE / 2, 2);
Point2D START_POS_OF_BAR_2(WIDTH_CONSOLE / 2, HEIGH_CONSOLE - 2);

Ball ball;
Bar bar1, bar2;

int level;
int mode;				// mode = 1:chơi với người, 2:chơi với máy

void Nocursortype();

void DrawBoard(int width, int height);
void ThreadGame();
void Reset();
void PauseGame(HANDLE t);
void ExitGame(HANDLE t);
void GoToXY(int x, int y);
void Menu();
void GameLoop();
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

int main()
{
	SetConsoleTitleW(L"HOCKEY");//Đặt tiêu đề trên thanh tiêu đề của cửa sổ console
	FixConsoleWindow();//làm mờ đi nút maximize và không cho người dùng thay đổi kích thước
	//cửa sổ hiện hành.
	Nocursortype();	//Xóa dấu nháy trên console

	Reset();	//Khởi tạo dữ liệu ban đầu

	Menu();
}

void GameLoop()
{
	
	thread t1(ThreadGame); //Tạo thread game

	HANDLE handle = t1.native_handle(); //Lấy handle của thread

	//gameloop
	int temp;
	system("cls");
	DrawBoard(WIDTH_CONSOLE, HEIGH_CONSOLE);
	while (true)
	{
		
		

		//nếu chưa kết thúc game
		if (0 == STATE)		
		{
			temp = _getch();
			if ('p' == temp)
			{
				PauseGame(handle);		//Tạm dừng
			}
			else if (27 == temp)	//ESC
			{
				ExitGame(handle);		//Thoát game
			}
			else
			{
				ResumeThread(handle);
				//Phần di chuyển của các đối tượng


				//Nếu chơi với người thì bar1 tự di chuyển, bar 2 điều khiển được
				if (mode == 2)
				{
					if ((temp == 'd') && (bar2.Pos().X() < WIDTH_CONSOLE - 1))
					{
						bar2.MoveBarToRight();
					}
					if ((temp == 'a') && (bar2.Pos().X() > 5))
					{
						bar2.MoveBarToLeft();
					}
				}
				//Chơi với người thì cả 2 bar đều được điều khiển
				else
				{
					if ((temp == 'd') && (bar1.Pos().X() < WIDTH_CONSOLE - 1))
					{
						bar1.MoveBarToRight();
					}
					if ((temp == 'a') && (bar1.Pos().X() > 5))
					{
						bar1.MoveBarToLeft();
					}
					if ((temp == 'l') && (bar2.Pos().X() < WIDTH_CONSOLE - 1))
					{
						bar2.MoveBarToRight();
					}
					if ((temp == 'j') && (bar2.Pos().X() > 5))
					{
						bar2.MoveBarToLeft();
					}
				}
			}
		}


		//Xử lý khi kết thúc game
		else if (ball.Pos().Y() == 1 || ball.Pos().Y() == HEIGH_CONSOLE - 1)	//Đã thua
		{
			GoToXY(WIDTH_CONSOLE+10, HEIGH_CONSOLE/ 2);
			if (mode == 1)
			{
				if (2 == STATE)
				{
					cout << "Nguoi choi 1 chien thang!!!!" << endl;
				}
				else if (1 == STATE)
				{
					cout << "Nguoi choi 2 chien thang!!!!" << endl;
				}
			}
			else
			{
				if (2 == STATE)
				{
					cout << "Ban thua roi!!!!" << endl;
				}
				else if (1 == STATE)
				{
					cout << "Ban la nguoi chien thang!!!!" << endl;
				}
			}
			GoToXY(WIDTH_CONSOLE + 10, HEIGH_CONSOLE / 2+1);
			cout << "Ban co muon tiep tuc khong: " << endl;
			GoToXY(WIDTH_CONSOLE + 10, HEIGH_CONSOLE / 2+2);
			cout << "1. Co\t2. Khong" << endl;
			PauseGame(handle);
			char option;
			option = _getch();
			if ('2' == option)
			{
				TerminateThread(handle, 0);
				system("cls");
				main();
			}
			else if ('1' == option)
			{
				Reset();
				DrawBoard(WIDTH_CONSOLE,HEIGH_CONSOLE);
			}
		}
	}
}

void Nocursortype()							//Xóa dấu nháy của con trỏ kí tự			Nguồn: https://daynhauhoc.com/t/an-con-tro-chuot-tren-man-hinh-console/34411
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void TextColor(WORD color)					// Đổi màu ký tự				Nguồn:https://blogkhanhtoan.wordpress.com/2016/03/07/mot-so-ham-mo-rong-trong-cc/
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void DrawBoard(int width, int height)			//Vẽ màn hình game với kích thước width x height
{
	Point2D pos;
	//Vẽ 3 thanh ngang
	for (int i = 0; i <= width; i++)
	{
		pos.SetX(i);
		pos.SetY(0);
		pos.GoTo();
		printf("%c", char(219));

		

		pos.SetY(height);
		pos.GoTo();
		printf("%c", char(219));
	}

	//Vẽ quả bóng
	ball.DrawBall('O');

	//Vẽ 2 thanh dọc 
	for (int i = 0; i <= height; i++)
	{
		pos.SetX(0);
		pos.SetY(i);
		pos.GoTo();
		printf("%c", char(219));

		pos.SetX(width);
		pos.GoTo();
		printf("%c", char(219));
	}

	//Vẽ 2 thanh bar
	bar1.DrawBar(char(100));
	bar2.DrawBar(char(100));

	//Vẽ menu
	GoToXY(WIDTH_CONSOLE + 10, 5);
	cout << "Pause Game: press P";
	GoToXY(WIDTH_CONSOLE + 10, 7);
	cout<< "Exit Game: press ESC" << endl;
	if (mode == 2)
	{
		GoToXY(WIDTH_CONSOLE + 10, 9);
		cout << "Press 'j', 'l' to move the bar"<< endl;
	}
	else
	{
		GoToXY(WIDTH_CONSOLE + 10, 9);
		cout << "Press 'a', 'd' to move the bar1";
		GoToXY(WIDTH_CONSOLE + 3, 11);
		cout<< "Press 'j', 'l' to move the bar2" << endl;
	}
	}
	
void Menu()							//Vẽ và xử lý menu
{
	TextColor(15);
	GoToXY(45, 10);
	cout << "WELLCOM TO PING PONG GAME!!!";
	GoToXY(50, 12);
	cout << "1_PLAY WITH YOUR FRIENDS";
	GoToXY(50, 14);
	cout << "2_PLAY WITH COMPUTER";
	GoToXY(50, 16);
	cout << "3_EXIT";
	int option;
	option = _getch();
	if ('1' == option)
	{
		mode = 1;
		GameLoop();
	}
	else if ('2' == option)
	{
		mode = 2;
		//Nếu là máy thì phải có chọn mức độ khó cho game
		system("cls");
		GoToXY(45, 14);
		cout << "   Xin moi nhap do kho tu 1 den 10: ";
		cin >> level;
		bar2.SetLevel(level); //Chọn xong set mức độ khó
		GameLoop();
	}
	else 
	{
		system("cls");
		exit(0);
	}
}

void ThreadGame()
{
	while (true)
	{
		if (0 == STATE)		//Nếu chưa kết thúc game
		{
			//Di chuyển quả bóng
			ball.MoveBall(HEIGH_CONSOLE, WIDTH_CONSOLE);
			if (mode == 2)
			{
				//Tự di chuyển bar1
				bar1.AutoMove(ball.Pos().X(), WIDTH_CONSOLE);
			}
			//Phần xử lý khi va chạm

			//Bar1 không hứng được bóng
			if (3 == ball.Pos().Y() && 'U' == ball.HeightState())
			{
				if (ball.Pos().X() < bar1.Pos().X() - 5 || ball.Pos().X() > bar1.Pos().X() + 1)
				{
					STATE = 1;				
					ball.SetState('F');
				}
				else
				{
					SPEED++;
				}
			}

			//Bar 2 không hứng được bóng
			if (HEIGH_CONSOLE - 3 == ball.Pos().Y() && 'D' == ball.HeightState())
			{
				if (ball.Pos().X() < bar2.Pos().X() - 5 || ball.Pos().X() > bar2.Pos().X() + 1)
				{
					STATE = 2;							//Ball đã chạm đáy nhưng bar2 vẫn chưa hứng được.
					ball.SetState('F');
				}
				else
				{
					SPEED++;
				}
			}
		}
		else if (ball.Pos().Y() > 1 && ball.Pos().Y() < HEIGH_CONSOLE - 1)	//Đã thua nhưng ball vẫn chưa chạm đáy
		{
			ball.MoveBall(HEIGH_CONSOLE, WIDTH_CONSOLE);
		}
		Sleep(100 - SPEED);									//Hàm ngủ theo tốc độ SPEEED
	}
}

void Reset()						//Reset lại các chỉ số
{
	system("cls");
	bar1.SetPos(START_POS_OF_BAR_1);
	bar2.SetPos(START_POS_OF_BAR_2);
	ball.SetPos(START_POS_OF_BALL);
	SPEED = 5;
	STATE = 0;
	ball.SetState('T');
}

void PauseGame(HANDLE t)			//Tạm dừng game
{
	SuspendThread(t);
}

void ExitGame(HANDLE t)						//Thoát game
{	
	TerminateThread(t, 0);		
	system("cls");
	exit(0);
}

void GoToXY(int x, int y)					//Đi đến điểm có tọa độ (x, y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

