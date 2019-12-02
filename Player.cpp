#include "Player.h"



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
	else if (_x> (WIDTH_BODER - Size() - 2)) {
		SetX(WIDTH_BODER - Size() - 2);
	}
	return isMove ;
}

Player::Player()
{
}


Player::~Player()
{
}

Player::Player(int x, int y, int size) {
	_x =x;
	_y = y;
	_size = size;
	_ox = x;
	_oy = y;
}

// Input: h(con tro su dung voi man hinh console)
// Output: Thanh choi
// Chuc nang: Ve thanh choi
void Player::Draw(HANDLE& h) {
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
	//SetConsoleTextAttribute(h, 10);
	//Ve vi tri moi khi di chuyen
	for (int i = -_size; i < _size; ++i) {
		cout <<(char)(254);
	}

	SetConsoleTextAttribute(h, 15);
	//Gan toa do vi tri moi vao _ox _oy de xu ly tiep khi di chuyen
	_ox = _x;
	_oy = _y;
}