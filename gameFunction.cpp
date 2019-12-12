
#include "gameFunction.h"
#include <string>
#include <fstream>
#include <conio.h>
#include"Item.h"
#include"time.h"
#include"File.h"
#include <random>



void Nocursortype()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void ResetResult(Player& you, Player& com, Ball& b, bool& started, int& yourScore, int& computerScore, HANDLE& h) {

	//luu diem
	savebest(you.Score());

	you.setScore(0);
	COORD pos;
	COORD pos1;

	pos.X = WIDTH_BODER / 2 - 10;
	pos.Y = (HEIGHT_BODER + 5) / 2 + 3;

	pos1.X = WIDTH_BODER / 2 - 9;
	pos1.Y = (HEIGHT_BODER + 5) / 2 + 4;

	SetConsoleTextAttribute(h, 12);

	if (yourScore == 3) {
		SetConsoleCursorPosition(h, pos);
		cout << ">>>>>> YOU WIN! <<<<<<" << endl;
		SetConsoleCursorPosition(h, pos1);
		cout << "DIEM SO CAO NHAT: " << Maxscore() << endl;

		yourScore = 0;
		computerScore = 0;
	}
	else if (computerScore == 3) {
		SetConsoleCursorPosition(h, pos);
		cout << ">>>> COMPUTER WIN <<<<" << "" << endl;
		SetConsoleCursorPosition(h, pos1);
		cout << "DIEM SO CAO NHAT:  " << Maxscore() << endl;

		yourScore = 0;
		computerScore = 0;
	}

	//Cho qua bong ve tri ban dau
	b.SetX(WIDTH_BODER / 2 - 1);
	b.SetY((HEIGHT_BODER + 8 / 2));

	//Cho vi tri cua 2 nguoi choi ve vi tri ban dau
	you.SetX(WIDTH_BODER / 2);

	started = false;

	b.SetVX(rand() % 3 - 2);
	b.SetVY(1);
	b.SetX(WIDTH_BODER / 2 - 1);
	b.SetY((HEIGHT_BODER + 8) / 2);

}
//void ResetResult(Player& you, Player& com, Ball& ball, bool& started, int& yourScore, int& computerScore, HANDLE& h) {
//
//	you.setScore(0);
//	COORD pos;
//
//	pos.X = WIDTH_BODER / 2 - 10;
//	pos.Y = (HEIGHT_BODER + 5) / 2 + 3;
//
//	SetConsoleTextAttribute(h, 12);
//
//	if (yourScore == 3) {
//		SetConsoleCursorPosition(h, pos);
//		cout << ">>>>>> YOU WIN! <<<<<<";
//		yourScore = 0;
//		computerScore = 0;
//	}
//	else if (computerScore == 3) {
//		SetConsoleCursorPosition(h, pos);
//		cout << ">>>> COMPUTER WIN <<<<";
//		yourScore = 0;
//		computerScore = 0;
//	}
//
//	ResetGame(you, ball, started, h);
//
//}

void ResetGame(Player& you, Ball& b, bool& started, HANDLE& h)
{
	//Cho qua bong ve tri ban dau
	b.SetX(WIDTH_BODER / 2 - 1);
	b.SetY((HEIGHT_BODER + 8 / 2));

	//Cho vi tri cua 2 nguoi choi ve vi tri ban dau
	you.SetX(WIDTH_BODER / 2);

	started = false;

	b.SetVX(rand() % 3 - 2);
	b.SetVY(1);
	b.SetX(WIDTH_BODER / 2 - 1);
	b.SetY((HEIGHT_BODER + 8) / 2);

	you.setScore(0);
}

