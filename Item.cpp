#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

Item::Item(int x, int y) {
	_x = x;
	_y = y;
	_ox = _x;
	_oy = _y;
	_vx = _vy = 0;
}

// Input: h(con tro su dung voi man hinh console)
// Output: Qua bong
// Chuc nang: Ve qua bong
void Item::Draw(HANDLE& h) {
	SetConsoleTextAttribute(h, 15);
	COORD c;
	//Vi tri cu
	c.X = int(_ox);
	c.Y = int(_oy);

	SetConsoleCursorPosition(h, c);
	//Xoa vi tri cu
	cout << ' ';
	//Vi tri moi
	c.X = int(_x);
	c.Y = int(_y);

	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 6);
	//Ve vi tri moi
	cout << (char)(234);

	SetConsoleTextAttribute(h, 15);
	//Gan toa do vi tri moi vao _ox _oy de xu ly tiep khi bong di chuyen
	_ox = _x;
	_oy = _y;
}