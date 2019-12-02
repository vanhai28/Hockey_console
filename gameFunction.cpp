#include "gameFunction.h"
#include <string>
#include <fstream>
#include <conio.h>


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


	COORD pos;

	pos.X = WIDTH_BODER / 2 - 10;
	pos.Y = (HEIGHT_BODER + 5) / 2 + 3;

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

	ResetGame(you, b, started, yourScore, h);

	//COORD c;

	//c.X = 0;
	//c.Y = HEIGHT_BODER + 5;
	////dua con tro ve vi tri (0, HEIGHT_BODER)
	//SetConsoleCursorPosition(h, c);
	//SetConsoleTextAttribute(h, 15);

	//cout << "\n\n       Your score: " << yourScore << "\t\tComputer score: " << computerScore << endl;
}
void ResetGame(Player& you, Ball& b, bool& started, int& yourScore, HANDLE& h)
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

	yourScore = 0;
}

void DrawBorder(HANDLE &h)
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

void gotoXY(int x, int y, HANDLE& h)
{
	COORD c;

	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(h, c);
}

void setListBox(vector<Box>& list, const int & level)
{
	int heightOfList = 6;
	int sizeList = list.size();
	Box temp;
	int widthBox = temp.Width();
	int heightBox = temp.Height();

	if (sizeList == 0)
	{

		int numBox = 0;
		for (int i = 0; i < heightOfList; i++)
		{
			numBox += (WIDTH_BODER - 2 * (i + 2)) / widthBox;
		}

		for (int i = 0; i < numBox + heightBox; i++)
		{
			list.push_back(Box());
		}
	}

	int index = 0;
	int dum = 0;
	for (int i = TOP_BODER + 1; i < TOP_BODER + heightOfList; i += heightBox)
	{
		for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
		{
			list[index].setScore(rand() % 10 + level * 5);
			list[index].setColor(rand() % 4);
			list[index].setX(j);
			list[index].setY(i);
			index++;
		}
		dum += 2;
	}

	while ((int)list.size() > index)
	{
		list.pop_back();
	}
}

void displayListBox(vector<Box>& list)
{
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		list[i].displayBox();
	}
}

bool checkBallCollideBox(Ball & ball, vector<Box>& list, int& score)
{
	int size = list.size();
	char maxBox = 3;//Toi da bong chi cham duoc ba Box
	bool isCollide = false;
	bool flag = false;//kiem tra neu dong thoi va cham goc va giua thi uu tien va cham giua
	Box * p = NULL;

	for (int i = 0; i < size; i++)
	{
		//va cham o giua
		if (!list[i].IsBreak() && ball.Y() - 1 == list[i].Y() && ball.X() < list[i].X() + list[i].Width() && ball.X() >= list[i].X())
		{

			list[i].hideBox();
			score += list[i].Score();
			isCollide = true;
			ball.SetVY(ball.VY() * -1);
			flag = true;

		}//va cham hai ben
		else if (!list[i].IsBreak() && ball.Y() == list[i].Y() && (ball.X() == list[i].X() + list[i].Width() || ball.X() == list[i].X() - 1) && ball.VX() != 0)
		{
			list[i].hideBox();
			score += list[i].Score();
			isCollide = true;
			ball.SetVX(ball.VX()*-1);

		}
		//va cham o goc nhon
		if (!list[i].IsBreak() && ball.Y() - 1 == list[i].Y() && ((ball.X() == list[i].X() + list[i].Width() && ball.VX() < 0) || (ball.X() == list[i].X() - 1 && ball.VX() > 0)))
		{
			p = &list[i];

		}
	}

	if (!flag && p)
	{
		p->hideBox();
		score += p->Score();

		ball.SetVY(ball.VY() * -1);
		ball.SetVX(ball.VX()*-1);
	}

	return isCollide;
}

void saveAchievement(int level, int score)
{
	fstream f;
	f.open("achievement.txt", ios::app);

	if (f.is_open())
	{
		f << endl << score << "\n" << level;
		f.close();
	}

}

void showAchievemert(HANDLE h)
{
	fstream f;
	f.open("achievement.txt", ios::in);

	if (f.is_open())
	{
		SetConsoleTextAttribute(h, 9);
		int i = 6;
		string lineScore, lineLevel;
		gotoXY(WIDTH_BODER + 5, HEIGHT_BODER / 4 + 2, h);

		cout << "ACHIEVEMENT TABLE";

		SetConsoleTextAttribute(h, 10);
		gotoXY(WIDTH_BODER + 6, HEIGHT_BODER / 4 + 4, h);

		cout << "LEVEL     SCORE";

		while (!f.eof())
		{
			gotoXY(WIDTH_BODER + 8, HEIGHT_BODER / 4 + i, h);
			getline(f, lineScore);
			getline(f, lineLevel);
			cout << lineLevel << "        ";
			cout << lineScore;
			i++;
		}

		f.close();
	}
	else
	{
		gotoXY(WIDTH_BODER / 2, HEIGHT_BODER / 3, h);
		cout << "Loi trong qua trinh mo file\n";
	}
}

void loadGame(char mode, int &level)
{

	fstream f;
	string lineLevel;

	if (mode == '2')
	{
		level = 1;
		f.open("achievement.txt", ios::out);
		f.close();
		return;
	}

	f.open("achievement.txt", ios::in);

	if (f.is_open())
	{
		while (!f.eof())
		{
			getline(f, lineLevel);
		}

		f.close();
	}

	level = tryParseInt(lineLevel) + 1;
}

int tryParseInt(string line)
{
	int result;

	try
	{
		result = stoi(line);
	}
	catch (exception ex)
	{
		result = 0;
	}

	return result;
}

