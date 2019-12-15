#include "Player.h"
#include <fstream>


bool Player::move()
{
	bool isMove = false;//khoi tao trang thai di chuyen la false

	//xu li nhan phim di chuyen
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
<<<<<<< Updated upstream

=======
			PlaySound(L"getItem.wav", NULL, SND_FILENAME || SND_ASYNC);
>>>>>>> Stashed changes
			item[i].deleteItem(h);//Xoa item tren man hinh
			item[i].setIsMove(false);//dat trang thai di chuyen cua item ve false
			//tang diem theo item nhan duoc
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
			//Loai bo truong hop diem am
			score = score > 0 ? score : 0;
		}
	}
}

void Player::saveAchievement()
{
	fstream f;
	f.open("achievement.txt", ios::app);//mo file

	if (f.is_open())
	{
		//ghi level va diem vao file
		f << endl << level << endl << score;
		f.close();//dong file
	}

}

void Player::showAchievemert(HANDLE h)
{
	fstream f;
	f.open("achievement.txt", ios::in);//mo file

	if (f.is_open())
	{
		SetConsoleTextAttribute(h, 9);//dat gia tri cho mau sac chu
		int i = 6;//tao khoang cach in moi dong trong bang thanh tich
		string lineScore, lineLevel;
		gotoXY(WIDTH_BODER + 5, HEIGHT_BODER / 4 + 2, h);

		cout << "ACHIEVEMENT TABLE";

		SetConsoleTextAttribute(h, 10);//dat gia tri cho mau sac chu
		gotoXY(WIDTH_BODER + 6, HEIGHT_BODER / 4 + 4, h);

		cout << "LEVEL     SCORE";

		while (!f.eof())
		{
			gotoXY(WIDTH_BODER + 8, HEIGHT_BODER / 4 + i, h);

			do {
				getline(f, lineLevel);//doc level tu file
			} while (lineLevel.empty() && !f.eof());
			
			getline(f, lineScore);//doc diem tu file
			//xuat ra man hinh level va diem
			cout << lineLevel << "        ";
			cout << lineScore;
			i++;

		}
		f.close();
	}
	else
	{
		//neu khong doc duoc file thi hien thi thong bao loi
		gotoXY(WIDTH_BODER + 8, HEIGHT_BODER / 4 + 6, h);
		cout << "Loi trong qua trinh mo file\n";
	}
}