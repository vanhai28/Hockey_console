#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Ball.h"
#include "Player.h"

using namespace std;

int width = 54; // Chieu ngang san dau
int height = 35; // Chieu doc san dau

//An con tro chuot tren man hinh
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}


// Input: you(thanh choi cua ban), com(thanh choi cua may), b(bong), started(co kiem tra ket thuc tran), 
// yourScore(diem cua ban), computerScore(diem cua may), h(con tro su dung voi man hinh console)
// Output: Man hinh choi ban dau
// Chuc nang: Reset lai san dau khi ban thang hoac may thang
void ResetResult(Player& you, Player& com, Ball& b, bool& started, int& yourScore, int& computerScore, HANDLE& h) {
	//Cho qua bong ve tri ban dau
	b.SetX(float(width / 2 - 1));
	b.SetY(float((height + 8) / 2));

	//Cho vi tri cua 2 nguoi choi ve vi tri ban dau
	you.SetX(float(width / 2));
	com.SetX(float(width / 2));
	com.SetVX(0.0f);

	started = false;

	b.SetVX(float(rand() % 3) - 1.5f);
	b.SetVY(1);

	COORD pos;

	pos.X = width / 2 - 10;
	pos.Y = (height + 5) / 2 + 3;

	SetConsoleTextAttribute(h, 12);

	if (yourScore == 3) {
		SetConsoleCursorPosition(h, pos);
		cout << ">>>>>> YOU WIN! <<<<<<";
		yourScore = 0;
		computerScore = 0;
	}
	else if (computerScore == 3) {
		SetConsoleCursorPosition(h, pos);
		cout << ">>>> COMPUTER WIN <<<<";
		yourScore = 0;
		computerScore = 0;
	}

	COORD c;

	c.X = 0;
	c.Y = height + 5;
	//dua con tro ve vi tri (0, height)
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 15);

	cout << "\n\n       Your score: " << yourScore << "\t\tComputer score: " << computerScore << endl;
}
void DrawBorder(HANDLE h);
int main() {
	const float maxSpeed = 2;
	const int delay = 50;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	DrawBorder(h);
	
	bool started = false;
	bool isWait = false;
	int yourScore = 0;
	int computerScore = 0;

	//Khoi tao
	Player you(width / 2, height + 5 - 2, 4);
	Player computer(width / 2, 7, 4);
	Ball ball(width / 2 - 1, (height + 8) / 2);

	//Tao van toc ban dau cho qua bong. Bong se luon huong ve phia ban truoc.
	ball.SetVX(float(rand() % 3) - 1.5f);
	ball.SetVY(1);

	computer.SetVX(0);

	while (true) {

		if (started) {

			//Khi nhan phim mui ten trai hoac phai thi nguoi choi se di chuyen sang trai hoac phai
			if (GetAsyncKeyState(VK_LEFT)) {
				you.SetX(you.X() - 2);
			}
			else if (GetAsyncKeyState(VK_RIGHT)) {
				you.SetX(you.X() + 2);
			}

			//Cho may chay theo bong
			computer.SetVX(computer.VX() - float(computer.X() - ball.X()) / 10.0f);
			computer.SetVX(computer.VX()*0.83f);
			computer.SetX(computer.X() + computer.VX());

			//Tao ranh gioi cho nguoi choi
			if (you.X() < you.Size() + 1) {
				you.SetX(float(you.Size() + 1));
			}
			else if (you.X() > (width - you.Size() - 2)) {
				you.SetX(float(width - you.Size() - 2));
			}
			//Tao ranh gioi cho may
			if (computer.X() < computer.Size() + 1) {
				computer.SetX(float(you.Size() + 1));
			}
			else if (computer.X() > (width - computer.Size() - 2)) {
				computer.SetX(float(width - computer.Size() - 2));
			}
			//Gioi han toc do cua qua bong
			if (ball.VX() < -maxSpeed) {
				ball.SetVX(-maxSpeed);
			}
			else if (ball.VX() > maxSpeed) {
				ball.SetVX(maxSpeed);
			}
			//vi tri moi cua qua bong
			ball.SetX(ball.X() + ball.VX());
			ball.SetY(ball.Y() + ball.VY());

			//Kiem tra bong cham thanh choi cua ban
			if (ball.Y() >= you.Y() - 1 && ball.Y() <= you.Y()) {

				if (ball.X() > you.X() - you.Size() && ball.X() < you.X() + you.Size()) {
					ball.SetVY(ball.VY() * -1);
					ball.SetVX(ball.VX() + float(ball.X() - you.X()) / 3);
					ball.SetY(you.Y() - 1);
				}
			}
			// Kiem tra bong cham thanh choi cua may
			if (ball.Y() <= computer.Y() + 1 && ball.Y() >= computer.Y()) {

				if (ball.X() > computer.X() - computer.Size() && ball.X() < computer.X() + computer.Size()) {
					ball.SetVY(ball.VY() * -1);
					ball.SetVX(ball.VX() + float(ball.X() - computer.X()) / 3);
					ball.SetY(computer.Y() + 1);
				}
			}
			// Kiem tra ban thang hoac may thang
			if (ball.Y() >= height + 5) {
				++computerScore;
				ResetResult(you, computer, ball, started, yourScore, computerScore, h);
	
			}
			else if (ball.Y() <= 5) {
				++yourScore;
				ResetResult(you, computer, ball, started, yourScore, computerScore, h);
			}
			//Kiem tra bong cham 2 bien
			if (ball.X() <= 1) {
				ball.SetVX(ball.VX() * -1);
				ball.SetX(1.0f);
			}
			else if (ball.X() >= width - 3) {
				ball.SetVX(ball.VX() * -1);
				ball.SetX(float(width - 3));
			}

		}
		else 
		{
			COORD c;

			if (!isWait) {
				c.X = width / 2 - 12;
				c.Y = (height + 5) / 2 + 5;
				//Di chuyen con tro toi vi tri (c.X, c.Y)
				SetConsoleCursorPosition(h, c);

				SetConsoleTextAttribute(h, 15);
				cout << "Press the space to start!";
				SetConsoleTextAttribute(h, 15);

				c.X = width / 2 - 4;
				c.Y = 6;

				SetConsoleCursorPosition(h, c);
				cout << "Computer";

				c.X = width / 2 - 2;
				c.Y = height + 4;

				SetConsoleCursorPosition(h, c);
				cout << "You";

				isWait = true;
			}

			if (GetAsyncKeyState(VK_SPACE)) { //Khi nhan phim Space tu ban phim thi tro choi bat dau
				c.X = width / 2 - 12;
				c.Y = (height + 5) / 2 + 5;
				SetConsoleCursorPosition(h, c);
				cout << "                          ";

				c.X = width / 2 - 10;
				c.Y = (height + 5) / 2 + 3;
				SetConsoleCursorPosition(h, c);
				cout << "                       ";

				c.X = width / 2 - 4;
				c.Y = 6;
				SetConsoleCursorPosition(h, c);
				cout << "        ";

				c.X = width / 2 - 2;
				c.Y = height + 4;
				SetConsoleCursorPosition(h, c);
				cout << "   ";

				started = true;
				isWait = false;
			}
		}
		//Ve va tao mau cho thanh choi cua minh
		SetConsoleTextAttribute(h, 9);
		you.Draw(h);

		//Ve va tao mau cho thanh choi cua may
		SetConsoleTextAttribute(h, 10);
		computer.Draw(h);

		//Ve va tao mau cho qua bong
		ball.Draw(h);

		Sleep(delay);
	}

	return 0;
}
void DrawBorder(HANDLE h)
{


	
	Nocursortype();
	srand(unsigned int(time(NULL)));
	//tao hinh chu nhat voi toa do goc tren ben trai (0, 0) va goc duoi ben trai (width, height + 8)
	SMALL_RECT DisplayArea = { 0, 0,(short) width,(short)height + 8 };
	SetConsoleWindowInfo(h, TRUE, &DisplayArea);

	//An con tro console
	CONSOLE_CURSOR_INFO cci;

	cci.dwSize = 10;
	cci.bVisible = false;
	//Ve khung
	SetConsoleTextAttribute(h, 12); //Tao mau cho khung choi
	//Tao chu PONG
	for (int i = 0; i < 24; i++) {
		cout << (char)(220);

		switch (i) {
		case 5: case 11: case 17:
			cout << ' ';
			break;
		default:
			break;
		}
	}

	cout << endl;

	for (int i = 0; i < 24; i++) {
		switch (i) {
		case 0: case 4: case 5: case 9: case 10: case 14: case 15:
			cout << (char)(219);
			break;
		default:
			break;
		}

		cout << ' ';
	}

	cout << endl;

	for (int i = 0; i < 24; i++) {
		switch (i) {
		case 0: case 5:
			cout << (char)(219);
			continue;
		case 1: case 2: case 3: case 4: case 19: case 20:
			cout << (char)(220);
			continue;
		case 7: case 11: case 12: case 16: case 17:
			cout << (char)(219);
			break;
		case 21:
			cout << (char)(220);
			break;
		default:
			break;
		}

		cout << ' ';
	}

	cout << endl;

	for (int i = 0; i < 24; i++) {
		switch (i) {
		case 0: case 6: case 10: case 11: case 15: case 16: case 20:
			cout << (char)(219);
			break;
		default:
			break;
		}

		cout << ' ';
	}

	cout << endl;

	for (int i = 0; i < 24; i++) {
		switch (i) {
		case 0: case 11: case 12: case 16: case 22:
			cout << (char)(219);
			break;
		case 6:
			cout << (char)(219);
			continue;
		case 17:
			cout << (char)(219);
			continue;
		case 7: case 8: case 9: case 10: case 18: case 19: case 20: case 21:
			cout << (char)(220);
			continue;
		default:
			break;
		}

		cout << ' ';
	}
	//Ket thuc tao chu PONG

	//Bat dau ve khung
	cout << endl;

	for (int i = 0; i < width - 1; ++i) {
		cout << (char)(220);
	}

	for (int i = 0; i < height - 1; ++i) {
		cout << "\n" << (char)(219);

		for (int i = 0; i < width - 3; ++i)
			cout << ' ';

		cout << (char)(219);
	}

	cout << endl;

	cout << (char)(219);

	for (int i = 0; i < width - 3; ++i) {
		cout << (char)(220);
	}

	cout << (char)(219);

	SetConsoleTextAttribute(h, 12);

	cout << endl;

	cout << (char)(201);

	for (int i = 1; i < width - 2; ++i) {
		cout << (char)(205);
	}

	cout << (char)(187) << endl;
	SetConsoleTextAttribute(h, 15);
	cout << "       Your score: 0\t\tComputer score: 0" << endl;

	SetConsoleTextAttribute(h, 12);

	cout << (char)(200);

	for (int i = 1; i < width - 2; ++i) {
		cout << (char)(205);
	}

	cout << (char)(188);
	//Ket thuc ve khung
}