void stagePingpongBox(Player you, Ball ball, HANDLE h)
{

	const int MAX_LEVEL = 10;
	const int time_play = 2;
	const int seconds = 60;
	int delay = 110;
	char key;
	vector <Box> listBox;

	int level = 1;
	int yourScore = 0;
	bool started = false;
	bool isWait = false;

	clock_t start = 0, end = 0;
	double cpu_time_used = 0;
	gotoXY(0, HEIGHT_BODER + 7, h);
	SetConsoleTextAttribute(h, 15);
	std::cout << "       Your score:" << yourScore << "\t\t      Level    : " << level << endl;
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

	loadGame(key, level);

	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 5, h);
	std::cout << "                          ";
	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 7, h);
	std::cout << "                           ";

	setListBox(listBox, level);
	displayListBox(listBox);
	gotoXY(0, HEIGHT_BODER + 7, h);
	SetConsoleTextAttribute(h, 15);
	std::cout << "       Your score:" << yourScore << "\t\t      Level    : " << level << endl;

	//-------------------------------------------------------------

	while (true) {
		//PlaySound(TEXT("a.mp3"), NULL, SND_FILENAME | SND_ASYNC);
		start = clock();

		showAchievemert(h);
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

			if (checkBallCollideBox(ball, listBox, yourScore))
			{
				gotoXY(0, HEIGHT_BODER + 7, h);
				SetConsoleTextAttribute(h, 15);
				std::cout << "       Your score:" << yourScore << "    ";

			}


			//vi tri moi cua qua bong
			ball.SetX(ball.X() + ball.VX());
			ball.SetY(ball.Y() + ball.VY());

			if (ball.Y() >= HEIGHT_BODER + 5 || cpu_time_used / seconds >= time_play)
			{
				if (yourScore >= 200 + level * 50)
				{
					gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 7, h);
					SetConsoleTextAttribute(h, 10);
					std::cout << " <<<<<  LEVEL   UP >>>>>";

					saveAchievement(level, yourScore);
					level = level <= MAX_LEVEL ? level + 1 : MAX_LEVEL;

					gotoXY(0, HEIGHT_BODER + 7, h);
					SetConsoleTextAttribute(h, 15);
					std::cout << "       Your score: 0\t\t      Level    : " << level << endl;

				}

				cpu_time_used = 0;
				ResetGame(you, ball, started, yourScore, h);
				setListBox(listBox, level);
				displayListBox(listBox);

				you.Draw(h);
			}

			//Kiem tra bong cham thanh choi cua ban
			if (ball.Y() >= you.Y() - 1 && ball.Y() <= you.Y()) {

				if (ball.X() >= you.X() - you.Size() && ball.X() <= you.X() + you.Size())
				{
					ball.SetVY(ball.VY() * -1);
					int temp = ball.VX() < 0 ? -1 : 1;
					ball.SetVX(abs(ball.X() - you.X())* temp);
					ball.SetY(you.Y() - 1);
				}
			}

			if (ball.Y() <= TOP_BODER)
			{
				ball.SetVY(ball.VY()*-1);
			}

			//Kiem tra bong cham 2 bien
			if (ball.X() <= 1) {
				ball.SetVX(ball.VX() * -1);
				ball.SetX(LEFT_BODER + 1);
			}
			else if (ball.X() >= WIDTH_BODER - 3) {
				ball.SetVX(ball.VX() * -1);
				ball.SetX(WIDTH_BODER - 3);
			}

			//Ve va tao mau cho qua bong
			ball.Draw(h);

			Sleep(delay - 10 * level);

		}
		else
		{

			isWait = true;
			if (isWait) {
				gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 5, h);
				SetConsoleTextAttribute(h, 15);
				std::cout << "Press the space to start!";

				SetConsoleTextAttribute(h, 15);

				gotoXY(WIDTH_BODER / 2 - 2, HEIGHT_BODER + 4, h);

				std::cout << "You";
			}

			if (GetAsyncKeyState(VK_SPACE)) { //Khi nhan phim Space tu ban phim thi tro choi bat dau
				gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 5, h);
				std::cout << "                          ";

				gotoXY(WIDTH_BODER / 2 - 10, (HEIGHT_BODER + 5) / 2 + 3, h);
				std::cout << "                       ";

				gotoXY(WIDTH_BODER / 2 - 12, (HEIGHT_BODER + 5) / 2 + 7, h);
				std::cout << "                                ";

				gotoXY(WIDTH_BODER / 2 - 4, 6, h);
				std::cout << "        ";

				gotoXY(WIDTH_BODER / 2 - 2, HEIGHT_BODER + 4, h);
				std::cout << "   ";

				started = true;
				isWait = false;
			}
		}

		end = clock();

		if (started)
		{
			setfill('0');

			cpu_time_used += (double)(end - start) / CLOCKS_PER_SEC;
			gotoXY(60, 38, h);
			std::cout << setw(2) << (int)cpu_time_used / seconds;
			cout << " : " << setw(2) << (int)cpu_time_used % seconds;
		}
	}
}

void menu(char& key, HANDLE h)
{
	system("cls");
	SetConsoleTextAttribute(h, 10);

	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 5, h);
	std::cout << "SOLO VS COMPUTER   :    Press 1";

	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 7, h);
	std::cout << "PINGPONG BOX       :    Press 2";

	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 9, h);
	std::cout << "GUIDE              :    Press 3";

	gotoXY(WIDTH_BODER / 2 - 10, HEIGHT_BODER / 2 + 11, h);
	std::cout << "EXIT               :    Press 0";

	do
	{
		key = _getch();
	} while (key != '1' && key != '2' && key != '3' && key != '0');

}