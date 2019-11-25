#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

Player::Player(int x, int y, int size) {
	_x = float(x);
	_y = float(y);
	_size = size;
	_ox = float(x);
	_oy = float(y);
}

// Input: h(con tro su dung voi man hinh console)
// Output: Thanh choi
// Chuc nang: Ve thanh choi
void Player::Draw(HANDLE& h) {
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