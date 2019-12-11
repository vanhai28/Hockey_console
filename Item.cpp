#include "Item.h"
#include <string>
#include<ctime>

void Item::resetCatoryRandom()
{
	int temp = randomRange(0, 100);

	if (temp > 0 && temp <= 30) {
		cat = 2;
	}
	else if (temp > 30 && temp <= 60)
	{
		cat = 3;
	}
	else if (temp > 60 && temp < 80)
	{
		cat = 0;
	}
	else {
		cat = 1;
	}
}

Item::Item()
{

	cat = rand() % 4;
	is_move = false;
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
void Item::Draw(HANDLE& h)
{

	if (!is_move || _y < 6) return;
	SetConsoleTextAttribute(h, 15);
	deleteItem(h);
	COORD c;

	//Vi tri moi
	c.X = int(_x);
	c.Y = int(_y);

	//ve mau
	SetConsoleCursorPosition(h, c);

	//random mau cho item
	int j;
	srand((int)time(0));
	j = rand() % (16);
	SetConsoleTextAttribute(h, 1 + j);
	
	//Ve vi tri moi
	cout << catory[cat];

	SetConsoleTextAttribute(h, 15);
	//Gan toa do vi tri moi vao _ox _oy de xu ly tiep khi bong di chuyen
	_ox = _x;
	_oy = _y;
}

void Item::move()
{
	if (is_move)
	{
		_y++;
	}
}

void Item::deleteItem(HANDLE& h)
{
	COORD c;
	//Vi tri cu
	c.X = int(_ox);
	c.Y = int(_oy);

	SetConsoleCursorPosition(h, c);
	//Xoa vi tri cu
	cout << "     ";

}