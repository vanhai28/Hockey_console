#include "Player.h"
#include <fstream>


bool Player::move()
{
	bool isMove = false;
	if (GetAsyncKeyState(VK_LEFT)) {
		SetX(_x - 2);
		isMove = true;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		SetX(_x + 2);
		isMove = true;
	}

	//Tao ranh gioi cho nguoi choi
	if (_x < Size() + 1) {
		SetX(Size() + 1);
	}
	else if (_x > (WIDTH_BODER - Size() - 2)) {
		SetX(WIDTH_BODER - Size() - 2);
	}
	return isMove;
}

Player::Player()
{
	score = 0;
	level = 1;
}


Player::~Player()
{
}

Player::Player(int x, int y, int size) {
	_x = x;
	_y = y;
	_size = size;
	_ox = x;
	_oy = y;
	score = 0;
	level = 0;
}

// Input: h(con tro su dung voi man hinh console)
// Output: Thanh choi
// Chuc nang: Ve thanh choi
void Player::Draw(HANDLE& h)
{
	SetConsoleTextAttribute(h, 9);
	COORD c;
	//Vi tri cu
	c.X = int(_ox) - _size;
	c.Y = int(_oy);

	SetConsoleCursorPosition(h, c);
	//Xoa vi tri cu khi di chuyen
	for (int i = -_size; i < _size; ++i) {
		cout << ' ';
	}
	//Vi tri moi
	c.X = int(_x) - _size;
	c.Y = int(_y);

	SetConsoleCursorPosition(h, c);

	//Ve vi tri moi khi di chuyen
	for (int i = -_size; i < _size; ++i) {
		cout << (char)(254);
	}

	SetConsoleTextAttribute(h, 15);
	//Gan toa do vi tri moi vao _ox _oy de xu ly tiep khi di chuyen
	_ox = _x;
	_oy = _y;
}

void Player::getItem(Item item[], int numItem, HANDLE&h)
{
	for (int i = 0; i < numItem; i++)
	{
		if (item[i].Y() >= _y - 1 && item[i].Y() <= _y && item[i].X() >= _x - _size && item[i].X() < _x + _size) {

			item[i].deleteItem(h);
			/*HANDLE h;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			Draw(h);*/
			item[i].setIsMove(false);

			switch (item[i].getCatory())
			{
			case 0:
				score *= 2;
				break;
			case 1:
				score /= 2;
				break;
			case 2:
				score += 10;
				break;
			case 3:
				score -= 10;
				break;
			}

			score = score > 0 ? score : 0;
		}
	}
}

void Player::saveAchievement()
{
	fstream f;
	f.open("achievement.txt", ios::app);

	if (f.is_open())
	{
		f << endl << level << endl << score;
		f.close();
	}

}

void Player::showAchievemert(HANDLE h)
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

			getline(f, lineLevel);
			getline(f, lineScore);

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