void DrawBorder(HANDLE& h)
{
	system("cls");
	gotoXY(0, 0, h);
	//Ve khung
	SetConsoleTextAttribute(h, 12); //Tao mau cho khung choi
	//Tao chu PONG
	for (int i = 0; i < 24; i++)
	{
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

	for (int i = 0; i < 24; i++)
	{
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

	for (int i = 0; i < 24; i++)
	{
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

	for (int i = 0; i < 24; i++)
	{
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

	for (int i = 0; i < WIDTH_BODER + 25; ++i)
	{
		cout << (char)(220);
	}

	for (int i = 0; i < HEIGHT_BODER - 1; ++i)
	{

		cout << (char)(219);
		for (int i = 0; i < WIDTH_BODER - 3; ++i)
			cout << ' ';
		cout << (char)(219);
		cout << "\n";
	}

	cout << (char)(219);

	for (int i = 0; i < WIDTH_BODER - 3; ++i) {
		cout << (char)(220);
	}

	cout << (char)(219);

	for (int i = 0; i <= 25; ++i) {
		cout << (char)(220);
	}

	SetConsoleTextAttribute(h, 12);

	cout << (char)(201);

	for (int i = 1; i < WIDTH_BODER - 2; ++i) {
		cout << (char)(205);
	}

	cout << (char)(187) << endl;

	SetConsoleTextAttribute(h, 15);

	cout << endl;
	SetConsoleTextAttribute(h, 12);

	cout << (char)(200);

	for (int i = 1; i < WIDTH_BODER - 2; ++i) {
		cout << (char)(205);
	}

	cout << (char)(188);
	//Ket thuc ve khung
}


void loadGame(char mode, int& level)
{
	fstream f;
	string lineLevel , lineScore;

	if (mode == '1')//choi tiep
	{
		f.open("achievement.txt", ios::in);

		if (f.is_open())
		{
			while (f.is_open() && !f.eof())
			{
				do
				{
					getline(f, lineLevel);
				} while (!f.eof() && lineLevel.empty());

				getline(f, lineScore);


				f.close();
			}

			level = tryParseInt(lineLevel) + 1;
		}
		else
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			gotoXY(WIDTH_BODER + 8, HEIGHT_BODER / 4 + 6, h);
			cout << "Loi mo file!!";
		}
	}
	else
	{
		f.open("achievement.txt", ios::out);//mo va xoa het du lieu trong file
		f.close();
	}

}

	void stagePingpongBox(Player you, Ball ball, HANDLE h)
	{
		//khai bao bien hang so
		const int MAX_LEVEL = 10;//Level cao nhat
		const int time_play = 2;//thoi gian choi moi luot
		const int seconds = 60;//so giay trong 1 phut
		int delay = 110;//Dieu khien toc do bong
		char key;//phim chuc nang
		vector <Box> listBox;//Danh sach box

		bool started = false;//kiem tra trang thai bat dau
		bool isWait = false;//Kiem tra trang thai cho
		bool isLevelUp = false;//Kiem tra su len level
		bool isCollide = false;// kiem tra bong va cham hop

		clock_t start = 0, end = 0;//tinh thoi gian
		double time_used = 0;//luu khoang thoi gian

		//ve man hinh chuan bi cho man choi
		gotoXY(0, HEIGHT_BODER + 7, h);
		SetConsoleTextAttribute(h, 15);
		std::cout << "       Your score:" << you.Score() << "\t\t      Level    : " << you.getLevel() << endl;
		//Ve va tao mau cho thanh choi cua minh
		you.Draw(h);

		//---------------- Chon che do choi --------------------------
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 5, h);
		SetConsoleTextAttribute(h, 10);
		std::cout << "Choi tiep    :    nhan 1";
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 7, h);
		std::cout << "Choi lai     :    nhan 2";

		do
		{
			key = _getch();
		} while (key != '1' && key != '2');

		int tempLevel = 1;
		loadGame(key, tempLevel);//tai game tu file
		you.setLevel(tempLevel);

		//Xoa dong chu chon che do
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 5, h);
		std::cout << "                          ";
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 7, h);
		std::cout << "                           ";

		//khoi tao va hien thi day box
		Box::setListBox(listBox, you.getLevel());
		Box::displayListBox(listBox);

		you.setScore(250);
		//hien thi diem ban dau va level
		gotoXY(0, HEIGHT_BODER + 7, h);
		SetConsoleTextAttribute(h, 15);
		std::cout << "       Your score:" << you.Score() << "\t\t      Level    : " << you.getLevel() << endl;

		you.showAchievemert(h);//hien thi thanh tich

		//bat dau vong lap game
		while (true) {


			start = clock();//tin thoi gian

			if (GetAsyncKeyState(VK_ESCAPE)) {
				break;//ket thuc tro choi
			}

			if (started)
			{
				if (you.move())
				{
					//Ve va tao mau cho thanh choi cua minh
					SetConsoleTextAttribute(h, 9);
					you.Draw(h);
				}
				//Kiem tra bong va cham vao box
				int tempScore = you.Score();
				isCollide = ball.checkBallCollideBox(listBox, tempScore);
				you.setScore(tempScore);

				if (isCollide)
				{
					gotoXY(0, HEIGHT_BODER + 7, h);
					SetConsoleTextAttribute(h, 15);
					std::cout << "       Your score:" << you.Score() << "    ";
				}

				//vi tri moi cua qua bong
				ball.SetX(ball.X() + ball.VX());
				ball.SetY(ball.Y() + ball.VY());

				//Kiem tra ket thuc luot choi
				//Neu bong cham day hoac het thoi gian
				if (ball.Y() >= HEIGHT_BODER + 5 || time_used / seconds >= time_play)
				{
					//Kiem tra diem co du qua man khong
					if (you.Score() >= 200 + you.getLevel() * 50)
					{
						isLevelUp = true;

						//hien thi diem
						gotoXY(0, HEIGHT_BODER + 7, h);
						SetConsoleTextAttribute(h, 15);
						std::cout << "       Your score: 0    \t      Level    : " << you.getLevel() << endl;

						you.saveAchievement();//Luu thanh tich
						you.showAchievemert(h);//hien thi thanh tich

						tempLevel = you.getLevel() <= MAX_LEVEL ? you.getLevel() + 1 : MAX_LEVEL;//Tang level
						you.setLevel(tempLevel);
					}
					//Reset lai cac gia tri
					time_used = 0;
					ResetGame(you, ball, started, h);
					Box::setListBox(listBox, you.getLevel());
					Box::displayListBox(listBox);

					you.Draw(h);
				}

				//Kiem tra bong cham thanh choi cua ban
				if (ball.Y() >= you.Y() - 1 && ball.Y() <= you.Y() && ball.X() > you.X() - you.Size() && ball.X() < you.X() + you.Size())
				{
					ball.SetVY(ball.VY() * -1);
					int temp = ball.VX() < 0 ? -1 : 1;

					ball.SetVX(abs(ball.X() - you.X()) / 2 * temp);//dieu chinh huong bong
					ball.SetY(you.Y() - 1);
				}

				if ((ball.X() == you.X() - you.Size() && ball.VX() > 0) || (ball.X() == you.X() + you.Size() && ball.VX() < 0))
				{
					//bong cham goc nhon thi bat nguoc lai
					if (ball.Y() == you.Y() - 1)
					{
						ball.SetVY(ball.VY() * -1);
						ball.SetVX(ball.VX()*-1);
					}
					else if (ball.Y() == you.Y())//bong cham hai ben thanh
					{
						ball.SetVX(ball.VX()*-1);
					}
				}

				//Kiem tra bong cham bien
				if (ball.X() <= 1) {//bong cham bien trai
					ball.SetVX(ball.VX() * -1);
					ball.SetX(LEFT_BODER + 1);
				}
				else if (ball.X() >= WIDTH_BODER - 3) {//bong cham bien phai
					ball.SetVX(ball.VX() * -1);
					ball.SetX(WIDTH_BODER - 3);
				}
				else if (ball.Y() <= TOP_BODER)//bong cham bien tren
				{
					ball.SetVY(ball.VY()*-1);
				}

				//Ve va tao mau cho qua bong
				ball.Draw(h);

				Sleep(delay - 10 * you.getLevel());//dieu chinh toc do bong

			}
			else
			{
				SetConsoleTextAttribute(h, 15);

				//tam dung man choi
				isWait = true;
				if (isWait)
				{
					gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 5, h);
					std::cout << "Press the space to start!";

					gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 3, h);
					cout << "Diem chuan level " << you.getLevel() << " la " << 200 + you.getLevel() * 50;

					gotoXY(WIDTH_BODER / 2 - 2, HEIGHT_BODER + 4, h);
					std::cout << "You";
				}

				//------------Tao hieu ung dong cho chu level up-----------------
				int temp = 9, color = 0;
				while (isWait && isLevelUp)
				{
					SetConsoleTextAttribute(h, 10 + color);
					for (int i = 0; i < temp; i++)
					{
						if (GetAsyncKeyState(VK_SPACE))
						{
							SetConsoleTextAttribute(h, 10);
							isWait = false;
							isLevelUp = false;
							break;
						}
						gotoXY(WIDTH_BODER / 2 - 7 - i, (HEIGHT_BODER + 5) / 2 + 7, h);
						cout << "<";
						gotoXY(WIDTH_BODER / 2 - 4, (HEIGHT_BODER + 5) / 2 + 7, h);
						cout << "LEVEL   UP";
						gotoXY(WIDTH_BODER / 2 + 7 + i, (HEIGHT_BODER + 5) / 2 + 7, h);
						cout << ">";
						Sleep(60);
					}
					color++;
					color %= temp;
				}
				//-----------------------Ket thuc tao hieu ung ----------------------------

				if (GetAsyncKeyState(VK_SPACE)) { //Khi nhan phim Space tu ban phim thi tro choi bat dau
					//Xoa cac dong chu hien thi trong khi dung game

					gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 5, h);
					std::cout << "                          ";

					if (GetAsyncKeyState(VK_SPACE) || !isWait) { //Khi nhan phim Space tu ban phim thi tro choi bat dau
						//Xoa cac dong chu hien thi trong khi dung game


						gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 5, h);
						std::cout << "                          ";//xoa dong chu Press the space to start!

						gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 3, h);
						std::cout << "                            ";//xoa dong chu Diem chuan level 

						gotoXY(WIDTH_BODER / 2 - 16, (HEIGHT_BODER + 5) / 2 + 7, h);
						std::cout << "                                ";//xoa dong chu level up

						gotoXY(WIDTH_BODER / 2 - 2, HEIGHT_BODER + 4, h);
						std::cout << "   ";// xoa chu you

						gotoXY(60, 38, h);
						std::cout << "           ";//Xoa hien thi thoi gian cu


						started = true;//thiet lap trang thai bat dau choi
						isWait = false;//bo che do cho
					}
				}
			}
			end = clock();

			if (started)
			{
				//Hien thi dong ho dem thoi gian 
				setfill('0');
				time_used += (double)(end - start) / CLOCKS_PER_SEC;
				gotoXY(60, 38, h);
				std::cout << setw(2) << (int)time_used / seconds;
				cout << " : " << setw(2) << (int)time_used % seconds;
			}

		}
	}

	void playPingpong(Player you, Player computer)
	{
		//khoi tao cac bien
		int maxSpeed = 4;
		int delay = 150;
		const double second = 5.000;
		const int numItem = 2;
		const double timeDisplayItem = 2;
		HANDLE h;
		h = GetStdHandle(STD_OUTPUT_HANDLE);
		DrawBorder(h);

		clock_t start = 0;
		clock_t end = 0;
		bool started = false;
		bool isWait = false;
		int yourScore = 0;
		int computerScore = 0;
		double duration = 0;
		char key;
		int index = 0;


		srand((int)time(0));
		//Khoi tao
		Ball ball(WIDTH_BODER / 2 - 1, (HEIGHT_BODER + 8) / 2);
		Item listItem[numItem];

		//Tao van toc ban dau cho qua bong. Bong se luon huong ve phia ban truoc.
		ball.SetVX(1);
		ball.SetVY(1);

		//---------------- Chon che do choi --------------------------
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 5, h);
		SetConsoleTextAttribute(h, 10);
		std::cout << "Choi tiep    :    nhan 1";
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 7, h);
		std::cout << "Load game     :    nhan 2";
		do
		{
			key = _getch();
		} while (key != '1' && key != '2');

		LoadFile(key, yourScore, computerScore);

		//ve chu thich len man hinh
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 5, h);
		std::cout << "                          ";
		gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 7, h);
		std::cout << "                           ";

		gotoXY(55, 9, h);
		SetConsoleTextAttribute(h, 13);
		std::cout << "       SCORE" << endl;

		gotoXY(55, 19, h);
		SetConsoleTextAttribute(h, 13);
		std::cout << "Phim enter de luu game" << endl;

		gotoXY(55, 22, h);
		SetConsoleTextAttribute(h, 13);
		std::cout << "Phim ese de thoat" << endl;

		computer.SetVX(0);

		//bo dem thoi gian
		start = clock();

		//bat dau vong chay
		while (true) {

			//phim ? de tro lai nemu
			if (GetAsyncKeyState(VK_ESCAPE)) {
				break;
			}
			//luu vao file
			if (GetAsyncKeyState(VK_RETURN))
			{
				SaveToFile(yourScore, computerScore);

			}

			//ve diem lên man hình
			gotoXY(55, 13, h);
			SetConsoleTextAttribute(h, 15);
			std::cout << "Your :" << yourScore << " - " << computerScore << ": Computer";

			gotoXY(55, 15, h);
			std::cout << "  score:" << you.Score() << endl;

			if (started) {

				//Khi nhan phim mui ten trai hoac phai thi nguoi choi se di chuyen sang trai hoac phai
				if (GetAsyncKeyState(VK_LEFT)) {
					you.SetX(you.X() - 2);
				}
				else if (GetAsyncKeyState(VK_RIGHT)) {
					you.SetX(you.X() + 2);
				}

				//Cho may chay theo bong
				computer.SetVX(computer.VX() - int(computer.X() - ball.X()) / 10);
				computer.SetVX(computer.VX() * 1);
				computer.SetX(ball.X());

				//Tao ranh gioi cho nguoi choi
				if (you.X() < you.Size() + 1) {
					you.SetX(you.Size() + 1);
				}
				else if (you.X() > (WIDTH_BODER - you.Size() - 2)) {
					you.SetX(WIDTH_BODER - you.Size() - 2);
				}
				//Tao ranh gioi cho may
				if (computer.X() < computer.Size() + 1) {
					computer.SetX(you.Size() + 1);
				}
				else if (computer.X() > (WIDTH_BODER - computer.Size() - 2)) {
					computer.SetX(WIDTH_BODER - computer.Size() - 2);
				}

				//Gioi han toc do cua qua bong
				if (ball.VX() < -maxSpeed) {
					ball.SetVX(-maxSpeed);
				}
				else if (ball.VX() > maxSpeed) {
					ball.SetVX(maxSpeed);
				}

				you.getItem(listItem, numItem, h);


				//vi tri moi cua qua bong
				ball.SetX(ball.X() + ball.VX());
				ball.SetY(ball.Y() + ball.VY());


				// Kiem tra bong cham thanh choi cua may
				if (ball.Y() <= computer.Y() + 1 && ball.Y() >= computer.Y()) {

					if (ball.X() > computer.X() - computer.Size() && ball.X() < computer.X() + computer.Size()) {
						ball.SetVY(ball.VY() * -1);
						ball.SetVX(ball.VX() + (ball.X() - computer.X()) / 3);
						ball.SetY(computer.Y() + 1);
						delay = delay - 5;
					}
				}

				//Kiem tra bong cham thanh choi cua ban
				if (ball.Y() >= you.Y() - 1 && ball.Y() <= you.Y()) {

					if (ball.X() > you.X() - you.Size() && ball.X() < you.X() + you.Size()) {
						ball.SetVY(ball.VY() * -1);
						ball.SetVX(ball.VX() + (ball.X() - you.X()) / 3);
						ball.SetY(you.Y() - 1);
						delay = delay - 5;
					}
				}

				// Kiem tra ban thang hoac may thang
				if (ball.Y() >= HEIGHT_BODER + 5) {
					++computerScore;
					ResetResult(you, computer, ball, started, yourScore, computerScore, h);
					gotoXY(55, 13, h);
					std::cout << "    score: " << you.Score() << endl;
				}
				else if (ball.Y() <= 5) {
					++yourScore;
					ResetResult(you, computer, ball, started, yourScore, computerScore, h);
					gotoXY(55, 13, h);
					std::cout << "    score: " << you.Score() << endl;
				}
				//Kiem tra bong cham 2 bien
				if (ball.X() <= 1) {
					ball.SetVX(ball.VX() * -1);
					ball.SetX(1);
				}
				else if (ball.X() >= WIDTH_BODER - 3) {
					ball.SetVX(ball.VX() * -1);
					ball.SetX(WIDTH_BODER - 3);
				}
			}
			else
			{
				COORD c;

				if (!isWait) {
					c.X = WIDTH_BODER / 2 - 12;
					c.Y = (HEIGHT_BODER + 5) / 2 + 5;
					//Di chuyen con tro toi vi tri (c.X, c.Y)
					SetConsoleCursorPosition(h, c);

					//hien chu len man hinh
					SetConsoleTextAttribute(h, 15);
					cout << "Press the space to start!";
					SetConsoleTextAttribute(h, 15);

					c.X = WIDTH_BODER / 2 - 4;
					c.Y = 6;

					SetConsoleCursorPosition(h, c);
					cout << "Computer";

					c.X = WIDTH_BODER / 2 - 2;
					c.Y = HEIGHT_BODER + 4;

					SetConsoleCursorPosition(h, c);
					cout << "You";

					isWait = true;
				}

				//Khi nhan phim Space tu ban phim thi tro choi bat dau
				if (GetAsyncKeyState(VK_SPACE)) {

					gotoXY(WIDTH_BODER / 2 - 9, (HEIGHT_BODER + 5) / 2 + 4, h);
					SetConsoleTextAttribute(h, 12);
					cout << "                     ";
					delay = 150;

					//reset lai thoi gian item
					duration = 0;
					listItem[index].deleteItem(h);
					listItem[index].setIsMove(false);

					c.X = WIDTH_BODER / 2 - 12;
					c.Y = (HEIGHT_BODER + 5) / 2 + 5;
					SetConsoleCursorPosition(h, c);
					cout << "                          ";

					c.X = WIDTH_BODER / 2 - 10;
					c.Y = (HEIGHT_BODER + 5) / 2 + 3;
					SetConsoleCursorPosition(h, c);
					cout << "                       ";

					c.X = WIDTH_BODER / 2 - 4;
					c.Y = 6;
					SetConsoleCursorPosition(h, c);
					cout << "        ";

					c.X = WIDTH_BODER / 2 - 2;
					c.Y = HEIGHT_BODER + 4;
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
			end = clock();

			gotoXY(0, 16, h);
			SetConsoleTextAttribute(h, 12);
			cout << (char)219;

			//dem thoi gian
			duration = (double)(end - start) / CLOCKS_PER_SEC;

			//resest thoi gian ve muc 0
			if (duration > timeDisplayItem&& started)
			{
				for (int i = 0; i < numItem; i++)
				{
					if (listItem[i].getIsMove() == false)
					{
						listItem[i].setIsMove(true);
						listItem[i].resetCatoryRandom();
						listItem[i].SetX(randomRange(6, WIDTH_BODER - 14));
						listItem[i].SetY(i * 10 - 20);
					}
				}

				duration = 0;
			}

			//ve va xoa cac item 

			for (int i = 0; i < numItem - 1 && started; i++)
			{
				listItem[i].move();
				listItem[i].Draw(h);

				index = i;

				if (listItem[i].Y() >= HEIGHT_BODER + 3)
				{
					listItem[i].deleteItem(h);
					listItem[i].setIsMove(false);

				}
			}
		}

	}


	//lua chon cho menu
	void showMenu(char& key, HANDLE h)
	{
		system("cls");
		SetConsoleTextAttribute(h, 10);

		//vẽ chữ MENU
		gotoXY(WIDTH_BODER / 2 + 2, HEIGHT_BODER / 2 - 2, h);
		cout << (char)219 << (char)223 << (char)220 << (char)223 << (char)219 << " " << (char)219 << (char)223
			<< (char)223 << " " << (char)219 << (char)223 << (char)219 << " " << (char)219 << " " << (char)219 << "  " << (char)219;;
		gotoXY(WIDTH_BODER / 2 + 2, HEIGHT_BODER / 2 - 1, h);
		cout << (char)219 << "   " << (char)219 << " " << (char)219 << (char)196 << (char)196 << " " << (char)219
			<< " " << (char)219 << " " << (char)219 << " " << (char)219 << "  " << (char)219;;
		gotoXY(WIDTH_BODER / 2 + 2, HEIGHT_BODER / 2, h);
		cout << (char)219 << "   " << (char)219 << " " << (char)219 << (char)220 << (char)220 << " " << (char)219
			<< " " << (char)219 << (char)220 << (char)219 << " " << (char)219 << (char)220 << (char)220 << (char)219;

		//các chức năng của game
		gotoXY(WIDTH_BODER / 2 - 5, HEIGHT_BODER / 2 + 4, h);
		std::cout << "SOLO VS COMPUTER   :    Press 1";

		gotoXY(WIDTH_BODER / 2 - 5, HEIGHT_BODER / 2 + 8, h);
		std::cout << "PINGPONG BOX       :    Press 2";

		gotoXY(WIDTH_BODER / 2 - 5, HEIGHT_BODER / 2 + 12, h);
		std::cout << "GUIDE              :    Press 3";

		gotoXY(WIDTH_BODER / 2 - 5, HEIGHT_BODER / 2 + 16, h);
		std::cout << "EXIT               :    Press 0";

		do
		{
			key = _getch();
		} while (key != '1' && key != '2' && key != '3' && key != '0');

	}

	void ReadGuide(char& key, HANDLE& h)
	{
		system("cls");
		gotoXY(0, 0, h);
		//Ve khung
		SetConsoleTextAttribute(h, 12); //Tao mau cho khung choi
		//Tao chu PONG

		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{

			cout << (char)(220);

			switch (i) {
			case 25: case 26: case 32: case 38: case 45: case 51: case 57:
				cout << ' ';
				break;

			}

		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 24: case 25: case 26: case 30: case 31: case 38:
			case 42: case 43: case 47: case 48: case 52: case 53:
				cout << (char)(219);
				break;
			default:
				break;
			}

			cout << ' ';
		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 25:
			case 39: case 44:
				cout << (char)(219);
				continue;
			case 21: case 22: case 23: case 24: case 35: case 36:
			case 40: case 41: case 42: case 43: case 58: case 59:
				cout << (char)(220);
				continue;
			case 27: case 28: case 32: case 33:
			case 46: case 50: case 51: case 55: case 56:
				cout << (char)(219);
				break;
			case 37:
			case 60:
				cout << (char)(220);
				break;
			default:
				break;
			}

			cout << ' ';
		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 26: case 27: case 31: case 32: case 36:
			case 38: case 44: case 49: case 48: case 53: case 54: case 58:
				cout << (char)(219);
				break;
			default:
				break;
			}

			cout << ' ';
		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}

		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 26: case 27: case 31: case 37:
			case 39: case 50: case 51: case 55: case 61:
				cout << (char)(219);
				break;
			case 32:
			case 45:
				cout << (char)(219);
				continue;
			case 56:
				cout << (char)(219);
				continue;
			case 33: case 34: case 35: case 36:
			case 46: case 47: case 48: case 49: case 57: case 58: case 59: case 60:
				cout << (char)(220);
				continue;
			default:
				break;
			}

			cout << ' ';
		}

		//Ket thuc tao chu PONG
		gotoXY(20, 10, h);
		cout << (char)219;
		for (int i = 1; i < 36; i++)
		{
			cout << (char)219;
		}
		gotoXY(20, 39, h);
		cout << (char)219;
		for (int i = 1; i < 36; i++)
		{
			cout << (char)219;
		}
		cout << (char)219;
		for (int i = 10; i < 40; i++)

			//ket thuc tao ch oing pong

			//hien thi hung dan len console
			while (1)

			{
				//chon ese de tro lai menu
				if (GetAsyncKeyState(VK_ESCAPE)) {
					break;//ket thuc tro choi
				}
				fstream fileguide;
				fileguide.open("Guide.txt", ios::in);

				//kiem tra file
				if (fileguide.fail())
				{
					cout << "khong mo duoc file!" << endl;
					return;
				}

				//moi file de doc va luu vao token
				string token = " ";
				string line;
				while (!fileguide.eof())
				{
					getline(fileguide, line);
					token += "\n";
					token += line;
				}

				fileguide.close();

				//hien thi token ra man hin console
				gotoXY(11, 8, h);
				SetConsoleTextAttribute(h, 10);
				cout << token;


			}

		showMenu(key, h);
	}

	//ve menu game
	void DrawMenu(char& key, HANDLE& h)
	{
		system("cls");
		gotoXY(0, 0, h);
		//Ve khung
		SetConsoleTextAttribute(h, 12); //Tao mau cho khung choi
		//Tao chu PING PONG
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{

			cout << (char)(220);

			switch (i) {
			case 25: case 26: case 32: case 38: case 45: case 51: case 57:
				cout << ' ';
				break;

			}

		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 24: case 25: case 26: case 30: case 31: case 38:
			case 42: case 43: case 47: case 48: case 52: case 53:
				cout << (char)(219);
				break;
			default:
				break;
			}

			cout << ' ';
		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 25:
			case 39: case 44:
				cout << (char)(219);
				continue;
			case 21: case 22: case 23: case 24: case 35: case 36:
			case 40: case 41: case 42: case 43: case 58: case 59:
				cout << (char)(220);
				continue;
			case 27: case 28: case 32: case 33:
			case 46: case 50: case 51: case 55: case 56:
				cout << (char)(219);
				break;
			case 37:
			case 60:
				cout << (char)(220);
				break;
			default:
				break;
			}

			cout << ' ';
		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}
		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 26: case 27: case 31: case 32: case 36:
			case 38: case 44: case 49: case 48: case 53: case 54: case 58:
				cout << (char)(219);
				break;
			default:
				break;
			}

			cout << ' ';
		}

		cout << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << ' ';
		}

		for (int i = 20; i < 64; i++)
		{
			switch (i) {
			case 20: case 26: case 27: case 31: case 37:
			case 39: case 50: case 51: case 55: case 61:
				cout << (char)(219);
				break;
			case 32:
			case 45:
				cout << (char)(219);
				continue;
			case 56:
				cout << (char)(219);
				continue;
			case 33: case 34: case 35: case 36:
			case 46: case 47: case 48: case 49: case 57: case 58: case 59: case 60:
				cout << (char)(220);
				continue;
			default:
				break;
			}

			cout << ' ';
		}
		//Ket thuc tao chu PHING PONG

		//bat dau ve khung cho me nu
		gotoXY(20, 10, h);
		cout << (char)219;
		for (int i = 1; i < 36; i++)
		{
			cout << (char)219;
		}
		gotoXY(20, 39, h);
		cout << (char)219;
		for (int i = 1; i < 36; i++)
		{
			cout << (char)219;
		}
		cout << (char)219;
		for (int i = 10; i < 40; i++)
		{
			gotoXY(20, i, h);
			cout << (char)219;
			gotoXY(56, i, h);
			cout << (char)219;
		}
		//hien thi cac lua chon cho menu
		showMenu(key, h);

	}

