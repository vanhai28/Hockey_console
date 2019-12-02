#include "gameFunction.h"
#include <string>
#include <fstream>
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
	//Cho qua bong ve tri ban dau
 	b.SetX(WIDTH_BODER / 2 - 1);
	b.SetY((HEIGHT_BODER + 8 / 2));

	//Cho vi tri cua 2 nguoi choi ve vi tri ban dau
	you.SetX(WIDTH_BODER / 2);
	com.SetX(WIDTH_BODER / 2);
	com.SetVX(0);

	started = false;

	b.SetVX(rand() % 3 - 2);
	b.SetVY(1);
	b.SetX(WIDTH_BODER / 2 - 1);
	b.SetY((HEIGHT_BODER + 8) / 2);

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

	COORD c;

	c.X = 0;
	c.Y = HEIGHT_BODER + 5;
	//dua con tro ve vi tri (0, HEIGHT_BODER)
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 15);
	
	//cout << "\n\n       Your score: " << yourScore << "\t\tComputer score: " << computerScore << endl;
}


void DrawBorder(HANDLE &h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console,150, 0, 680, 750, true);
	Nocursortype();
	//An con tro console
	CONSOLE_CURSOR_INFO cci;

	cci.dwSize = 5;
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

	for (int i = 0; i < WIDTH_BODER +25; ++i) {
		cout << (char)(220);
	}

	for (int i = 0; i < HEIGHT_BODER-1 ; ++i) {
		
		cout << (char)(219);
		for (int i = 0; i < WIDTH_BODER - 3; ++i)
			cout << ' ';	
		cout << (char)(219);
		cout << "\n";
	}

	cout << (char)(219);
	
	
	
	for (int i = 0; i < WIDTH_BODER -3 ; ++i) {
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
	//cout << "       Your score: 0\t\tComputer score: 0" << endl;
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
	for (int i = TOP_BODER +1 ; i < TOP_BODER + heightOfList; i += heightBox)
	{
		for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
		{
			list[index].setScore(rand() % 10 + level*5);
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

	for (int i = 0; i < size ; i++)
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
		f << endl << level <<  "\n" << score;
		f.close();
	}

}

void showAchievemert(HANDLE h)
{
	fstream f;
	f.open("achievement.txt", ios::in);
	
	if (f.is_open())
	{
		SetConsoleTextAttribute(h, 10);
		int i = 3;
		string line;
		gotoXY(WIDTH_BODER + 5, HEIGHT_BODER / 4 + 2, h);
		getline(f, line);
		cout << line;

		while (!f.eof())
		{
			gotoXY(WIDTH_BODER +5, HEIGHT_BODER / 4+i, h);
			getline(f, line);
			cout << line<<"       ";
			getline(f, line);
			cout << line;
			i++;
		}
		
		f.close();
	}
	else
	{
		gotoXY(WIDTH_BODER / 2, HEIGHT_BODER / 3 , h);
		cout << "Loi trong qua trinh mo file\n";
	}
}
	
void loadGame(int &level)
{

	fstream f;
	f.open("achievement.txt", ios::in);
	string lineLevel,lineScore; 

	if (f.is_open())
	{
		getline(f, lineLevel);
		while (!f.eof())
		{
			getline(f, lineLevel);
			getline(f, lineScore);
		}
	}

	if (!f.is_open() || lineLevel.empty() || lineScore.empty())
	{
		level = 0;
	}
	else {
		level = tryParseInt(lineLevel);
	}

}

int tryParseInt(string line)
{
	int result;

	try
	{
		result  = stoi(line);
	}
	catch (exception ex)
	{
		result = 0;
	}
	 
	return result;
}
