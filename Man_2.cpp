//#include <iostream>
//#include <ctime>
//#include <Windows.h>
//#include "Ball.h"
//#include "Player.h"
//#include "gameFunction.h"
//#include <iomanip>
//#include <Mmsystem.h>
//#include <conio.h>
//using namespace std;
//
//
//
//int main() {
//
//	const int MAX_LEVEL = 10;
//	const int time_play = 2;
//	const int seconds = 60;
//	int delay = 110;
//	HANDLE h;
//	h = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	DrawBorder(h);
//
//	bool started = false;
//	bool isWait = false;
//	int yourScore = 2000;
//	int level = 0;
//
//	//Khoi tao
//	Player you(WIDTH_BODER / 2, HEIGHT_BODER_BODER + 5 - 2, 4);
//	Player computer(WIDTH_BODER / 2, 7, 4);
//	Ball ball(WIDTH_BODER / 2 - 1, (HEIGHT_BODER_BODER + 8) / 2);
//
//	//Tao van toc ban dau cho qua bong. Bong se luon huong ve phia ban truoc.
//	ball.SetVX((rand() % 4) - 3);
//	ball.SetVY(1);
//	char key;
//
//	vector <Box> listBox;
//	setListBox(listBox, level);
//	displayListBox(listBox);
//
//
//	clock_t start = 0, end = 0;
//	double cpu_time_used = 0;
//	gotoXY(0, HEIGHT_BODER_BODER + 7, h);
//	SetConsoleTextAttribute(h, 15);
//	std::cout << "       Your score:" << yourScore << "\t\t      Level    : " << level << endl;
//	//Ve va tao mau cho thanh choi cua minh
//	you.Draw(h);
//	//Ve va tao mau cho qua bong
//	ball.Draw(h);
//	//---------------- Chon che do choi --------------------------
//	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER_BODER / 2 + 5, h);
//	SetConsoleTextAttribute(h, 10);
//	cout << "Choi tiep    :    nhan 1";
//	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER_BODER / 2 + 7, h);
//	cout << "Choi lai     :    nhan 2";
//	do
//	{
//		key = _getch();
//	} while (key != '1' && key != '2');
//
//	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER_BODER / 2 + 5, h);
//	cout << "                          ";
//	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER_BODER / 2 + 7, h);
//	cout << "                           ";
//
//	if (key == '1')
//	{
//		loadGame(level);
//	}
//	else
//	{
//		level = 0;
//	}
//	gotoXY(0, HEIGHT_BODER_BODER + 7, h);
//	SetConsoleTextAttribute(h, 15);
//	std::cout << "       Your score:" << yourScore << "\t\t      Level    : " << level << endl;
//	//-------------------------------------------------------------
//
//	while (true) {
//		//PlaySound(TEXT("a.mp3"), NULL, SND_FILENAME | SND_ASYNC);
//		start = clock();
//		
//		showAchievemert(h);
//		if (GetAsyncKeyState(VK_ESCAPE)) {
//			break;//ket thuc tro choi
//		}
//
//		if (started)
//		{
//			if (you.move())
//			{
//				//Ve va tao mau cho thanh choi cua minh
//				SetConsoleTextAttribute(h, 9);
//				you.Draw(h);
//			}
//
//			if (checkBallCollideBox(ball, listBox, yourScore))
//			{
//				gotoXY(0, HEIGHT_BODER_BODER + 7, h);
//				SetConsoleTextAttribute(h, 15);
//				std::cout << "       Your score:" << yourScore <<"    ";
//
//			}
//		
//
//			//vi tri moi cua qua bong
//			ball.SetX(ball.X() + ball.VX());
//			ball.SetY(ball.Y() + ball.VY());
//
//			if (ball.Y() >= HEIGHT_BODER_BODER + 5 || cpu_time_used / seconds >= time_play)
//			{
//				if (yourScore >= 200 + level * 50)
//				{
//					gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER_BODER + 5) / 2 + 7,h);
//					SetConsoleTextAttribute(h, 10);
//					cout << " <<<<<  LEVEL   UP >>>>>";
//
//					level = level <= MAX_LEVEL ? level+1 : MAX_LEVEL;
//					gotoXY(0, HEIGHT_BODER_BODER + 7, h);
//					SetConsoleTextAttribute(h, 15);
//
//					std::cout << "       Your score: 0\t\t      Level    : " << level << endl;
//					saveAchievement(level, yourScore);
//				}
//
//				cpu_time_used = 0;
//				ResetResult(you, computer, ball, started, yourScore, computerScore, h);
//				setListBox(listBox, level);
//				displayListBox(listBox);
//				yourScore = 0;
//				you.Draw(h);
//			}
//
//			//Kiem tra bong cham thanh choi cua ban
//			if (ball.Y() >= you.Y() - 1 && ball.Y() <= you.Y()) {
//
//				if (ball.X() >= you.X() - you.Size() && ball.X() <= you.X() + you.Size()) {
//					ball.SetVY(ball.VY() * -1);
//					int temp = ball.VX() < 0 ? -1 : 1;
//					ball.SetVX(abs(ball.X() - you.X())*temp / 2);
//					ball.SetY(you.Y() - 1);
//				}
//			}
//
//			if (ball.Y() <= TOP_BODER)
//			{
//				ball.SetVY(ball.VY()*-1);
//			}
//
//			//Kiem tra bong cham 2 bien
//			if (ball.X() <= 1) {
//				ball.SetVX(ball.VX() * -1);
//				ball.SetX(LEFT_BODER + 1);
//			}
//			else if (ball.X() >= WIDTH_BODER - 3) {
//				ball.SetVX(ball.VX() * -1);
//				ball.SetX(WIDTH_BODER - 3);
//			}
//
//	
//			//Ve va tao mau cho qua bong
//			ball.Draw(h);
//
//			Sleep(delay - 10 * level);
//
//		}
//		else
//		{
//			COORD c;
//			isWait = true;
//			if (isWait) {
//				gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER_BODER + 5) / 2 + 5,h);
//				SetConsoleTextAttribute(h, 15);
//				std::cout << "Press the space to start!";
//
//				SetConsoleTextAttribute(h, 15);
//
//				gotoXY(WIDTH_BODER / 2 - 2, HEIGHT_BODER_BODER + 4, h);
//			
//				std::cout << "You";
//			}
//
//			if (GetAsyncKeyState(VK_SPACE)) { //Khi nhan phim Space tu ban phim thi tro choi bat dau
//				gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER_BODER + 5) / 2 + 5, h);
//				std::cout << "                          ";
//
//				gotoXY(WIDTH_BODER / 2 - 10, (HEIGHT_BODER_BODER + 5) / 2 + 3, h);
//				std::cout << "                       ";
//
//				gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER_BODER + 5) / 2 + 7, h);
//				cout << "                                ";
//
//				gotoXY(WIDTH_BODER / 2 - 4, 6, h);
//				std::cout << "        ";
//
//				gotoXY(WIDTH_BODER / 2 - 2, HEIGHT_BODER_BODER + 4, h);
//				std::cout << "   ";
//
//				started = true;
//				isWait = false;
//			}
//		}
//
//		end = clock();
//
//		if (started)
//		{
//			setfill('0');
//
//			cpu_time_used += (double)(end - start) / CLOCKS_PER_SEC;
//			gotoXY(60, 38, h);
//			std::cout << setw(2) << (int)cpu_time_used / seconds;
//			cout << " : " << setw(2) << (int)cpu_time_used % seconds;
//		}
//	}
//
//	return 0;
//}
